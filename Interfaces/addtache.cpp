#include "addtache.h"

addTache::addTache(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Ajouter une tâche");
    _vlayout= new QVBoxLayout(this);
    _datesLayout=new QHBoxLayout;
    _tachesLayout=new QHBoxLayout;
    _buttonLayout=new QHBoxLayout;
    _titreLayout=new QHBoxLayout;
    _dateDispo=new QDateEdit(this);
    _dateDispo->setCalendarPopup(true);
    _dateEcheance=new QDateEdit(this);
    _dateEcheance->setCalendarPopup(true);
    _dateDispo_l=new QLabel("Date de disponibilité:",this);
    _dateEcheance_l=new QLabel("Date d'échéance:",this);
    _titre=new QLineEdit(this);
    _titre_l=new QLabel("Nom:",this);
    _idTaches=new QLineEdit(this);
    _idTaches->setEnabled(false);
    _idTaches_l=new QLabel("ID des sous-tâches",this);
    _preemptive=new QCheckBox(this);
    _preemptive_l=new QLabel("Préemptive?",this);
    _unitaire=new QCheckBox(this);
    _unitaire->setChecked(true);
    _unitaire_l=new QLabel("Unitaire?");
    _ajouter=new QPushButton("Ajouter");
    _annuler=new QPushButton("Annuler");

    _titreLayout->addWidget(_titre_l);
    _titreLayout->addWidget(_titre);
    _titreLayout->addWidget(_preemptive_l);
    _titreLayout->addWidget(_preemptive);
    _titreLayout->addWidget(_unitaire_l);
    _titreLayout->addWidget(_unitaire);
    _datesLayout->addWidget(_dateDispo_l);
    _datesLayout->addWidget(_dateDispo);
    _datesLayout->addWidget(_dateEcheance_l);
    _datesLayout->addWidget(_dateEcheance);
    _tachesLayout->addWidget(_idTaches_l);
    _tachesLayout->addWidget(_idTaches);
    _buttonLayout->addWidget(_ajouter);
    _buttonLayout->addWidget(_annuler);

    _vlayout->addLayout(_titreLayout);
    _vlayout->addLayout(_datesLayout);
    _vlayout->addLayout(_tachesLayout);
    _vlayout->addLayout(_buttonLayout);
    connect(_unitaire,SIGNAL(clicked(bool)),this,SLOT(switchingTache(bool)));
    connect(_annuler,SIGNAL(clicked()),this,SLOT(close()));
}

addTache::~addTache()
{
    delete _titreLayout;
    delete _datesLayout;
    delete _tachesLayout;
    delete _buttonLayout;
    delete _vlayout;
    delete _dateDispo_l;
    delete _dateEcheance_l;
    delete _titre_l;
    delete _idTaches_l;
    delete _preemptive_l;
    delete _unitaire_l;
    delete _ajouter;
    delete _annuler;
    delete _preemptive;
    delete _unitaire;
    delete _titre;
    delete _idTaches;
    delete _dateDispo;
    delete _dateEcheance;
}

