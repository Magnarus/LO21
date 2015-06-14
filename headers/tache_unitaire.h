#ifndef TACHE_UNITAIRE_H
#define TACHE_UNITAIRE_H
#include"tache.h"
#include<QTime>
/**
 * \class       Tache_Unitaire tache_Unitaire.h "headers/tache_unitaire.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe Tache Unitaire
 * \details     Une tâche Unitaire est un évènement qui doit être réalisé durant un interval de dates donné.
 *              Elle peut être préemptive ou non.
 */
class Tache_Unitaire : public Tache
{
protected:
    QTime duree; /** durée de la tâche*/
    /**
     * \brief Tache_Unitaire
     * constructeur par recopie interdit
     */
    Tache_Unitaire(const Tache_Unitaire&);
    /**
     * \brief operator =
     * recopie par opérateur interdite
     * \return copie du paramètre passé
     */
    Tache_Unitaire& operator=(const Tache_Unitaire&);
public:
    /**
     * \brief Tache_Unitaire
     * constructeur par défaut
     */
    Tache_Unitaire():Tache(){}
    /**
     * \brief Tache_Unitaire
     * constructeur
     * \param id
     * id de la tâche
     * \param titre
     * titre de la tâche
     * \param dispo
     * date disponibilité de la tâche
     * \param deadline
     * date d'échéance de la tâche
     * \param dur
     * durée de la tâche
     */
    Tache_Unitaire(const int id, const QString& titre, const QDate&
                   dispo, const QDate& deadline, const QTime& dur):
        Tache(id,titre,dispo,deadline),duree(dur)
    {
        //setType(UNITAIRE);
        typeT= UNITAIRE;
    }
    /**
     * \brief afficher
     * fonction de service
     */
    virtual void afficher()const = 0;

    /**
     * \brief getDuree
     * accesseur sur la durée
     * \return durée de la tâche
     */
    inline QTime getDuree()const {return duree;}

    /**
     * \brief setDuree
     * mutateur sur la durée
     * \param d
     * la nouvelle durée
     */
    inline virtual void setDuree(QTime& d){duree=d;}

};
#include<QVariant>
Q_DECLARE_METATYPE(Tache_Unitaire*)

#endif // TACHE_UNITAIRE_H
