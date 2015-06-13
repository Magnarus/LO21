#include "../headers/accueil.h"

Accueil::Accueil(QWidget *parent) : QWidget(parent)
{
    _edtInterface=new EmploiDuTemps(this);
    _projectTree=new ProjectView(this);
    _mainLayout=new QVBoxLayout(this);
    _projectTree->hide();
    _mainLayout->addWidget(_edtInterface);
    this->setLayout(_mainLayout);

    connect(_edtInterface,SIGNAL(progChanged()),this,SLOT(prevenirAgenda()));
    connect(_projectTree,SIGNAL(previentAccueil()),this,SLOT(prevenirAgenda()));
}


