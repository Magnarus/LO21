#include "../headers/editeur.h"
Editeur::Editeur(QWidget *parent):QWidget(parent)
{
    _valider = new QPushButton("Valider");
    _buttonLayout = new QHBoxLayout;
    _buttonLayout->addWidget(_valider);
}
