#include "../headers/addprogunitaire.h"
AddProgUnitaire::AddProgUnitaire(QWidget *parent):AddProg(parent)
{
    _taches = new QListWidget(this);
    setWindowTitle("Ajout d'une programmation de tâche");
    //On récupère toutes les taches unitaires programmables non programmées
    TacheManager::IteratorTypeT itType = dynamic_cast<TacheManager*>(TacheManager::getInstance())->getIteratorTypeT(UNITAIRE);
    QList<const Tache_Unitaire*> prog;

    //On récupère toutes les tâches des programmations de tâches
    ProgManager::Iterator it = ProgManager::getInstance()->getIterator();
    while(it.courant() != ProgManager::getInstance()->end())
    {
        if(it.valeur()->getType() == PROGTACHE)
        {
            ProgTUnit* ptu = dynamic_cast<ProgTUnit*>(it.valeur());
            prog.push_back(ptu->getProgramme());
        }
        it.next();
    }
    //On parcours toutes les tâches unitaires (préemptives ou non) et on check si elles sont dans les tâches récupérées
    while(itType.courant() != itType.fin())
    {
        Tache_Unitaire* courant = dynamic_cast<Tache_Unitaire*>(itType.valeur());
        if(courant->precedencesFinies())
        {
            if(!prog.contains(courant))
            {
                QListWidgetItem* item = new QListWidgetItem(_taches);
                item->setText(courant->getTitre());
                QVariant v;
                v.setValue(courant);
                item->setData(32,v);
                _taches->addItem(item);
            }
        }
        itType.next();
    }

    _taches->setSelectionMode(QAbstractItemView::SingleSelection);
    _mainLayout->addWidget(_taches);
    _mainLayout->addLayout(_buttonLayout);
    connect(_valider,SIGNAL(clicked()),this,SLOT(creation()));
    connect(_taches,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(majInfo(QListWidgetItem*)));
}

void AddProgUnitaire::creation()
{
    QMap<QString,QVariant> params;
    params["date"] = QVariant(_date->date());
    params["duree"]= QVariant(_duree->time());
    params["horaire"] = QVariant(_horaire->time());
    qDebug() << _taches->selectedItems().size();
    QVariant p = _taches->selectedItems().at(0)->data(32);
    Tache_Unitaire* t = p.value<Tache_Unitaire*>();
    params["programme"] = p;
    try
    {
        ProgManager::getInstance()->ajouterItem("UNITAIRE",params);
        t->setEtat(EN_COURS);
        QMessageBox::information(this,"ajout réussi","programmation bien ajoutée !");
        done(1);
    }
    catch(AgendaException &e)
    {
        QMessageBox::critical(this,"Erreur ajout",e.getInfo());
        done(0);
    }

}

void AddProgUnitaire::majInfo(QListWidgetItem * selected)
{
    QVariant var = selected->data(32);
    Tache_Unitaire* t = var.value<Tache_Unitaire*>();
    _date->setMinimumDate(t->getDateDispo());
    _date->setDate(t->getDateDispo());
    if(t->getType() == NON_PREEMPTIVE)
    {
        _duree->setTime(t->getDuree());
        _duree->setEnabled(false);
    }
    else
    {
        QTime durMax = t->getDuree();
        QTime durTemp;
        int h,m;
        ProgManager::Iterator it = ProgManager::getInstance()->getIterator();
        while(it.courant() != ProgManager::getInstance()->end())
        {
            ProgTUnit* ptu = dynamic_cast<ProgTUnit*>(it.valeur());
            if(ptu->estProg(t))
            {
                durTemp = ptu->getDuree();
                h = durMax.hour() - durTemp.hour();
                durMax.setHMS(h,0,0);

            }
            it.next();
        }
        _duree->setMaximumTime(durMax);
    }

}
