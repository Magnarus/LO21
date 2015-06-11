#include "../headers/editproject.h"
EditProject::EditProject(Projet *p, QWidget *parent):Editeur(parent),projetEdit(p)
{
    qDebug() << "titre projet ! " << p->getTitre();
    _taches = new QListWidget(this);
    _taches_l = new QLabel(QString("Taches : "));
    _taches_l->setAlignment(Qt::AlignHCenter);

    _titre = new QLineEdit(this);


    _dateDispo = new QDateEdit(this);

    _dateEcheance = new QDateEdit(this);

    _formLayout = new QFormLayout;
    _formLayout->addRow("Titre : ",_titre);
    _formLayout->addRow("Date Dispo : ",_dateDispo);
    _formLayout->addRow("Date Echeance : ",_dateEcheance);

    _tachesLayout = new QVBoxLayout;
    _tachesLayout->addWidget(_taches_l);
    _tachesLayout->addWidget(_taches);
    _tachesLayout->setAlignment(Qt::AlignHCenter);

    _mainLayout = new QVBoxLayout(this);
    _mainLayout->addLayout(_formLayout);
    _mainLayout->addLayout(_tachesLayout);
    _mainLayout->addLayout(_buttonLayout);

}

void EditProject::initChamps()
{
    qDebug() << "init champ : titre projet ! " << projetEdit->getTitre();

    _titre->setText(projetEdit->getTitre());
    _dateDispo->setDate(projetEdit->getDateDispo());
    _dateEcheance->setDate(projetEdit->getDateEcheance());
    Projet::Iterator it = projetEdit->getIterator();
    for(it;it.courant() != projetEdit->end();it.next())
    {
        QListWidgetItem* item = new QListWidgetItem(_taches);
        item->setText(it.valeur()->getTitre());
        QVariant v;
        v.setValue(it.valeur());
        item->setData(32,v);
        _taches->addItem(item);
    }
    _taches->setSelectionMode(QAbstractItemView::NoSelection);
}
