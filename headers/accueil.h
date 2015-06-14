#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QWidget>
#include <QMainWindow>
#include <QComboBox>
#include <QVBoxLayout>
#include "emploidutemps.h"
#include "projectview.h"
/**
 * \class Accueil accueil.h "headers/accueil.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        08 juin 2015
 * \brief       Implémente la classe accueil
 *
 * \details    Cette classe est le widget qui constitue le widget principal de l'application
 * il permet d'alterner entre le calendrier qui permet de gérer les programmations
 * et la treeview qui gère les projets et la dépendance avec les tâches
 */
class Accueil : public QWidget
{
    Q_OBJECT
    QVBoxLayout* _mainLayout;/** Layout pour les widgets */
    EmploiDuTemps* _edtInterface;/** emploi du temps de l'application avec planning */
    ProjectView *_projectTree;/** Arborescence des projets avec outils d'éditions et d'ajouts */
public:
    /**
     * \brief      Constructeur de Accueil
     * \param    parent         définit le widget mère s'il y en a un.
     */
    explicit Accueil(QWidget *parent = 0);
    /**
     * \brief       accesseur dur l'emploi du temps
     * \return      un \e EmploiDuTemps.
     */
    inline EmploiDuTemps* const& getEDT(){ return _edtInterface;}
    ~Accueil(){}

signals:
    /**
     * \brief       signal qui permet de signaler un changement d'affichage sur les dockWidgets.
     */
    void changeDockVisible(bool);
    /**
     * \brief       signal qui permet de signaler que de nouvelles tâches sont créées.
     * Sert d'intermédiaire entre le treewidget et l'agenda.
     */
    void previentAgenda();
public slots:
    /**
     * \brief       Slot qui sert à définir l'affichage comme étant celui de l'interface du treewidget.
     */
    void setTreeOn()
    {
        _mainLayout->removeWidget(_edtInterface);
        _mainLayout->addWidget(_projectTree);
        _edtInterface->hide();
        _projectTree->show();
        emit changeDockVisible(false);
    }
    /**
     * \brief       Slot qui sert à définir l'affichage comme étant celui de l'interface du planning.
     */
    void setPlanningOn()
    {
        _mainLayout->removeWidget(_projectTree);
        _mainLayout->addWidget(_edtInterface);
        _projectTree->hide();
        _edtInterface->show();
        emit changeDockVisible(true);
    }
    /**
     * \brief       Slot qui sert à définir la date courante du planning.
     * \param d qui correspond à la nouvelle date
     */
    void setDate(QDate d)
    {
        _edtInterface->setDate(d);
    }
    /**
     * \brief       Slot qui sert à mettre à jour les programmations affichées.
     *
     */
    void majEDT()
    {

        _edtInterface->changerProg();
    }
    /**
     * \brief       Slot qui prévient l'agenda des changements.
     *
     */
    void prevenirAgenda(){
        emit previentAgenda();
    }
};

#endif // ACCUEIL_H
