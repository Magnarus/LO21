#ifndef EDITTACHE_H
#define EDITTACHE_H
#include "editeur.h"
#include "projet.h"
#include "projetmanager.h"
#include "tache_unitaire.h"
#include "tache_composite.h"
#include <QString>
#include<QFormLayout>
#include<QLineEdit>
#include<QDateEdit>
#include<QLabel>
#include<QListWidget>
#include<QDebug>
#include<QMessageBox>
/**
 * \class EditTache EditTache.h "headers/edittache.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        08 juin 2015
 * \brief       Implémente la classe EditTache
 * \details    Ce widget sert à éditer les taches déjà existantes.
 */
class EditTache : public Editeur
{
    Q_OBJECT
    Tache* tacheEdit; /** tâche à modifier */
    QLineEdit *_titre; /** modificateur de titre */
    QDateEdit *_dateDispo; /** modificateur de date de disponibilité */
    QDateEdit *_dateEcheance; /** modificateur de date d'échéance */
    QTimeEdit *_duree; /** modificateur de durée */
    QFormLayout* _formLayout; /** layout de mise en forme du formulaire */
    QLabel *_type; /** label pour renseigner le type de la tâche */
    QLabel *_precedences_l; /** label pour renseigner sur le role de la liste de gauche */
    QLabel *_possibles_l; /** label pour renseigner sur le role de la liste de droite */
    QListWidget *_precedences; /** liste des précédences actuelles de la tâche */
    QListWidget *_possibles; /** liste des précédences possible pour la tâche */
    QPushButton *_ajouterPrec; /** bouton qui ajoute des taches possibles dans la liste de précédences */
    QPushButton *_retirerPrec; /** bouton qui retire une précédence de la liste */
    QHBoxLayout *_precLayout; /** layout pour les précédences */
    QVBoxLayout *_precListLayout; /** layout pour la liste de précédences*/
    QVBoxLayout *_possLayout; /** layout pour les précédences possibles */
    QVBoxLayout *_butPrecLayout; /** layout qui regroupe les listes et les boutons liés à la précédence */
    QVBoxLayout *_mainLayout; /** layout principal*/
public:
    /**
     * \brief EditTache constructeur
     * \param t tâche à éditer
     * \param parent s'il y en a un
     */
    EditTache(Tache* t=0,QWidget *parent=0);

    /**
     * \brief setTache change la tâche à modifier
     * \param t nouvelle tâche
     */
    void setTache(Tache* t){tacheEdit = t;initChamps();}
    /**
     * \brief initChamps initialise les champs d'édition avec les paramètres de la tâche
     */
    virtual void initChamps();
public slots:
    /**
     * \brief notifie la fin d'édition de la tâche
     */
    void notifie();

    /**
     * \brief ajouterListe ajoute aux précédences et retire aux possibles
     * \details cette fonction ne fait que modifier le widget, la tâche ne voit ses précédences modifiées
     * qu'au moment de la validation de l'édition
     */
    void ajouterListe();

    /**
     * \brief retirerListe retire des précédences et ajoute au possibles
     * \details cette fonction ne fait que modifier le widget, la tâche ne voit ses précédences modifiées
     * qu'au moment de la validation de l'édition
     */
    void retirerListe();
};

#endif // EDITTACHE_H
