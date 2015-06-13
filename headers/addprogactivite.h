#ifndef ADDPROGACTIVITE_H
#define ADDPROGACTIVITE_H
#include<QDateEdit>
#include<QMessageBox>
#include<QGroupBox>
#include"progmanager.h"
#include "addprog.h"
#include "activitemanager.h"
class AddProgActivite : public AddProg
{
    Q_OBJECT
    QLineEdit* _titreAct;
    QDateEdit* _dateAct;
    QTimeEdit* _dureeAct;
    QFormLayout* _activite;
    QGroupBox* _contour;
public:
    AddProgActivite(QWidget* parent=0);
public slots:
    void creation();
    void majDuree(QTime t){
        _dureeAct->setTime(t);
    }
    void majDate(QDate d){
        _dateAct->setDate(d);
    }
signals:
    void progAdded();
};
#endif // ADDPROGACTIVITE_H
