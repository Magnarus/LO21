#include "projectview.h"

projectView::projectView(QWidget *parent) : QWidget(parent)
{
    _creerProjet=new QPushButton("Ajouter un projet",this);
    _creerTache=new QPushButton("Ajouter une tâche",this);
    _Editer=new QPushButton("Editer le projet",this);
    _lesProjets=new QTreeView(this);
    _vlayout=new QVBoxLayout(this);
    _buttonLayout=new QHBoxLayout;

    _buttonLayout->addWidget(_creerProjet);
    _buttonLayout->addWidget(_creerTache);
    _buttonLayout->addWidget(_Editer);
    _vlayout->addLayout(_buttonLayout);
    _ajouterProjet=nullptr;
    _ajouterTache=nullptr;
    _editerProjet=nullptr;
    connect(_creerProjet,SIGNAL(clicked()),this,SLOT(showCreateProject()));
    connect(_creerTache,SIGNAL(clicked()),this,SLOT(showCreateTache()));
    connect(_Editer,SIGNAL(clicked()),this,SLOT(showEditProject()));
}

projectView::~projectView()
{
    delete _creerProjet;
    delete _creerTache;
    delete _Editer;
    delete _lesProjets;
    delete _buttonLayout;
    delete _vlayout;
    delete _ajouterProjet;
    delete _ajouterTache;
    delete _editerProjet;
}

