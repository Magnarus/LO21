#include "../headers/addprogactivite.h"

AddProgActivite::AddProgActivite(QWidget *parent):AddProg(parent)
{
    setWindowTitle("Ajout d'une programmation d'activite");
    _activite = new QFormLayout;
    _dateAct = new QDateEdit(this);
    _dureeAct = new QTimeEdit(this);
    _titreAct = new QLineEdit(this);
}
