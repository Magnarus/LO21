#ifndef EDITTACHE_H
#define EDITTACHE_H
#include "tache.h"
#include "editeur.h"
#include "projet.h"
#include "projetmanager.h"
#include <QString>
#include<QFormLayout>
#include<QLineEdit>
#include<QDateEdit>
#include<QLabel>
#include<QListWidget>
#include<QDebug>
class EditTache : public Editeur
{
    Tache* tacheEdit;
    QLineEdit *_titre;
    QDateEdit *_dateDispo,*_dateEcheance;
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
};

#endif // EDITTACHE_H
