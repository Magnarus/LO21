#include"headers/Agenda.h"

Agenda::Agenda(Accueil* a):_a(a)
{
    this->setCentralWidget(_a);
    this->setWindowState(Qt::WindowMaximized);

    _menuFichier = menuBar()->addMenu("&Fichier");
    _chargerFichier = new QAction("&Charger", this);
    _chargerFichier->setShortcut(QKeySequence("Ctrl+L"));
    _chargerFichier->setIcon(QIcon(":/res/charger.png"));
   // _sauvegarderFichier = new QAction("&Sauvegarder",this);
    _sauvegarderFichier=new QMenu("&Sauvegarder",this);
    _saveOptions.push_back(new QMenu("&XML",this));
    _saveOptions.push_back(new QMenu("&Fichier",this));
    _saveData.push_back(new QAction("&Programmation de la semaine",this));
    _saveData.push_back(new QAction("Programmation d'un projet",this));
    _saveOptions.first()->addAction(_saveData.first());
    _saveOptions.first()->addAction(_saveData[1]);
    //_saveOption=new QMenu("&XML",this);
    //_saveOption->addAction(new QAction("&Programmation de la semaine",this));
    //_saveOption->addAction(new QAction("&Programmation d'un projet",this));
    for(QVector<QMenu*>::iterator it=_saveOptions.begin();it!=_saveOptions.end();++it)
        _sauvegarderFichier->addMenu(*it);
   // _sauvegarderFichier->setShortcut(QKeySequence("Ctrl+S"));
    _sauvegarderFichier->setIcon(QIcon(":/res/sauvegarder.png"));
    _menuFichier->addAction(_chargerFichier);
    _menuFichier->addMenu(_sauvegarderFichier); //changed

     QDockWidget* dock = new QDockWidget(QLatin1String("Last filters"),this);
     dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    _dockWidget = new QWidget();
    _sideLayout = new QVBoxLayout();
    _calendar = new QCalendarWidget();
    _calendar->setMinimumDate(QDate::currentDate());
    _calendar->selectedDate().dayOfWeek();
    _list = new QListWidget();
    _sideLayout->addWidget(_calendar);
    _sideLayout->addWidget(_list);
    _dockWidget->setLayout(_sideLayout);
     dock->setWidget(_dockWidget);
     addDockWidget(Qt::LeftDockWidgetArea,dock);

    _menuMode = menuBar()->addMenu("&Mode");
    _edtMode = new QAction("&Planning",this);
    _edtMode->setShortcut(QKeySequence("CTRL+P"));
    _edtMode->setIcon(QIcon(":/res/calendrier.png"));
    _treeMode = new QAction("&Gestion des projets",this);
    _treeMode->setShortcut(QKeySequence("CTRL+T"));
    _treeMode->setIcon(QIcon(":/res/tree.png"));
    _addProgU = new QAction("Programmer tâche unitaire",this);
    _addProgU->setIcon(QIcon(":/res/nouveau.png"));
    _addProgU->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_U));
    _addProgA = new QAction("Programmer activite",this);
    _addProgA->setIcon(QIcon(":/res/nouveau.png"));
    _addProgA->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_A));

    QMenu *menu = new QMenu();
    menu->setIcon(QIcon(":/res/nouveau.png"));
    menu->addAction(_addProgU);
    menu->addAction(_addProgA);

    _programmer = new QToolButton(this);
    _programmer->setMenu(menu);
    _programmer->setPopupMode(QToolButton::InstantPopup);

    _menuMode->addAction(_edtMode);
    _menuMode->addAction(_treeMode);


    _toolbar = addToolBar("Agenda");
    _toolbar->addAction(_chargerFichier);
    //_toolbar->addAction(_sauvegarderFichier); //changed

    _toolbar->addSeparator();
    _toolbar->addAction(_edtMode);
    _toolbar->addAction(_treeMode);
    _toolbar->addSeparator();
    _toolbar->addWidget(_programmer);

    _progU = new AddProgUnitaire();
    _progA = new AddProgActivite();
    connect(_edtMode, SIGNAL(triggered()), _a, SLOT(setPlanningOn()));
    connect(_treeMode,SIGNAL(triggered()), _a,SLOT(setTreeOn()));
    connect(_a,SIGNAL(previentAgenda()),this,SLOT(updateList()));
    connect(_calendar,SIGNAL(selectionChanged()),this,SLOT(setDate()));
    connect(this,SIGNAL(dateChanged(QDate)),_a,SLOT(setDate(QDate)));
    connect(_a,SIGNAL(changeDockVisible(bool)),this,SLOT(changeDockVisible(bool)));
    connect(_addProgU,SIGNAL(triggered()),this,SLOT(showCreateProgU()));
    connect(_addProgA,SIGNAL(triggered()),this,SLOT(showCreateProgA()));
    connect(_progU,SIGNAL(accepted()),_a,SLOT(majEDT()));
    connect(_progA,SIGNAL(accepted()),_a,SLOT(majEDT()));
    connect(_saveData.first(),SIGNAL(triggered()),this,SLOT(saveProgWeekXML()));
    connect(_progA,SIGNAL(accepted()),this,SLOT(testAffichage()));
}

void Agenda::updateList()
{
    _list->clear();
    TacheManager::IteratorTypeT itType = dynamic_cast<TacheManager*>(TacheManager::getInstance())->getIteratorTypeT(UNITAIRE);
    QList<const Tache_Unitaire*> prog;
    //On récupère toutes les tâches des programmations de tâches
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
    //On parcours toutes les tâches unitaires (préemptives ou non) et on check si elles sont dans les tâches récupérées
    while(itType.courant() != itType.fin())
    {
        Tache_Unitaire* courant = dynamic_cast<Tache_Unitaire*>(itType.valeur());
        if(courant->precedencesFinies())
        {
            if(!prog.contains(courant) || courant->getType() == PREEMPTIVE)
            {
                QListWidgetItem* item = new QListWidgetItem(_list);
                item->setText(courant->getTitre());
                QVariant v;
                v.setValue(courant);
                item->setData(32,v);
                _list->addItem(item);
            }
        }
        itType.next();
    }
}

void Agenda::saveProgWeekXML(){
    //Récupération de la stratégie pour l'exportation
    progexport=new ProgrammationSemaineExport("XML",_a->getEDT()->getLundi(),_a->getEDT()->getDimanche(),new XMLExport("xml"));
    saveFile();
    QMessageBox::information(this,"Exportation de la semaine courante","Fichier XML exporté.",QMessageBox::Ok);
    delete progexport;
}

void Agenda::saveFile(){
    progexport->exportData();
}

void Agenda::saveProgProjetXML(Projet *p){
    progexport=new ProgrammationProjetExport(p,"XML",new XMLExport("xml"));
    saveFile();
    QMessageBox::information(this,"Exportation du projet "+p->getTitre(),"Fichier XML exporté",QMessageBox::Ok);
    delete progexport;
}
