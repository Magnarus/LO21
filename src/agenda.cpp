#include"../headers/agenda.h"

Agenda::Agenda(Accueil* a):_a(a)
{
    this->setCentralWidget(_a);
    this->setWindowState(Qt::WindowMaximized);

    _menuFichier = menuBar()->addMenu("&Fichier");
    _chargerFichier = new QAction("&Charger", this);
    _chargerFichier->setShortcut(QKeySequence("Ctrl+L"));
    _chargerFichier->setIcon(QIcon(":/res/charger.png"));
    _sauvegarderFichier = new QAction("&Sauvegarder",this);
    _sauvegarderFichier->setShortcut(QKeySequence("Ctrl+S"));
    _sauvegarderFichier->setIcon(QIcon(":/res/sauvegarder.png"));
    _menuFichier->addAction(_chargerFichier);
    _menuFichier->addAction(_sauvegarderFichier);

     QDockWidget* dock = new QDockWidget(QLatin1String("Last filters"),this);
     dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    _dockWidget = new QWidget();
    _sideLayout = new QVBoxLayout();
    _calendar = new QCalendarWidget();
    _calendar->setMinimumDate(QDate::currentDate());
    _calendar->selectedDate().dayOfWeek();
    _list = new QListWidget();
    QString label("Faudra ajouter les tâches non programmées qui peuvent l'être pour la semaine courante");
    _list->addItem(label);
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
    _toolbar->addAction(_sauvegarderFichier);
    _toolbar->addSeparator();
    _toolbar->addAction(_edtMode);
    _toolbar->addAction(_treeMode);
    _toolbar->addSeparator();
    _toolbar->addWidget(_programmer);

    _progU = new AddProgUnitaire();
    _progA = new AddProgActivite();
    connect(_edtMode, SIGNAL(triggered()), _a, SLOT(setPlanningOn()));
    connect(_treeMode,SIGNAL(triggered()), _a,SLOT(setTreeOn()));
    connect(_calendar,SIGNAL(selectionChanged()),this,SLOT(setDate()));
    connect(this,SIGNAL(dateChanged(QDate)),_a,SLOT(setDate(QDate)));
    connect(_a,SIGNAL(changeDockVisible(bool)),this,SLOT(changeDockVisible(bool)));
    connect(_addProgU,SIGNAL(triggered()),this,SLOT(showCreateProgU()));
    connect(_addProgA,SIGNAL(triggered()),this,SLOT(showCreateProgA()));
    connect(_progU,SIGNAL(progAdded()),_a,SLOT(majEDT()));
    connect(_progA,SIGNAL(progAdded()),_a,SLOT(majEDT()));
}

