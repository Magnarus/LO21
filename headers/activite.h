#ifndef ACTIVITE_H
#define ACTIVITE_H
#include <iostream>
#include <QDate>
#include <QTime>
#include <QString>
/**
 * \class       Activite activite.h "headers/activite.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe des activités classique
 *
 * \details    Cette classe définit les activités classiques, qui sont des activités non
 *                  liées à des projets.
 */
class Activite
{
    int id;/** id de l'activité */
    QDate date;/** date de l'activité */
    QTime duree;/** durée de l'activité */
    QString nom;/** Nom de l'activité */
    Activite& operator=(const Activite&);
public:
    /**
     * \brief       constructeur d'activité par défaut.
     */
    Activite(){}

    /**
     * \brief Activite
     * constructeur
     * \param id
     * id de l'activité
     * \param d
     * durée de l'activité
     * \param dur
     * durée de l'activité
     * \param nom
     * nom de l'activité
     */
    Activite(int id,const QDate& d, const QTime& dur, const QString& nom):date(d),duree(dur),nom(nom),id(id){}

    /**
     * @brief Activite
     * constructeur
     * @param d
     * date de l'activité
     * @param dur
     * durée de l'activité
     * @param nom
     * nom de l'activité
     */
    Activite(const QDate& d, const QTime& dur, const QString& nom):date(d),duree(dur),nom(nom){}

    /**
     * \brief getId
     * accesseur sur l'id
     * \return l'id
     */
    inline int getId()const {return id;}

    /**
     * \brief getDate
     * accesseur sur date
     * \return la date
     */
    const inline QDate& getDate()const{return date;}

    /**
     * \brief getDuree
     * accesseur sur durée
     * \return la durée
     */
    const inline QTime& getDuree()const{return duree;}

    /**
     * \brief getNom
     * accesseur de nom
     * \return le nom
     */
    const inline QString& getNom()const{return nom;}

    /**
     * \brief setDate
     * mutateur de date
     * \param d
     * nouvelle date
     */
    inline void setDate(QDate& d){date = d;}

    /**
     * \brief setDuree
     * mutateur de durée
     * \param d
     * la nouvelle durée
     */
    inline void setDuree(QTime& d){duree = d;}

    /**
     * \brief setNom
     * mutateur de nom
     * \param n
     * nouveau nom
     */
    inline void setNom(QString& n){nom = n;}

    /**
     * \brief       fonction de service qui affiche le nom d'une activité
     */
    inline void afficher(){std::cout << nom.toStdString() << std::endl;}
};
#include<QVariant>
// Nous enregistrons le type Activite pour son utilisation avec QVariant
Q_DECLARE_METATYPE(Activite)
// ... ainsi que le type pointeur vers Activite
Q_DECLARE_METATYPE(Activite*)
#endif // ACTIVITE_H
