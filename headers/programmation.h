#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H
#include<QDate>
#include<QTime>
#include "agendaexception.h"
#include "etats.h"
#include <iostream>
/**
 * \class       Programmation programmation.h "headers/programmation.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe programmation
 *
 * \details     Les programmations définissent quand l'utilisateur doit faire une tache ou une activite.
 */
class Programmation{
protected:
    int id;
    QDate date;
    QTime horaire;
    QTime duree;
    typeProg type;
    Programmation(const Programmation&);
    Programmation& operator=(const Programmation&);
public:
    Programmation(const int id,const QDate& d, const QTime& dur):id(id),date(d),duree(dur){}
    const inline int getId() const {return id;}
    const inline QDate& getDate()const{return date;}
    const inline QTime& getDuree()const{return duree;}
    const inline QTime& getHoraire()const{return horaire;}
    const inline typeProg getType()const{return type;}
    inline void setHoraire(const QTime& h){horaire=h;}
    virtual inline void setType(typeProg t){type=t;}
    virtual inline void setDate(const QDate& d) = 0;
    virtual inline void setDuree(const QTime &d) = 0;
    virtual void afficher() = 0;
};

#endif // PROGRAMMATION_H
