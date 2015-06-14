#ifndef ADDPROG_H
#define ADDPROG_H
#include<QDialog>
#include<QDateEdit>
#include<QTimeEdit>
#include<QButtonGroup>
#include<QRadioButton>
#include<QFormLayout>
#include<QVBoxLayout>
#include<QLineEdit>
#include<QPushButton>
/**
 * \class AddProg addprog.h "headers/addprog.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        08 juin 2015
 * \brief       Implémente la classe addprog
 *
 * \details    widget générique boite de dialogue qui permet de gérer la création
 * de programmations
 */
class AddProg: public QDialog
{
    Q_OBJECT
protected:
    QDateEdit * _date;/** modificateur de date */
    QTimeEdit *_horaire;/** modificateur d'horaires */
    QTimeEdit *_duree;/** modificateur de durée */
    QPushButton *_valider;/** bouton de validation */
    QPushButton *_annuler;/** bouton de rétractation */

    QFormLayout *_formLayout; /** layout du formulaire */
    QHBoxLayout *_buttonLayout;/** layout pour les boutons */
    QVBoxLayout * _mainLayout; /** layout principal */
public:
    /**
     * \brief       constructeur d'AddProg
     * param \e QWidget parent qui correspond au widget parent s'il y en a un
     */
    AddProg(QWidget* parent=0);
};

#endif // ADDPROG_H
