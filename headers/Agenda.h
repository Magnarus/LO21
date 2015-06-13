#ifndef AGENDA_H
#define AGENDA_H
#include<QMainWindow>
#include<QMenu>
#include<QMenuBar>
#include<QToolBar>
#include<QAction>
#include<QDockWidget>
#include<QToolButton>
#include "accueil.h"
#include<iostream>
#include"addprogunitaire.h"
#include"addprogactivite.h"
class Agenda : public QMainWindow
{
    Q_OBJECT
    Accueil* _a;
    QMenu* _menuFichier;
    QMenu* _menuMode;
    QCalendarWidget* _calendar;
    QListWidget* _list;
    QToolBar* _toolbar;
    QAction* _chargerFichier;
    QAction* _sauvegarderFichier;
    QAction* _edtMode;
    QAction* _treeMode;
    QAction* _addProgU;
    QAction* _addProgA;
    QToolButton* _programmer;
    QVBoxLayout* _sideLayout;
    QWidget* _dockWidget;
    AddProgUnitaire* _progU;
    AddProgActivite* _progA;

public :
    Agenda(Accueil* a);
signals :
    void dateChanged(QDate);
public slots:
    void setDate(){
        std::cout << "coucou hibou \n";
        QDate d = _calendar->selectedDate();
        emit dateChanged(d);
    }
    void changeDockVisible(){
        if (_dockWidget->isVisible())
            _dockWidget->setVisible(false);
        else _dockWidget->setVisible(true);
    }
    void showCreateProgU(){
       _progU=new AddProgUnitaire();
       _progU->exec();
    }
    void showCreateProgA(){
       _progA=new AddProgActivite();
       _progA->exec();
    }
};

#endif // AGENDA_H
