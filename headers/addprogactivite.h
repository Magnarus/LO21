#ifndef ADDPROGACTIVITE_H
#define ADDPROGACTIVITE_H
#include<QDateEdit>
#include "addprog.h"
class AddProgActivite : public AddProg
{
    Q_OBJECT
    QDateEdit* _dateAct;
    QTimeEdit* _dureeAct;
    QLineEdit* _titreAct;
    QFormLayout* _activite;
public:
    AddProgActivite(QWidget* parent=0);
public slots:
    void creation();
    void majInfo(QListWidgetItem*selected);
};
#endif // ADDPROGACTIVITE_H
