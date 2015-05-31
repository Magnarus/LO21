#ifndef TACHE_H
#define TACHE_H
#include<QString>
#include<QList>
#include<QDate>
#include<QTime>
#include<iostream>
class Tache
{
protected:
    int id;
    QString titre;
    QList<Tache*> precedence;
    QDate dateDispo;
    QDate dateEcheance;

    bool estPredecence(int id);
public:
    Tache(const int id, const QString& titre, const QDate&
          dispo, const QDate& deadline)
         :id(id),titre(titre),dateDispo(dispo),dateEcheance(deadline)
    {}
    inline int getId()const { return id;}
    inline QString getTitre()const {return titre;}
    inline QDate getDateDispo()const {return dateDispo;}
    inline QDate getEcheance()const {return dateEcheance;}

    inline void setTitre(QString& t){titre=t;}
    inline void setDateDispo(QDate& d){dateDispo =d;}
    inline void setEcheance(QDate& d){dateEcheance=d;}

    Tache* getPrecedence(int id);
    void ajouterPrecedence(Tache* pred);
    virtual void afficher()const = 0;
};

#endif // TACHE_H