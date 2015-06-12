#include "../headers/edittache.h"
EditTache::EditTache(Tache *t, QWidget *parent):Editeur(parent),tacheEdit(t)
{
    _titre = new QLineEdit(this);
    _dateDispo = new QDateEdit(this);
    _dateEcheance = new QDateEdit(this);
    _type = new QLabel("default",this);
    _precedences_l = new QLabel("Précédences : ",this);
    _possibles_l = new QLabel("Précédences possibles : ",this);
    _precedences = new QListWidget(this);
    _possibles = new QListWidget(this);
    _ajouterPrec = new QPushButton("<- Ajouter ",this);
    _retirerPrec = new QPushButton("Retirer ->",this);
    _duree = new QTimeEdit(this);

    _formLayout = new QFormLayout;
    _formLayout->addRow("Titre : ",_titre);
    _formLayout->addRow("Date Dispo : ",_dateDispo);
    _formLayout->addRow("Date Echéance : ",_dateEcheance);
    _formLayout->addRow("Durée de la tâche : ",_duree);
    _formLayout->addRow("Type : ",_type);

    _precListLayout = new QVBoxLayout;
    _precListLayout->addWidget(_precedences_l);
    _precListLayout->addWidget(_precedences);

    _possLayout = new QVBoxLayout;
    _possLayout->addWidget(_possibles_l);
    _possLayout->addWidget(_possibles);

    _butPrecLayout = new QVBoxLayout;
    _butPrecLayout->addWidget(_ajouterPrec);
    _butPrecLayout->addWidget(_retirerPrec);
    _butPrecLayout->setAlignment(Qt::AlignVCenter);

    _precLayout = new QHBoxLayout;
    _precLayout->addLayout(_precListLayout);
    _precLayout->addLayout(_butPrecLayout);
    _precLayout->addLayout(_possLayout);

    _mainLayout = new QVBoxLayout(this);
    _mainLayout->addLayout(_formLayout);
    _mainLayout->addLayout(_precLayout);
    _mainLayout->addLayout(_buttonLayout);

    connect(_valider,SIGNAL(clicked()),this,SLOT(notifie()));
    connect(_ajouterPrec,SIGNAL(clicked()),this,SLOT(ajouterListe()));
    connect(_retirerPrec,SIGNAL(clicked()),this,SLOT(retirerListe()));
}

void EditTache::initChamps()
{
    _titre->setText(tacheEdit->getTitre());
    _dateDispo->setDate(tacheEdit->getDateDispo());
    _dateEcheance->setDate(tacheEdit->getEcheance());
    if(tacheEdit->getType() == UNITAIRE || tacheEdit->getType() == PREEMPTIVE || tacheEdit->getType() == NON_PREEMPTIVE)
        _duree->setTime(dynamic_cast<Tache_Unitaire*>(tacheEdit)->getDuree());
    else
        _duree->setEnabled(false);
    _type->setText(tacheEdit->getTypeToQString());
    //On récupère toutes les précédences et on les ajoute à la liste
    Tache::Iterator it = tacheEdit->getIterator();
    for(it;it.courant() != tacheEdit->end();it.next())
    {
        QListWidgetItem* item = new QListWidgetItem(_precedences);
        item->setText(it.valeur()->getTitre());
        QVariant v;
        v.setValue(it.valeur());
        item->setData(32,v);
        _precedences->addItem(item);
    }
    //On récupère le projet pour check les précédences compatibles
    Projet* p = dynamic_cast<ProjetManager*>(ProjetManager::getInstance())->getProjetTache(tacheEdit->getId());
    if(p)
    {
        Projet::IteratorDate it = p->getIteratorDate(tacheEdit->getDateDispo(),tacheEdit->getEcheance());
        for(it;it.courant() != it.end();it.next())
        {
            if(it.valeur()->getId() != tacheEdit->getId())
            {
                if(!tacheEdit->estPredecence(it.valeur()->getId()))
                {
                    QListWidgetItem* item = new QListWidgetItem(_possibles);
                    item->setText(it.valeur()->getTitre());
                    QVariant v;
                    v.setValue(it.valeur());
                    item->setData(32,v);
                    _possibles->addItem(item);
                }
            }
        }
    }
}

void EditTache::notifie()
{
    try
    {
        qDebug() << "notifie";
        QString s = _titre->text();
        tacheEdit->setTitre(s);
        QDate d = _dateDispo->date();
        QDate e = _dateEcheance->date();
        QTime dur = _duree->time();
        tacheEdit->setDateDispo(d);
        tacheEdit->setEcheance(e);
        if(tacheEdit->getType() == UNITAIRE || tacheEdit->getType() == PREEMPTIVE || tacheEdit->getType() == NON_PREEMPTIVE)
        {
            qDebug() << "rtiorjtre";
            dynamic_cast<Tache_Unitaire*>(tacheEdit)->setDuree(dur);
        }
        for(int i = 0; i < _precedences->count(); i++)
        {
            QListWidgetItem* item = _precedences->item(i);
            QVariant v = item->data(32);
            Tache* t = v.value<Tache*>();
            if(!tacheEdit->estPredecence(t->getId()))
            {
                tacheEdit->ajouterPrecedence(t);
            }
        }
        for(int i = 0; i < _possibles->count(); i++)
        {
            QListWidgetItem* item = _possibles->item(i);
            QVariant v = item->data(32);
            Tache* t = v.value<Tache*>();
            if(tacheEdit->estPredecence(t->getId()))
            {
                tacheEdit->supprimerPrecedence(t->getId());
            }
        }
    }
    catch(AgendaException& e)
    {
        QMessageBox::critical(this,"Impossible de modifier",e.getInfo());
    }
    emit modifie();
}

void EditTache::ajouterListe()
{
    QList<QListWidgetItem*> selected = _possibles->selectedItems();
    QList<QListWidgetItem*>::iterator it = selected.begin();
    for(it;it != selected.end();++it)
    {
       _precedences->addItem((*it)->clone());
    }
    qDeleteAll(_possibles->selectedItems());
}

void EditTache::retirerListe()
{
    QList<QListWidgetItem*> selected = _precedences->selectedItems();
    QList<QListWidgetItem*>::iterator it = selected.begin();
    for(it;it != selected.end();++it)
    {
       _possibles->addItem((*it)->clone());
    }
    qDeleteAll(_precedences->selectedItems());
}
