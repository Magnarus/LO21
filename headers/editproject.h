#ifndef EDITPROJECT_H
#define EDITPROJECT_H
#include "projet.h"
#include"editeur.h"
#include<QString>
#include<QListWidget>
#include <QFormLayout>
#include<QDateEdit>
#include<QLabel>
#include<QLineEdit>
#include<QDebug>
#include<QMessageBox>
/**
 * \class EditProject editproject.h "headers/editproject.h"
 * \author      DELAUNAY Grégory et NEVEUX Anais
 * \version     1.0
 * \date        08 juin 2015
 * \brief       Implémente la classe EditProject
 * \details    Ce widget sert à éditer les projets déjà existant.
 */
class EditProject : public Editeur
{
    Q_OBJECT
    Projet* projetEdit; /** projet en cours d'édition */
    QListWidget* _taches; /** taches liées au projet */
    QLineEdit *_titre; /** modificateur de titre */
    QDateEdit *_dateDispo; /** modificateur de date de disponibilité */
    QDateEdit *_dateEcheance; /** modificateur d'échéance */
    QVBoxLayout *_mainLayout; /** layout principal */
    QVBoxLayout * _tachesLayout; /** layout pour la liste de tâches */
    QFormLayout* _formLayout; /** layout du formulaire */
    QLabel* _taches_l; /** label pour rensienger le role de la liste de tâches */
public:
    /**
     * \brief EditProject constructeur
     * \param p projet à modifier
     * \param parent s'il y en a un
     */
    EditProject(Projet* p=0, QWidget* parent=0);

    /**
     * \brief setProjet change le projet à éditer
     * \param p nouveau projet
     */
    void setProjet(Projet* p){projetEdit=p; initChamps();}

    /**
     * \brief initChamps initialise les champs d'éditions avec les paramètres du projet donné
     */
    virtual void initChamps();
public slots:
    /**
     * \brief notifie que le projet a fini d'être modifié
     */
    void notifie();
};

#endif // EDITPROJECT_H
