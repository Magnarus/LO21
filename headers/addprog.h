#ifndef ADDPROG_H
#define ADDPROG_H
#include<QDialog>
#include<QDateEdit>
#include<QTimeEdit>
#include<QButtonGroup>
#include<QRadioButton>
#include<QFormLayout>
#include<QVBoxLayout>
#include<QLineEdit>
#include<QPushButton>
class AddProg: public QDialog
{
    Q_OBJECT
protected:
    QDateEdit * _date;
    QTimeEdit *_horaire, *_duree;
    QPushButton *_valider, *_annuler;

    QFormLayout *_formLayout;
    QHBoxLayout *_buttonLayout;
    QVBoxLayout * _mainLayout;
public:
    AddProg(QWidget* parent=0);
};

#endif // ADDPROG_H
