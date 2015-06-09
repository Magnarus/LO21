#include"../headers/Agenda.h"

Agenda::Agenda(Accueil* a):_a(a)
{
    this->setCentralWidget(_a);
    this->setWindowState(Qt::WindowMaximized);

    _menuFichier = menuBar()->addMenu("&Fichier");
    _chargerFichier = new QAction("&Charger", this);
    _chargerFichier->setShortcut(QKeySequence("Ctrl+L"));
    _sauvegarderFichier = new QAction("&Sauvegarder",this);
    _sauvegarderFichier->setShortcut(QKeySequence("Ctrl+S"));
    _menuFichier->addAction(_chargerFichier);
    _menuFichier->addAction(_sauvegarderFichier);


    _menuMode = menuBar()->addMenu("&Mode");
    _edtMode = new QAction("&Planning",this);
    _edtMode->setShortcut(QKeySequence("CTRL+P"));
    _treeMode = new QAction("&Gestion des projets",this);
    _treeMode->setShortcut(QKeySequence("CTRL+T"));
    _menuMode->addAction(_edtMode);
    _menuMode->addAction(_treeMode);

    connect(_edtMode, SIGNAL(triggered()), _a, SLOT(setPlanningOn()));
    connect(_treeMode,SIGNAL(triggered()), _a,SLOT(setTreeOn()));
}

