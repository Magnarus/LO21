#include "../headers/addprogunitaire.h"
AddProgUnitaire::AddProgUnitaire(QWidget *parent):AddProg(parent)
{
    _taches = new QListWidget(this);
    setWindowTitle("Ajout d'une programmation de tâche");
    //On récupère toutes les taches unitaires non programmées
    TacheManager::IteratorTypeT itType = dynamic_cast<TacheManager*>(TacheManager::getInstance())->getIteratorTypeT(UNITAIRE);
    QList<const Tache_Unitaire*> prog;
    ProgManager::Iterator it = ProgManager::getInstance()->getIterator();
    while(it.courant() != ProgManager::getInstance()->end())
    {
        if(it.valeur()->getType() == PROGTACHE)
        {
            ProgTUnit* ptu = dynamic_cast<ProgTUnit*>(it.valeur());
            prog.push_back(ptu->getProgramme());
        }
        it.next();
    }
    while(itType.courant() != itType.fin())
    {
        Tache_Unitaire* courant = dynamic_cast<Tache_Unitaire*>(itType.valeur());
        if(!prog.contains(courant))
        {
            QListWidgetItem* item = new QListWidgetItem(_taches);
            item->setText(courant->getTitre());
            QVariant v;
            v.setValue(courant);
            item->setData(32,v);
            _taches->addItem(item);
        }
    }

    _taches->setSelectionMode(QAbstractItemView::SingleSelection);
    _mainLayout->addWidget(_taches);
    _mainLayout->addLayout(_buttonLayout);
}
