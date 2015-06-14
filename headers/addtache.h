#ifndef ADDTACHE_H
#define ADDTACHE_H

#include <QWidget>
#include<QDateEdit>
#include<QTimeEdit>
#include<QString>
#include<QCheckBox>
#include<QLineEdit>
#include<QLabel>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QPushButton>
#include<QString>
#include<QListWidget>
#include<QMessageBox>
#include<QListWidget>
#include "tachemanager.h"
/**
 * \class AddTache addtache.h "headers/addtache.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        08 juin 2015
 * \brief       Implémente la classe AddTache
 * \details    widget boite de dialogue qui permet de gérer la création
 * de tache.
 */
class AddTache : public QDialog
{
    Q_OBJECT
protected:
    QDateEdit *_dateDispo; /** modificateur de datedispo*/
    QDateEdit *_dateEcheance; /** modificateur de dateecheance*/
    QTimeEdit * _duree; /** modificateur de durée*/
    QLineEdit *_titre; /** modificateur de titre */
    QCheckBox *_preemptive;  /** vérificateur de préemptivité*/
    QCheckBox *_unitaire; /** vérificateur pour le caractère unitaire de la tâche */
    QPushButton *_ajouter; /** bouton de validation */
    QPushButton *_annuler; /** bouton de retractation */
    QLabel *_dateDispo_l; /** indicateur pour datedispo*/
    QLabel*_dateEcheance_l;/** indicateur pour dateecheance*/
    QLabel*_duree_l; /** indicateur pour durée */
    QLabel*_titre_l; /** indicateur pour titre*/
    QLabel*_preemptive_l;/** indicateur pour preemptivité*/
    QLabel*_unitaire_l; /** indicateur pour la checkbox sur unitaire ou non */
    QVBoxLayout *_vlayout; /** layout principal */
    QVBoxLayout *_datetimeLayout; /** layout sur la durée et la date */
    QHBoxLayout *_titreLayout; /** layout sur les titres */
    QHBoxLayout*_datesLayout; /** layout sur les dates*/
    QHBoxLayout*_timeLayout; /** layout sur les durées */
    QHBoxLayout*_buttonLayout; /** layout sur les boutons */

    /**
     * \brief setAjouterTitle modifie le titre du bouton de validation
     * \param title nouveau nom du bouton
     */
    void setAjouterTitle(const QString& title){ _ajouter->setText(title);}
public:
    /**
     * \brief AddTache constructeur
     * \param parent s'il y en a un
     */
    explicit AddTache(QWidget *parent = 0);

    /**
     * \brief getTitre
     * Permet de récupérer le titre que l'on souhaite donner à une tâche
     * \return Le contenu du champ titre.
     */
    inline const QString& getTitre()const{ return _titre->text();}

    /**
     * \brief ~AddTache destructeur
     */
    virtual ~AddTache(){}
protected:
signals:
    /**
     * \brief tacheAjoutee signal de fin de création
     * \param id id de la nouvelle tâche
     */
    void tacheAjoutee(int id);
public slots:
    /**
     * \brief switchingTache change les widget activés selon le caractère unitaire de la tâche.
     * \param b vrai si unitaire, faux sinon.
     */
    void switchingTache(bool b){
        _preemptive->setEnabled(b);
        _duree->setEnabled(b);
    }
    /**
     * \brief newTache gère la création de la tâche en fonction des valeurs des widgets de la fenêtre.
     */
    void newTache();
};

#endif // ADDTACHE_H
