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
#include"MethodExport.h"
#include"ProgrammationExport.h"
#include"XMLExport.h"
#include"SimpleFileExport.h"
#include"ProgrammationSemaineExport.h"
#include"ProgrammationProjetExport.h"
#include<QMessageBox>
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
    QMenu* _sauvegarderFichier;
    QVector<QMenu*>  _saveOptions;
    QVector<QAction*> _saveData;
    //QAction* _sauvegarderFichier;
    QAction* _edtMode;
    QAction* _treeMode;
    QAction* _addProgU;
    QAction* _addProgA;
    QToolButton* _programmer;
    QVBoxLayout* _sideLayout;
    QWidget* _dockWidget;
    AddProgUnitaire* _progU;
    AddProgActivite* _progA;
    ProgrammationExport* progexport;
public :
    Agenda(Accueil* a);
    void saveFile();
signals :
    void dateChanged(QDate);
public slots:
    void setDate(){
        QDate d = _calendar->selectedDate();
        emit dateChanged(d);
    }
    void changeDockVisible(bool b){
        _dockWidget->setVisible(b);
    }
    void showCreateProgU(){
       _progU=new AddProgUnitaire();
       //_progU->exec();
       if(_progU->exec()==QDialog::Accepted){
           _a->majEDT();
       }
    }
    void showCreateProgA(){
       _progA=new AddProgActivite();
       //_progA->exec();
        if(_progA->exec()==QDialog::Accepted){
            _a->majEDT();
        }
    }
    void updateList();
    void saveProgWeekXML();
    void saveProgProjetXML(Projet* p);
    void testAffichage(){ qDebug() << "test";}
};

#endif // AGENDA_H
