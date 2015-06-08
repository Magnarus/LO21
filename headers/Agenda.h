#ifndef AGENDA_H
#define AGENDA_H
#include<QMainWindow>
#include "accueil.h"
class Agenda : public QMainWindow
{
    Accueil* a;
public :
    Agenda(Accueil* a):a(a)
    {
        this->setCentralWidget(a);
        this->setWindowState(Qt::WindowMaximized);
    }
};

#endif // AGENDA_H
