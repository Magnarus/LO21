#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H
#include<QDate>
#include<QTime>
class Programmation{
    int id;
    QDate date;
    QTime duree;
public:
    Programmation(const int id,const QDate& d, const QTime& dur):id(id),date(d),duree(dur){}
    const inline QDate& getDate()const{return date;}
    const inline QTime& getDuree()const{return duree;}
    inline void setDate(QDate& d){date = d;}
    inline void setDuree(QTime &d){duree = d;}
    virtual void afficher() = 0;
};

#endif // PROGRAMMATION_H
