#include "../headers/projectview.h"

ProjectView::ProjectView(QWidget *parent) : QWidget(parent)
{
    _creerProjet=new QPushButton("Ajouter un projet",this);
    _creerTache=new QPushButton("Ajouter une tâche",this);
    _Editer=new QPushButton("Editer le projet",this);
    _lesProjets=new QTreeWidget(this);
    _vlayout=new QVBoxLayout(this);
    _buttonLayout=new QHBoxLayout;

    _buttonLayout->addWidget(_creerProjet);
    _buttonLayout->addWidget(_creerTache);
    _buttonLayout->addWidget(_Editer);
    _vlayout->addWidget(_lesProjets);
    _vlayout->addLayout(_buttonLayout);
    _ajouterProjet=nullptr;
    _ajouterTache=nullptr;
    _editerProjet=nullptr;
    QTreeWidgetItem * noeud1 = ajouterRacine("noeud1","mon premier noeud");
    QTreeWidgetItem * noeud2 = ajouterEnfant(noeud1,"sous noeud 1","mon premier sous noeud");
    ajouterEnfant(noeud2,"sous sous noeud 1","mon premier sous sous noeud");
    connect(_creerProjet,SIGNAL(clicked()),this,SLOT(showCreateProject()));
    connect(_creerTache,SIGNAL(clicked()),this,SLOT(showCreateTache()));
    connect(_Editer,SIGNAL(clicked()),this,SLOT(showEditProject()));
}
QTreeWidgetItem* ProjectView::ajouterRacine(QString name, QString description)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(_lesProjets);
    treeItem->setText(0, name);
    treeItem->setText(1, description);
    return treeItem;
}

QTreeWidgetItem* ProjectView::ajouterEnfant(QTreeWidgetItem *parent, QString name, QString description)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();
    treeItem->setText(0, name);
    treeItem->setText(1, description);
    parent->addChild(treeItem);
    return treeItem;
}

