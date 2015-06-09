#include "../headers/accueil.h"

Accueil::Accueil(QWidget *parent) : QWidget(parent)
{
    _chooseInterface=new QComboBox(this);
    _chooseInterface->setMaximumWidth(150);
    _chooseInterface->addItem(QString("Emploi du temps"));
    _chooseInterface->addItem(QString("Gestion de projet"));
    _edtInterface=new EmploiDuTemps(this);
    _projectTree=new ProjectView(this);
    _mainLayout=new QVBoxLayout(this);
    _mainLayout->addWidget(_chooseInterface);
    _projectTree->hide();
    _mainLayout->addWidget(_edtInterface);
    this->setLayout(_mainLayout);
    connect(_chooseInterface,SIGNAL(currentTextChanged(QString)),this,SLOT(changeInterface(QString)));
}

Accueil::~Accueil()
{
    delete _edtInterface;
    delete _chooseInterface;
    delete _mainLayout;
}

