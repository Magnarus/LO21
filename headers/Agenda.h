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
/**
 * \class Agenda agenda.h "headers/agenda.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        08 juin 2015
 * \brief       Implémente la classe Agenda
 * \details    Ce widget est la fenêtre principale de l'application.
 * C'est ici que s'articulent toutes les différentes interactions avec
 * l'utilisateur.
 */
class Agenda : public QMainWindow
{
    Q_OBJECT
    Accueil* _a; /** widget principal de la fenêtre */
    QMenu* _menuFichier; /** menu pour gérer l'import/export */
    QMenu* _menuMode; /** menu pour switcher planning/arborescence*/
    QCalendarWidget* _calendar; /** Calendrier*/
    QListWidget* _list; /** liste des tâches programées sur la semaine voulue */
    QToolBar* _toolbar; /** barre d'outil avec raccourcis */
    QAction* _chargerFichier; /** Action d'import de fichier XML */
    QMenu* _sauvegarderFichier; /** Action d'export de fichier XML */
    QVector<QMenu*>  _saveOptions; /** différents moyen d'export */
    QVector<QAction*> _saveData;
    QAction* _edtMode; /** Action pour aller vers le planning */
    QAction* _treeMode; /** Action pour aller vers l'arborescence */
    QAction* _addProgU; /** Action pour créer une programmation sur une tâche */
    QAction* _addProgA; /** Action pour créer une programmation sur une activité */
    QToolButton* _programmer; /** Bouton qui regroupe les actions de programmation */
    QVBoxLayout* _sideLayout;/** Layout pour les widgets placés dans le dockWidget*/
    QWidget* _dockWidget; /** Widget à placer dans le dockwidget pour pouvoir le déplacer */
    AddProgUnitaire* _progU; /** Fenêtre qui gère l'ajout de programmation de tâches unitaires */
    AddProgActivite* _progA; /** Fenêtre qui gère l'ajout de programmation d'activité */
    ProgrammationExport* progexport; /** gère l'export des données */
public :
    /**
     * \brief constructeur Agenda
     * \param a accueil à placer en widget principal
     */
    Agenda(Accueil* a);
    /**
     * \brief saveFile gère l'export des données.
     */
    void saveFile();
signals :
    /**
     * \brief dateChanged signale que la date sélectionnée a été modifiée
     */
    void dateChanged(QDate);
public slots:
    /**
     * `\brief setDate slot qui récupère la nouvelle date et la répercute sur le reste de l'application
     */
    void setDate(){
        QDate d = _calendar->selectedDate();
        emit dateChanged(d);
    }

    /**
     * \brief changeDockVisible change l'état du widget placé dans le dock
     * \param b vrai si visible, faux sinon.
     */
    void changeDockVisible(bool b){
        _dockWidget->setVisible(b);
    }

    /**
     * \brief showCreateProgU ouvre la fenêtre de programmation de tâche unitaire
     */
    void showCreateProgU(){
       _progU=new AddProgUnitaire();
       _progU->exec();
    }

    /**
     * \brief showCreateProgA ouvre la fenêtre de programmation d'activité
     */
    void showCreateProgA(){
       _progA=new AddProgActivite();
       _progA->exec();
    }

    /**
     * \brief updateList met à jour la liste des tâches programmées
     */
    void updateList();

    /**
     * \brief saveProgWeekXML lance l'export de la semaine
     */
    void saveProgWeekXML();

    /**
     * \brief saveProgProjetXML lance l'export d'un projet voulu
     * \param p projet à sauvegarder.
     */
    void saveProgProjetXML(Projet* p);
};

#endif // AGENDA_H
