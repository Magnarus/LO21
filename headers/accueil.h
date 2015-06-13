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
    QVBoxLayout* _mainLayout;
    EmploiDuTemps* _edtInterface;
    ProjectView *_projectTree;
public:
    explicit Accueil(QWidget *parent = 0);
    inline EmploiDuTemps* const& getEDT(){ return _edtInterface;}
    ~Accueil(){}

signals:
    void changeDockVisible(bool);
    void previentAgenda();
public slots:
    void setTreeOn()
    {
        _mainLayout->removeWidget(_edtInterface);
        _mainLayout->addWidget(_projectTree);
        _edtInterface->hide();
        _projectTree->show();
        emit changeDockVisible(false);
    }
    void setPlanningOn()
    {
        _mainLayout->removeWidget(_projectTree);
        _mainLayout->addWidget(_edtInterface);
        _projectTree->hide();
        _edtInterface->show();
        emit changeDockVisible(true);
    }
    void setDate(QDate d)
    {
        _edtInterface->setDate(d);
    }
    void majEDT()
    {

        _edtInterface->changerProg();
    }
    void prevenirAgenda(){
        emit previentAgenda();
    }
};

#endif // ACCUEIL_H
