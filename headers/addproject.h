#ifndef ADDPROJECT_H
#define ADDPROJECT_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include<QMap>
#include "projetmanager.h"
#include<QMessageBox>
class AddProject : public QWidget
{
    Q_OBJECT
    QLabel *_titre_l,*_dateDispo_l,*_dateEcheance_l;
    QLineEdit *_titre;
    QDateEdit *_dateDispo,*_dateEcheance;
    QPushButton *_ajouter,*_annuler;
    QVBoxLayout *_vlayout;
    QHBoxLayout *_titreLayout,*_datesLayout,*_buttonsLayout;
public:
    explicit AddProject(QWidget *parent = 0);
    virtual ~AddProject(){}
protected:
    void setAjouterTitle(const QString& title){ _ajouter->setText(title);}

public slots:
    void newProject();
};

#endif // ADDPROJECT_H
