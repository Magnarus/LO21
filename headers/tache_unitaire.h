#ifndef TACHE_UNITAIRE_H
#define TACHE_UNITAIRE_H
#include"tache.h"
#include<QTime>
/**
 * \class       Tache_Unitare tache_Unitaire.h "headers/tache_unitaire.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe Tache Unitaire
 * \extends     Tache
 * \details     Une tâche Unitaire est un évènement qui doit être réalisé durant un interval de dates donné.
 *              Elle peut être préemptive ou non.
 */
class Tache_Unitaire : public Tache
{
protected:
    QTime duree;
    Tache_Unitaire(const Tache_Unitaire&);
    Tache_Unitaire& operator=(const Tache_Unitaire&);
public:
    Tache_Unitaire():Tache(){}
    Tache_Unitaire(const int id, const QString& titre, const QDate&
                   dispo, const QDate& deadline, const QTime& dur):
        Tache(id,titre,dispo,deadline),duree(dur)
    {
        //setType(UNITAIRE);
        typeT= UNITAIRE;
    }
    virtual void afficher()const = 0;
    inline QTime getDuree()const {return duree;}
    inline virtual void setDuree(QTime& d){duree=d;}

};
#include<QVariant>
Q_DECLARE_METATYPE(Tache_Unitaire*)

#endif // TACHE_UNITAIRE_H
