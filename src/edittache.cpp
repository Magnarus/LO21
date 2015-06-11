#include "../headers/edittache.h"
EditTache::EditTache(Tache *t, QWidget *parent):Editeur(parent),tacheEdit(t)
{
    _titre = new QLineEdit(this);
    _dateDispo = new QDateEdit(this);
    _dateEcheance = new QDateEdit(this);
    _type = new QLabel("default",this);
    _preemptive = new QLabel("oui",this);
    _precedences_l = new QLabel("Précédences : ",this);
    _possibles_l = new QLabel("Précédences possibles : ",this);
    _precedences = new QListWidget(this);
    _possibles = new QListWidget(this);
    _ajouterPrec = new QPushButton("<- Ajouter ",this);
    _retirerPrec = new QPushButton("Retirer ->",this);

    _formLayout = new QFormLayout;
    _formLayout->addRow("Titre : ",_titre);
    _formLayout->addRow("Date Dispo : ",_dateDispo);
    _formLayout->addRow("Date Echéance : ",_dateEcheance);
    _formLayout->addRow("Type : ",_type);
    _formLayout->addRow("Préemptive ? : ",_preemptive);

    _precListLayout = new QVBoxLayout;
    _precListLayout->addWidget(_precedences_l);
    _precListLayout->addWidget(_precedences);

    _possLayout = new QVBoxLayout;
    _possLayout->addWidget(_possibles_l);
    _possLayout->addWidget(_possibles);

    _butPrecLayout = new QVBoxLayout;
    _butPrecLayout->addWidget(_ajouterPrec);
    _butPrecLayout->addWidget(_retirerPrec);
    _butPrecLayout->setAlignment(Qt::AlignVCenter);

    _precLayout = new QHBoxLayout;
    _precLayout->addLayout(_precListLayout);
    _precLayout->addLayout(_butPrecLayout);
    _precLayout->addLayout(_possLayout);

    _mainLayout = new QVBoxLayout(this);
    _mainLayout->addLayout(_formLayout);
    _mainLayout->addLayout(_precLayout);
    _mainLayout->addLayout(_buttonLayout);

}
