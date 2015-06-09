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
    QVariant var;
    QString noeud1Name("noeud1");
    QString noeud2Name("sous noeud 1");
    QString noeud3Name("sous sous noeud 1");
    QTreeWidgetItem * noeud1 = ajouterRacine(noeud1Name,noeud1Name,var);
    QTreeWidgetItem * noeud2 = ajouterEnfant(noeud1,noeud2Name,noeud2Name,var);
    ajouterEnfant(noeud2,noeud3Name,noeud3Name,var);

    connect(_creerProjet,SIGNAL(clicked()),this,SLOT(showCreateProject()));
    connect(_creerTache,SIGNAL(clicked()),this,SLOT(showCreateTache()));
    connect(_Editer,SIGNAL(clicked()),this,SLOT(showEditProject()));
}
QTreeWidgetItem* ProjectView::ajouterRacine(QString& name, QString& description,QVariant& data)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(_lesProjets);
    treeItem->setText(0, name);
    treeItem->setText(1, description);
    return treeItem;
}

QTreeWidgetItem* ProjectView::ajouterEnfant(QTreeWidgetItem *parent, QString& name, QString& description,
                                            QVariant& data)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();
    treeItem->setText(0, name);
    treeItem->setText(1, description);
    parent->addChild(treeItem);
    return treeItem;
}

void ProjectView::ajouterTache(Tache* t, QTreeWidgetItem* parent)
{
    QString name = t->getTitre();
    QString desc = "";
    QVariant var;
    var.setValue(t);
    if(t->getType() != COMPOSITE)
        ajouterEnfant(parent,name,desc,var);
    else
    {
        QTreeWidgetItem* nouvParent = ajouterEnfant(parent,name,desc,var);
        for(int i = 0; i< dynamic_cast<Tache_Composite*>(t)->getNbSousTaches(); i++)
            ajouterTache(dynamic_cast<Tache_Composite*>(t)->getSousTache(i),nouvParent);
    }

}

void ProjectView::init()
{
    QVariant var;
    QString name;
    QString desc ="";
    ProjetManager::Iterator it = ProjetManager::getInstance()->getIterator();
    while(it.courant() != ProjetManager::getInstance()->end())
    {
        Projet* p = it.valeur();
        var.setValue(p);
        name = p->getTitre();
        QTreeWidgetItem* itemCourant = ajouterRacine(name,desc,var);
        int i = p->getNbTaches();
        for(int j = 0; j<i;j++)
        {
           Tache* t = p->getTache(j);
           ajouterTache(t,itemCourant);
        }

    }
}
