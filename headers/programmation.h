#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H
#include<QDate>
#include<QTime>
#include "agendaexception.h"
#include <iostream>
class Programmation{
protected:
    int id;
    QDate date;
    QTime duree;
public:
    Programmation(const int id,const QDate& d, const QTime& dur):id(id),date(d),duree(dur){}
    const inline int getId()const {return id;}
    const inline QDate& getDate()const{return date;}
    const inline QTime& getDuree()const{return duree;}
    virtual inline void setDate(QDate& d) = 0;
    virtual inline void setDuree(QTime &d) = 0;
    virtual void afficher() = 0;
};

#endif // PROGRAMMATION_H
