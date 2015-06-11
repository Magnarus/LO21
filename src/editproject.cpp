#include "../headers/editproject.h"
EditProject::EditProject(Projet *p, QWidget *parent):Editeur(parent),projetEdit(p)
{

    _taches = new QListWidget(this);
    _taches_l = new QLabel(QString("Taches : "));
    _taches_l->setAlignment(Qt::AlignHCenter);

    _titre = new QLineEdit(this);
    //_titre->setText(p->getTitre());

    _dateDispo = new QDateEdit(this);
    //_dateDispo->setDate(p->getDateDispo());

    _dateEcheance = new QDateEdit(this);
    //_dateEcheance->setDate(p->getDateEcheance());

    _formLayout = new QFormLayout;
    _formLayout->addRow("Titre : ",_titre);
    _formLayout->addRow("Date Dispo : ",_dateDispo);
    _formLayout->addRow("Date Echeance : ",_dateEcheance);

    /*Projet::Iterator it = p->getIterator();
    Tache* t;
    while(it.courant() != p->end())
    {
        t = it.valeur();
        QListWidgetItem* item = new QListWidgetItem;
        item->setText(t->getTitre());
        item->setData(0,QVariant(t->getId()));
        _taches->addItem(item);
        it.next();
    }*/
    _tachesLayout = new QVBoxLayout;
    _tachesLayout->addWidget(_taches_l);
    _tachesLayout->addWidget(_taches);
    _tachesLayout->setAlignment(Qt::AlignHCenter);

    _mainLayout = new QVBoxLayout(this);
    _mainLayout->addLayout(_formLayout);
    _mainLayout->addLayout(_tachesLayout);
    _mainLayout->addLayout(_buttonLayout);

}
