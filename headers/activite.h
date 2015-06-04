#ifndef ACTIVITE_H
#define ACTIVITE_H
#include <iostream>
#include <QDate>
#include <QTime>
#include <QString>
/**
 * \class       Activite activite.h "headers/activite.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe des activités classique
 *
 * \details    Cette classe définit les activités classiques, qui sont des activités non
 *                  liées à des projets.
 */
class Activite
{
    QDate date;
    QTime duree;
    QString nom;
    Activite& operator=(const Activite&);
public:
    Activite(){}
    Activite(const QDate& d, const QTime& dur, const QString& nom):date(d),duree(dur),nom(nom){}
    const inline QDate& getDate()const{return date;}
    const inline QTime& getDuree()const{return duree;}
    const inline QString& getNom()const{return nom;}
    inline void setDate(QDate& d){date = d;}
    inline void setDuree(QTime& d){duree = d;}
    inline void setNom(QString& n){nom = n;}
    inline void afficher(){std::cout << nom.toStdString() << std::endl;}
};
#include<QVariant>
// Nous enregistrons le type Activite pour son utilisation avec QVariant
Q_DECLARE_METATYPE(Activite)
// ... ainsi que le type pointeur vers Activite
Q_DECLARE_METATYPE(Activite*)
#endif // ACTIVITE_H
