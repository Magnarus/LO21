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
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        08 juin 2015
 * \brief       Implémente la classe AddProgActivite
 * \extends AddProg
 * \details    widget boite de dialogue qui permet de gérer la création
 * de programmations de tâches unitaires.
 * Il sert à créer une activité en même temps,
 * vu qu'elles sont forcément liées à une programmation
 */
class AddProgUnitaire : public AddProg
{
    Q_OBJECT
    QListWidget *_taches;
public:
    AddProgUnitaire(QWidget* parent=0);
public slots:
    void creation();
    void majInfo(QListWidgetItem*selected);
signals:
    void progAdded();
};

#endif // ADDPROGUNITAIRE_H
