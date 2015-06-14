#include "../headers/projectview.h"
#include "../headers/tache_unitaire.h"
#include<QDebug>
#include<QAction>
#include<QMenu>
ProjectView::ProjectView(QWidget *parent) : QWidget(parent)
{
    _creerProjet=new QPushButton("Ajouter un projet",this);
    _lesProjets=new QTreeWidget(this);
    _mainLayout=new QHBoxLayout(this);
    _edit = nullptr;

    _ajout = new QAction(QIcon(":/res/charger.png"), tr("Nouvelle Tache"), this);
    connect(_ajout, SIGNAL(triggered()), this, SLOT(slotAjouterTache()));
    _suppr = new QAction(QIcon(":/res/sauvegarder.png"),tr("Supprimer"),this);
    connect(_suppr,SIGNAL(triggered()),this,SLOT(suppressionNoeud()));

    _export= new QMenu(tr("Exporter"),this);
    _exportProgProj=new QMenu(tr("Programmations liées"),this);
    _exportProgProjXML=new QAction(tr("XML"),this);
    _exportProgProj->addAction(_exportProgProjXML);
    _export->addMenu(_exportProgProj);
    connect(_exportProgProjXML,SIGNAL(triggered()),this,SLOT(exporterProgProjetXML()));

    _leftLayout = new QVBoxLayout;
    _leftLayout->addWidget(_lesProjets);
    _leftLayout->addWidget(_creerProjet);
    _mainLayout->addLayout(_leftLayout);
    _mainLayout->addWidget(_edit);
    _ajouterProjet=nullptr;
    _ajouterTache=nullptr;
    _editerProjet=nullptr;

    _lesProjets->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(_lesProjets,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(clicDroit(QPoint)));
    connect(_creerProjet,SIGNAL(clicked()),this,SLOT(showCreateProject()));
    connect(_lesProjets,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(lancerEdit(QTreeWidgetItem*,int)));
}
QTreeWidgetItem* ProjectView::ajouterRacine(QString& name, QString& description,QVariant& data)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(_lesProjets);
    treeItem->setText(0, name);
    treeItem->setText(1, description);
    treeItem->setData(0,32,data);
    return treeItem;
}

QTreeWidgetItem* ProjectView::ajouterEnfant(QTreeWidgetItem *parent, QString& name, QString& description,
                                            QVariant& data)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();
    treeItem->setText(0, name);
    treeItem->setText(1, description);
    treeItem->setData(0,32,data);
    parent->addChild(treeItem);
    return treeItem;
}

void ProjectView::ajouterTache(Tache* t, QTreeWidgetItem* parent)
{
    qDebug() << t->getId();
    QString name = t->getTitre();
    qDebug() << name;
    QString desc = "";
    QVariant var;
    if(t->getType() != COMPOSITE)
    {
        Tache_Unitaire* tu = dynamic_cast<Tache_Unitaire*>(t);
        var.setValue(tu);
        ajouterEnfant(parent,name,desc,var);
    }
    else
    {
        Tache_Composite* tc = dynamic_cast<Tache_Composite*>(t);
        var.setValue(tc);
        QTreeWidgetItem* nouvParent = ajouterEnfant(parent,name,desc,var);
        qDebug() << "nombre de sous taches ! " << tc->getNbSousTaches();
        Tache_Composite::Iterator it = tc->getIterator();
        while(it.courant() != tc->end())
        {
            ajouterTache(it.valeur(),nouvParent);
            it.next();
        }
    }
}

void ProjectView::init()
{
    qDebug() <<" debut init";
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
            Tache* t = p->getTacheParCompteur(j);
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
        QMenu menu(this);
        menu.addAction(_ajout);
        menu.addAction(_suppr);
        if(_noeudClic->data(0,32).canConvert<Projet*>()){
            menu.addMenu(_export);
        }
        menu.exec( _lesProjets->mapToGlobal(pos));
    }
}

void ProjectView::slotAjouterTache()
{
    Tache* t;
    QVariant tvar;
    QString desc="";
    QVariant donnees =_noeudClic->data(0,32);
    if(donnees.canConvert<Projet*>() || donnees.canConvert<Tache_Composite*>())
    {
        //On affiche la fenêtre pour créer une tâche
        if(showCreateTache()==QDialog::Accepted && !_ajouterTache->getTitre().isEmpty()){
            //On la récupère
            t = TacheManager::getInstance()->getDernierItem();
            qDebug() << "4";
            if (donnees.canConvert<Projet*>())
            {
                try
                {
                    Projet* p = donnees.value<Projet*>();
                    p->ajouterTache(t);
                    ajouterTache(t,_noeudClic);
                }catch(AgendaException e){QMessageBox::critical(this,"erreur ajout",e.getInfo());}
            }
            else
            {
                Tache_Composite* tc = donnees.value<Tache_Composite*>();
                tc->ajouterSousTache(t);
                ajouterTache(t,_noeudClic);
            }
        }
    }
    else QMessageBox::warning(this,"erreur noeud","une tache unitaire ne peut pas avoir de sous tâche");
}

void ProjectView::suppressionNoeud()
{
    QTreeWidgetItem* supp=nullptr;
    int nb=_noeudClic->childCount();

    for(int i=0;i<nb;i++)
    {
        supp=_noeudClic->child(i);
        QVariant varsupp = supp->data(0,32);
        supprimerValeurAssocieeQVariant(varsupp);
    }

    QVariant donnees = _noeudClic->data(0,32);
    supprimerValeurAssocieeQVariant(donnees);
    /*qDebug() << "avant suppression" << _lesProjets->topLevelItem(0)->childCount();
    _lesProjets->removeItemWidget(_noeudClic,0);
    qDebug() << "après " << _lesProjets->topLevelItem(0)->childCount();
    _lesProjets->reset();*/
    _lesProjets->clear();
    init();
}

void ProjectView::supprimerValeurAssocieeQVariant(QVariant& varsupp)
{
    if (varsupp.canConvert<Projet*>())
    {
        Projet* projetsupp = varsupp.value<Projet*>();
        ProjetManager::getInstance()->supprimerItem(projetsupp->getId());
        EditProject* e=dynamic_cast<EditProject*>(_edit);
        if(e!=NULL && e->getProjet()->getId()==projetsupp->getId()){
            _edit->hide();
            _mainLayout->removeWidget(_edit);
        }
    }
    else if (varsupp.canConvert<Tache_Unitaire*>() || varsupp.canConvert<Tache_Composite*>())
    {
        Tache* tachesupp;
        if(varsupp.canConvert<Tache_Unitaire*>())
            tachesupp= varsupp.value<Tache_Unitaire*>();
        else tachesupp= varsupp.value<Tache_Composite*>();

        supprimerLienProjet(tachesupp);
        supprimerLienTacheComposite(tachesupp);
        TacheManager::getInstance()->supprimerItem(tachesupp->getId());
        EditTache* t=dynamic_cast<EditTache*>(_edit);
        if(t!=NULL && t->getTache()->getId()==tachesupp->getId()){
            _edit->hide();
            _mainLayout->removeWidget(_edit);
        }
    }
}

void ProjectView::supprimerLienProjet(Tache* tachesupp)
{
    ProjetManager::Iterator it = ProjetManager::getInstance()->getIterator();
    bool dedans = false;
    while(it.courant() != ProjetManager::getInstance()->end() && !dedans)
    {
        dedans = it.valeur()->supprSiDedans(tachesupp->getId());
        it.next();
    }
}
void ProjectView::supprimerLienTacheComposite(Tache* tachesupp)
{
    TacheManager::IteratorTypeT itType = dynamic_cast<TacheManager*>(TacheManager::getInstance())->getIteratorTypeT(COMPOSITE);
    bool dedans = false;

    while(itType.courant() != itType.fin() && !dedans)
    {
        qDebug() << "entrée while";
        dedans = dynamic_cast<Tache_Composite*>(itType.valeur())->supprimerSousTache(tachesupp->getId());
        qDebug() << "dedans ? " << dedans;
        itType.next();
        qDebug() << "next hasn't fail";
    }
}

void ProjectView::lancerEdit(QTreeWidgetItem *item, int column)
{
    QVariant v = item->data(column,32);
    if(v.canConvert<Projet*>())
    {
        Projet* p = v.value<Projet*>();
        delete _edit;
        _edit = new EditProject(p,this);
        _mainLayout->addWidget(_edit);
        _edit->initChamps();
    }
    else
    {
        Tache * t;
        if(v.canConvert<Tache_Unitaire*>())
            t = v.value<Tache_Unitaire*>();
        else
            t = v.value<Tache_Composite*>();
        delete _edit;
        _edit = new EditTache(t,this);
        _mainLayout->addWidget(_edit);
        _edit->initChamps();
    }
    connect(_edit,SIGNAL(modifie()),this,SLOT(actualiser()));
}

void ProjectView::exporterProgProjetXML(){
    Tache* t;
    QVariant tvar;
    QString desc="";
    QVariant donnees =_noeudClic->data(0,32);
    if(donnees.canConvert<Projet*>())
    {
     XMLExport* xmlexport=new XMLExport("xml");
     ProgrammationProjetExport* p=new ProgrammationProjetExport(donnees.value<Projet*>(),"xml",xmlexport);
     p->exportData();
     QMessageBox::information(this,"Exportation","Projet exporté au format XML.");
     //delete xmlexport;
     delete p;
    }
    else QMessageBox::warning(this,"Erreur","L'objet à exporter ne désigne pas un projet");
}
