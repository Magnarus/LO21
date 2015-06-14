#ifndef AJOUTEUR_H
#define AJOUTEUR_H
#include <iostream>
#include <QMap>
#include <QSet>
#include <QList>
#include "tmanager.h"
#include "agendaexception.h"
/**
 * \class Ajouteur ajouteur.h "headers/ajouteur.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe ajouteur
 *
 * \details    Cette classe définit les ajouteurs génériques
 *             Les ajouteurs sont des objets qui servent à construire des objets d'un type données.
 *             Ils sont utiles pour que les managers puissent gérer de nouveaux types d'objets sans
 *             avoir à tout recompiler.
 */
template<typename U>
class Ajouteur
{
    friend class TManager<U>; // Pour que seuls les manager puissent créer des objets (principe du Manager ! )
protected:
    QSet<QString> types; /** Sert à indiquer les champs requis dans l'ajouteur */

    /**
     * \brief construire fonction qui crée l'objet du type correspondant et le retourne
     * \param params la liste des paramètres correspondant à l'objet qui doit être construit.
     * \return l'objet créé
     */
    virtual U construire(QMap<QString,QVariant>& params)const = 0;

    /**
     * \brief verifTypes fonction qui vérifie que l'utilisateur rentre les bons paramètres dans la fonction construire
     * \return \e booléen vrai si correspondance, faux sinon
     */
    virtual bool verifTypes(QList<QString>)const;
    Ajouteur(const Ajouteur&);
    Ajouteur& operator=(const Ajouteur&);
public:
    /**
     * \brief afficher fonction de service pour générer l'abstraction de la classe
     */
    virtual void afficher()const = 0;
    Ajouteur(){}
};
template<typename U>
bool Ajouteur<U>::verifTypes(QList<QString> set) const
{
    //On vérifie que les paramètres passés correspondent bien à une tache composite
    for(QList<QString>::iterator it = set.begin(); it!=set.end();++it)
    {
        if(types.find(*it) == types.end())
        {
            return false;
        }
    }
    return true;
}
#endif // AJOUTEUR_H
