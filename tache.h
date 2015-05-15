#ifndef TACHE_H
#define TACHE_H
#include<QString>
#include<vector>
#include<QDate>
#include<QTime>
#include<iostream>
class Tache
{
protected:
    int id;
    QString titre;
    std::vector<Tache*> precedence;
    QDate dateDispo;
    QDate dateEcheance;
    QTime duree;

    bool estPredecence(int id);
public:
    Tache(const int id, const QString& titre, const QDate&
          dispo, const QDate& deadline, const QTime& dur)
         :id(id),titre(titre),dateDispo(dispo),dateEcheance(deadline),duree(dur)
    {}
    inline int getId()const { return id;}
    inline QString getTitre()const {return titre;}
    inline QDate getDateDispo()const {return dateDispo;}
    inline QDate getEcheance()const {return dateEcheance;}
    inline QTime getDuree()const {return duree;}

    inline void setTitre(QString& t){titre=t;}
    inline void setDateDispo(QDate& d){dateDispo =d;}
    inline void setEcheance(QDate& d){dateEcheance=d;}
    inline void setDuree(QTime& d){duree=d;}

    Tache* getPrecedence(int id);
    void ajouterPrecedence(Tache* pred);
    virtual void afficher()const = 0;
};

#endif // TACHE_H
