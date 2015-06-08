#include "addproject.h"

AddProject::AddProject(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(QString("Créer un projet"));
    _vlayout=new QVBoxLayout(this);
    _titreLayout=new QHBoxLayout();
    _datesLayout=new QHBoxLayout();
    _buttonsLayout=new QHBoxLayout();
    _titre_l=new QLabel("Titre:",this);
    _dateDispo_l=new QLabel("Date de disponibilité:",this);
    _dateEcheance_l=new QLabel("Date d'échéance:",this);
    _ajouter=new QPushButton("Créer le projet",this);
    _annuler=new QPushButton("Annuler",this);
    _titre=new QLineEdit(this);
    _dateDispo=new QDateEdit(this);
    _dateEcheance=new QDateEdit(this);
    _dateDispo->setCalendarPopup(true);
    _dateEcheance->setCalendarPopup(true);

    _titreLayout->addWidget(_titre_l);
    _titreLayout->addWidget(_titre);

    _datesLayout->addWidget(_dateDispo_l);
    _datesLayout->addWidget(_dateDispo);
    _datesLayout->addWidget(_dateEcheance_l);
    _datesLayout->addWidget(_dateEcheance);

    _buttonsLayout->addWidget(_ajouter);
    _buttonsLayout->addWidget(_annuler);

    _vlayout->addLayout(_titreLayout);
    _vlayout->addLayout(_datesLayout);
    _vlayout->addLayout(_buttonsLayout);
    connect(_annuler,SIGNAL(clicked()),this,SLOT(close()));
}

AddProject::~AddProject()
{
    delete _ajouter;
    delete _annuler;
    delete _dateDispo;
    delete _dateEcheance;
    delete _titre;
    delete _titre_l;
    delete _dateDispo_l;
    delete _dateEcheance_l;
    delete _titreLayout;
    delete _buttonsLayout;
    delete _datesLayout;
    delete _vlayout;
}

