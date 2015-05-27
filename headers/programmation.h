#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H
#include<QDate>
#include<QTime>
template<typename P>
class Programmation{
    QDate date;
    QTime duree;
    P programme;
public:
    Programmation(const QDate& d, const QTime& dur, const P& p):date(d),duree(dur),programme(p){}
    const inline QDate& getDate()const{return date;}
    const inline QTime& getDuree()const{return duree;}
    const inline P getProgramme()const{return programme;}
    inline void setDate(QDate& d){date = d;}
    inline void setDuree(QTime &d){duree = d;}
    inline void setProgramme(P& p){programme = p;}
};

#endif // PROGRAMMATION_H
