#ifndef ADDPROJECT_H
#define ADDPROJECT_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include<QMap>
#include "projetmanager.h"
#include<QMessageBox>
/**
 * \class AddProject addproject.h "headers/addproject.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        08 juin 2015
 * \brief       Implémente la classe AddProject
 * \details    widget boite de dialogue qui permet de gérer la création
 * de projets.
 */
class AddProject : public QDialog
{
    Q_OBJECT
protected:
    QLabel *_titre_l; /** label pour le titre*/
    QLabel*_dateDispo_l; /** label pour la date dispo*/
    QLabel *_dateEcheance_l;/** label pour la date d'échéance*/
    QLineEdit *_titre; /** modificateur de titre*/
    QDateEdit *_dateDispo;/** modificateur de dateDispo*/
    QDateEdit *_dateEcheance;/** modificateur de dateEcheance*/
    QPushButton *_ajouter;/** bouton de validation*/
    QPushButton*_annuler;/** bouton de retractation */
    QVBoxLayout *_vlayout;/** layout principal*/
    QHBoxLayout *_titreLayout; /** layout pour le titre*/
    QHBoxLayout *_datesLayout; /** layout pour les dates */
    QHBoxLayout *_buttonsLayout; /** layout pour les boutons */
    /**
     * \brief setAjouterTitle modifie le titre du bouton
     * \param title nouveau titre
     */
    void setAjouterTitle(const QString& title){ _ajouter->setText(title);}

public:
    /**
     * \brief constructeur AddProject
     * \param parent s'il y en a un
     */
    explicit AddProject(QWidget *parent = 0);
    /**
     * \brief destructeur ~AddProject
     */
    virtual ~AddProject(){}
protected:

public slots:
    /**
     * \brief newProject qui crée un projet.
     */
    void newProject();
};

#endif // ADDPROJECT_H
