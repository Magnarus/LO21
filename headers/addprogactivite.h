#ifndef ADDPROGACTIVITE_H
#define ADDPROGACTIVITE_H
#include<QDateEdit>
#include<QMessageBox>
#include<QGroupBox>
#include"progmanager.h"
#include "addprog.h"
#include "activitemanager.h"
/**
 * \class AddProgActivite addprogactivite.h "headers/addprogactivite.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        08 juin 2015
 * \brief       Implémente la classe AddProgActivite
 *\extends AddProg
 * \details    widget boite de dialogue qui permet de gérer la création
 * de programmations d'activités.
 * Il sert à créer une activité en même temps,
 * vu qu'elles sont forcément liées à une programmation
 */
class AddProgActivite : public AddProg
{
    Q_OBJECT
    QLineEdit* _titreAct;
    QDateEdit* _dateAct;
    QTimeEdit* _dureeAct;
    QFormLayout* _activite;
    QGroupBox* _contour;
public:
    AddProgActivite(QWidget* parent=0);
public slots:
    void creation();
    void majDuree(QTime t){
        _dureeAct->setTime(t);
    }
    void majDate(QDate d){
        _dateAct->setDate(d);
    }
signals:
    void progAdded();
};
#endif // ADDPROGACTIVITE_H
