#ifndef AGENDA_H
#define AGENDA_H
#include<QMainWindow>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include "accueil.h"
class Agenda : public QMainWindow
{
    Q_OBJECT
    Accueil* _a;
    QMenu* _menuFichier;
    QMenu* _menuMode;
    QAction* _chargerFichier;
    QAction* _sauvegarderFichier;
    QAction* _edtMode;
    QAction* _treeMode;

public :
    Agenda(Accueil* a);
};

#endif // AGENDA_H
