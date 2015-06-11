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
class EditProject : public Editeur
{
    Q_OBJECT
    Projet* projetEdit;
    QListWidget* _taches;
    QLineEdit *_titre;
    QDateEdit *_dateDispo,*_dateEcheance;
    QVBoxLayout *_mainLayout,* _tachesLayout;
    QFormLayout* _formLayout;
    QLabel* _taches_l;
public:
    EditProject(Projet* p=0, QWidget* parent=0);
    void setProjet(Projet* p){projetEdit=p;}
    virtual void initChamps();
public slots:
    void notifie();
};

#endif // EDITPROJECT_H
