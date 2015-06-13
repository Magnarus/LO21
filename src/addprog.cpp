#include"../headers/addprog.h"

AddProg::AddProg(QWidget* parent):QDialog(parent)
{
    _titre = new QLineEdit(this);
    _date = new QDateEdit(this);
    _date->setMinimumDate(QDate::currentDate());
    _date->setCalendarPopup(true);
    _horaire = new QTimeEdit(this);
    _duree = new QTimeEdit(this);
    _duree->stepBy(1);
    _valider = new QPushButton("valider",this);
    _annuler = new QPushButton("annuler",this);

    _formLayout = new QFormLayout;
    _formLayout->addRow("Titre : ",_titre);
    _formLayout->addRow("Date : ", _date);
    _formLayout->addRow("Heure : ",_horaire);
    _formLayout->addRow("Duree : ",_duree);

    _buttonLayout = new QHBoxLayout;
    _buttonLayout->addWidget(_valider);
    _buttonLayout->addWidget(_annuler);

    _mainLayout = new QVBoxLayout(this);
    _mainLayout->addLayout(_formLayout);
}
