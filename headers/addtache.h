#ifndef ADDTACHE_H
#define ADDTACHE_H

#include <QWidget>
#include<QDateEdit>
#include<QString>
#include<QCheckBox>
#include<QLineEdit>
#include<QLabel>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QPushButton>
#include<QString>
#include<QListWidget>
class AddTache : public QWidget
{
    Q_OBJECT
    QDateEdit *_dateDispo,*_dateEcheance;
    QLineEdit *_titre;
    QListWidget *_idTaches;
    QCheckBox *_preemptive,*_unitaire;
    QPushButton *_ajouter,*_annuler;
    QLabel *_dateDispo_l,*_dateEcheance_l,*_titre_l,*_idTaches_l,*_preemptive_l,*_unitaire_l;
    QVBoxLayout *_vlayout,*_tachesLayout;
    QHBoxLayout *_titreLayout,*_datesLayout,*_buttonLayout;

public:
    explicit AddTache(QWidget *parent = 0);
    virtual ~AddTache();
protected:
    void setAjouterTitle(const QString& title){ _ajouter->setText(title);}
signals:

public slots:
    void switchingTache(bool b){
        _idTaches->setEnabled(!b);
        _preemptive->setEnabled(b);
        //Ajouter la partie duree
    }
};

#endif // ADDTACHE_H
