#ifndef ADDPROGUNITAIRE_H
#define ADDPROGUNITAIRE_H
#include "addprog.h"
#include "tachemanager.h"
#include "programmation.h"
#include "progTUnit.h"
#include "progmanager.h"
#include "math.h"
#include <QListWidget>
#include<QMessageBox>
#include<QDebug>
class AddProgUnitaire : public AddProg
{
    Q_OBJECT
    QListWidget *_taches;
public:
    AddProgUnitaire(QWidget* parent=0);
public slots:
    void creation();
    void majInfo(QListWidgetItem*selected);
signals:
    void progAdded();
};

#endif // ADDPROGUNITAIRE_H
