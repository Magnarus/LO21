#ifndef AGENDA_H
#define AGENDA_H
#include<QMainWindow>
#include<QMenu>
#include<QMenuBar>
#include<QToolBar>
#include<QAction>
#include<qdockwidget>
#include "accueil.h"
#include<iostream>
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
    QVBoxLayout* _sideLayout;
    QWidget* _dockWidget;

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
};

#endif // AGENDA_H
