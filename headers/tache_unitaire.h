#ifndef TACHE_UNITAIRE_H
#define TACHE_UNITAIRE_H
#include"tache.h"
#include<QTime>
class Tache_Unitaire : public Tache
{
protected:
    QTime duree;
public:
    Tache_Unitaire():Tache(){}
    Tache_Unitaire(const int id, const QString& titre, const QDate&
                   dispo, const QDate& deadline, const QTime& dur):
        Tache(id,titre,dispo,deadline),duree(dur)
    {}
    virtual void afficher()const = 0;
    inline QTime getDuree()const {return duree;}
    inline void setDuree(QTime& d){duree=d;}

};
#include<QVariant>
Q_DECLARE_METATYPE(Tache_Unitaire*)

#endif // TACHE_UNITAIRE_H
