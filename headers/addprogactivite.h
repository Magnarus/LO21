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
 * \details    widget boite de dialogue qui permet de gérer la création
 * de programmations d'activités.
 * Il sert à créer une activité en même temps,
 * vu qu'elles sont forcément liées à une programmation
 */
class AddProgActivite : public AddProg
{
    Q_OBJECT
    QLineEdit* _titreAct;/** modificateur de titre */
    QDateEdit* _dateAct;/** modificateur de date */
    QTimeEdit* _dureeAct;/** modificateur de durée */
    QFormLayout* _activite;/** layout du formulaire */
    QGroupBox* _contour;/** layout pour le design */
public:
    /**
     * \brief constructeur AddProgActivite
     * \param parent s'il y en a un
     */
    AddProgActivite(QWidget* parent=0);
public slots:
    /**
     * \brief creation qui créé l'activité et sa programmation associée.
     */
    void creation();
    /**
     * \brief majDuree met à jour la durée
     * \param t nouvelle durée
     */
    void majDuree(QTime t){
        _dureeAct->setTime(t);
    }
    /**
     * \brief majDate met à jour la date
     * \param d nouvelle date
     */
    void majDate(QDate d){
        _dateAct->setDate(d);
    }
signals:
    /**
     * \brief signal pour la fin d'ajout.
     */
    void progAdded();
};
#endif // ADDPROGACTIVITE_H
