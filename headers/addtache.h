#ifndef ADDTACHE_H
#define ADDTACHE_H

#include <QWidget>
#include<QDateEdit>
#include<QTimeEdit>
#include<QString>
#include<QCheckBox>
#include<QLineEdit>
#include<QLabel>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QPushButton>
#include<QString>
#include<QListWidget>
#include<QMessageBox>
#include<QListWidget>
#include "tachemanager.h"
class AddTache : public QDialog
{
    Q_OBJECT
protected:
    QDateEdit *_dateDispo,*_dateEcheance;
    QTimeEdit * _duree;
    QLineEdit *_titre;
    QCheckBox *_preemptive,*_unitaire;
    QPushButton *_ajouter,*_annuler;
    QLabel *_dateDispo_l,*_dateEcheance_l,*_duree_l,*_titre_l,*_preemptive_l,*_unitaire_l;
    QVBoxLayout *_vlayout,*_datetimeLayout,_projetLayout,_mereLayout;
    QHBoxLayout *_titreLayout,*_datesLayout,*_timeLayout,*_buttonLayout;
    void setAjouterTitle(const QString& title){ _ajouter->setText(title);}
public:
    explicit AddTache(QWidget *parent = 0);
    virtual ~AddTache(){}
protected:
signals:
    void tacheAjoutee(int id);
public slots:
    void switchingTache(bool b){
        _preemptive->setEnabled(b);
        _duree->setEnabled(b);
    }
    void newTache();
};

#endif // ADDTACHE_H
