#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H
#include<QDate>
#include<QTime>
#include "agendaexception.h"
#include "etats.h"
#include <iostream>
/**
 * \class       Programmation programmation.h "headers/programmation.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe programmation
 *
 * \details     Les programmations définissent quand l'utilisateur doit faire une tache ou une activite.
 */
class Programmation{
protected:
    int id; /** id de la programmation */
    QDate date; /** date de la programmation */
    QTime horaire; /** horaire de la programmation */
    QTime duree; /** durée de la programmation */
    typeProg type; /** type de programmation */
    /**
     * \brief Programmation
     * constructeur interdit
     */
    Programmation(const Programmation&);
    /**
     * \brief operator =
     * redéfinition d'opérateur interdite
     * \return copie de la programmation
     */
    Programmation& operator=(const Programmation&);
public:
    /**
     * \brief Programmation
     * constucteur
     * \param id id de la programmation
     * \param d date de la programmation
     * \param dur durée de la programmation
     * \param h horaire de la programmation
     */
    Programmation(const int id,const QDate& d, const QTime& dur,const QTime& h);

    /**
     * \brief getId
     * retourne l'id de la programmation
     * \return l'id de la programmation
     */
    const inline int getId() const {return id;}

    /**
     * \brief getDate
     * accesseur sur la date
     * \return la date de la programmation
     */
    const inline QDate& getDate()const{return date;}

    /**
     * \brief getDuree
     * accesseur sur la durée de la programmation
     * \return la durée de la programmation
     */
    const inline QTime& getDuree()const{return duree;}

    /**
     * \brief getHoraire
     * accesseur sur l'horaire de la programmation
     * \return  l'horaire de la programmation
     */
    const inline QTime& getHoraire()const{return horaire;}

    /**
     * \brief getType
     * accesseur sur le type de la programmation
     * \return le type de la programmation
     */
    const inline typeProg getType()const{return type;}

    /**
     * \brief setHoraire
     * mutateur sur l'horaire
     * \param h nouvelle horaire
     */
    inline void setHoraire(const QTime& h){horaire=h;}

    /**
     * \brief setType
     * mutateur sur le type
     * \param t nouveau type
     */
    virtual inline void setType(typeProg t){type=t;}

    /**
     * \brief setDate
     * mutateur sur la date
     * \param d nouvelle date
     */
    virtual inline void setDate(const QDate& d) = 0;

    /**
     * \brief setDuree
     * mutateur sur la durée
     * \param d nouvelle durée
     */
    virtual inline void setDuree(const QTime &d) = 0;

    /**
     * \brief afficher
     * fonction de service
     */
    virtual void afficher() = 0;
};
#include<QVariant>
// ... ainsi que le type pointeur vers Activite
Q_DECLARE_METATYPE(Programmation*)
#endif // PROGRAMMATION_H
