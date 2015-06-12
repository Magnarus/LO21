#ifndef ADDPROGUNITAIRE_H
#define ADDPROGUNITAIRE_H
#include "addprog.h"
#include "tachemanager.h"
#include "programmation.h"
#include "progTUnit.h"
#include "progmanager.h"
#include <QListWidget>
class AddProgUnitaire : public AddProg
{
    QListWidget *_taches;
public:
    AddProgUnitaire(QWidget* parent=0);
};

#endif // ADDPROGUNITAIRE_H
