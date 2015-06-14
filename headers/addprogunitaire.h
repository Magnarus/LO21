#ifndef ADDPROGUNITAIRE_H
#define ADDPROGUNITAIRE_H
#include "addprog.h"
#include "tachemanager.h"
#include "programmation.h"
#include "progTUnit.h"
#include "progmanager.h"
#include "math.h"
#include <QListWidget>
#include<QMessageBox>
#include<QDebug>
/**
 * \class AddProgUnitaire addprogunitaire.h "headers/addprogunitaire.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        08 juin 2015
 * \brief       Implémente la classe AddProgActivite
 * \details    widget boite de dialogue qui permet de gérer la création
 * de programmations de tâches unitaires.
 * Il sert à créer une activité en même temps,
 * vu qu'elles sont forcément liées à une programmation
 */
class AddProgUnitaire : public AddProg
{
    Q_OBJECT
    QListWidget *_taches;/** listes des tâches programmables */
public:
    /**
     * \brief constructeur AddProgUnitaire
     * \param parent s'il y en a un
     */
    AddProgUnitaire(QWidget* parent=0);
public slots:
    /**
     * \brief creation gère la création de la programmation associée à la tâche
     */
    void creation();
    /**
     * \brief majInfo met à jour les champs d'éditions pour correspondre avec la tâche choisie
     * \param selected qui correspond à la tâche choisie.
     */
    void majInfo(QListWidgetItem*selected);
signals:
    /**
     * \brief progAdded signal de fin d'ajout
     */
    void progAdded();
};

#endif // ADDPROGUNITAIRE_H
