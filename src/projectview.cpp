#include "../headers/projectview.h"
#include<QDebug>
#include<QAction>
#include<QMenu>
ProjectView::ProjectView(QWidget *parent) : QWidget(parent)
{
    _creerProjet=new QPushButton("Ajouter un projet",this);
    _creerTache=new QPushButton("Ajouter une tâche",this);
    _Editer=new QPushButton("Editer le projet",this);
    _actualiser= new QPushButton("Actualiser tree view",this);
    _lesProjets=new QTreeWidget(this);
    _vlayout=new QVBoxLayout(this);
    _buttonLayout=new QHBoxLayout;

    _buttonLayout->addWidget(_creerProjet);
    _buttonLayout->addWidget(_creerTache);
    _buttonLayout->addWidget(_Editer);
    _buttonLayout->addWidget(_actualiser);
    _vlayout->addWidget(_lesProjets);
    _vlayout->addLayout(_buttonLayout);
    _ajouterProjet=nullptr;
    _ajouterTache=nullptr;
    _editerProjet=nullptr;

    _lesProjets->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(_lesProjets,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(clicDroit(QPoint)));

    connect(_creerProjet,SIGNAL(clicked()),this,SLOT(showCreateProject()));
    connect(_creerTache,SIGNAL(clicked()),this,SLOT(showCreateTache()));
    connect(_Editer,SIGNAL(clicked()),this,SLOT(showEditProject()));
    connect(_actualiser,SIGNAL(clicked()),this,SLOT(actualiser()));
}
QTreeWidgetItem* ProjectView::ajouterRacine(QString& name, QString& description,QVariant& data)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(_lesProjets);
    treeItem->setText(0, name);
    treeItem->setText(1, description);
    treeItem->setData(0,32,data);
    _lesProjets->addTopLevelItem(treeItem);
    return treeItem;
}

QTreeWidgetItem* ProjectView::ajouterEnfant(QTreeWidgetItem *parent, QString& name, QString& description,
                                            QVariant& data)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();
    qDebug() << "dans ajouterEnfant" << data.typeName();
    treeItem->setText(0, name);
    treeItem->setText(1, description);
    treeItem->setData(0,32,data);
    parent->addChild(treeItem);
    return treeItem;
}

void ProjectView::ajouterTache(Tache* t, QTreeWidgetItem* parent)
{
    QString name = t->getTitre();
    QString desc = "";
    QVariant var;
    var.setValue(t);
    qDebug() << "dans ajouterTache" << var.typeName();
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
        qDebug() << var.typeName();
        name = p->getTitre();
        QTreeWidgetItem* itemCourant = ajouterRacine(name,desc,var);
        int i = p->getNbTaches();
        for(int j = 0; j<i;j++)
        {
           Tache* t = p->getTache(j);
           ajouterTache(t,itemCourant);
        }
        it.next();
    }
}

void ProjectView::clicDroit(QPoint pos)
{
    //On récupère le noeud de la treeview cliqué
     _noeudClic = _lesProjets->itemAt(pos);

    //On check qu'il y en a bien un
    if(_noeudClic)
    {
        //On ajoute des actions au menu contextuel et on les relie à des slots
        QAction* ajout = new QAction(QIcon(":/res/charger.png"), tr("Nouvelle Tache"), this);
        connect(ajout, SIGNAL(triggered()), this, SLOT(slotAjouterTache()));
        QAction* suppr = new QAction(QIcon(":/res/sauvegarder.png"),tr("Supprimer"),this);
        connect(ajout,SIGNAL(triggered()),this,SLOT(suppressionNoeud()));
        QMenu menu(this);
        menu.addAction(ajout);
        menu.addAction(suppr);
        menu.exec( _lesProjets->mapToGlobal(pos));
    }
}

void ProjectView::slotAjouterTache()
{
    Tache* t;
    QVariant tvar;
    QString desc="";
    QVariant donnees =_noeudClic->data(0,32);
    if(donnees.canConvert<Projet*>()|| donnees.canConvert<Tache_Composite*>())
    {
        //On affiche la fenêtre pour créer une tâche
        showCreateTache();
        //On la récupère
        t = TacheManager::getInstance()->getDernierItem();
        tvar.setValue(t);
    }
    else QMessageBox::critical(this,"erreur noeud","une tache unitaire ne peut pas avoir de sous tâche");

    if (donnees.canConvert<Projet*>())
    {
        try
        {
            Projet* p = donnees.value<Projet*>();
            p->ajouterTache(t);
            ajouterTache(t,_noeudClic);
        }catch(AgendaException e){QMessageBox::critical(this,"erreur ajout",e.getInfo());}
    }
    else if(donnees.canConvert<Tache_Composite*>())
    {
        try
        {
             Tache* tinter = donnees.value<Tache*>();
             Tache_Composite* tc= dynamic_cast<Tache_Composite*>(tinter);
             qDebug() << "titre de ma tache composite convertie" << tc->getTitre();
             tc->ajouterSousTache(t);
             ajouterEnfant(_noeudClic,t->getTitre(),desc,tvar);
        }
        catch(const std::bad_cast& e) {
            QMessageBox::critical(this,"erreur interne","erreur interne");
        }
    }
    _noeudClic = nullptr;
}

void ProjectView::suppressionNoeud()
{
    QTreeWidgetItem* supp=nullptr;
    int nb=_noeudClic->childCount();
    for(int i=0;i<nb;i++)
    {
        supp=_noeudClic->child(i);
        QVariant varsupp = supp->data(0,32);
        if (varsupp.canConvert<Projet*>())
        {
            Projet* projetsupp = varsupp.value<Projet*>();
            ProjetManager::getInstance()->supprimerItem(projetsupp->getId());
            delete projetsupp;
        }
        else
        {
            Tache* tachesupp= varsupp.value<Tache*>();
            TacheManager::getInstance()->supprimerItem(tachesupp->getId());
            delete tachesupp;
        }
    }
    _lesProjets->removeItemWidget(_noeudClic,0);
    _noeudClic = nullptr;
}
