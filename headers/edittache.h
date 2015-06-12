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
class EditTache : public Editeur
{
    Q_OBJECT
    Tache* tacheEdit;
    QLineEdit *_titre;
    QDateEdit *_dateDispo,*_dateEcheance;
    QTimeEdit *_duree;
    QFormLayout* _formLayout;
    QLabel *_type,*_precedences_l,*_possibles_l;
    QListWidget *_precedences, *_possibles;
    QPushButton *_ajouterPrec, *_retirerPrec;
    QHBoxLayout *_precLayout;
    QVBoxLayout *_precListLayout,*_possLayout,*_butPrecLayout,*_mainLayout;
public:
    EditTache(Tache* t=0,QWidget *parent=0);
    void setTache(Tache* t){tacheEdit = t;}
    virtual void initChamps();
public slots:
    void notifie();
    void ajouterListe();
    void retirerListe();
};

#endif // EDITTACHE_H
