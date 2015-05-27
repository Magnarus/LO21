#ifndef ACTIVITE_H
#define ACTIVITE_H
#include <QDate>
#include <QTime>
#include <QString>
class Activite
{
    QDate date;
    QTime duree;
    QString nom;
public:
    Activite();
    const inline QDate& getDate()const{return date;}
    const inline QTime& getDuree()const{return duree;}
    const inline QString& getNom()const{return nom;}
    inline void setDate(QDate& d){date = d;}
    inline void setDuree(QTime& d){duree = d;}
    inline void setNom(QString& n){nom = n;}

};

#endif // ACTIVITE_H
