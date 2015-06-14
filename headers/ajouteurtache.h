#ifndef AJOUTEURTACHE_H
#define AJOUTEURTACHE_H
#include "ajouteur.h"
#include "tache.h"
Q_DECLARE_METATYPE( QList<Tache*> ) // Sert à indiquer au QVariant que ce type existe
/**
 * \class       AjouteurTache ajouteurtache.h "headers/ajouteurtache.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe AjouteurTache
 * \details    Cette classe définit les ajouteurs de tache
 *             Les ajouteurs sont des objets qui servent à construire des objets d'un type données.
 *             Ils sont utiles pour que les managers puissent gérer de nouveaux types d'objets sans
 *             avoir à tout recompiler.
 */
class AjouteurTache : public Ajouteur<Tache*>
{
protected:
    virtual Tache* construire(QMap<QString,QVariant>& params)const = 0;
    AjouteurTache(const AjouteurTache&);
    AjouteurTache& operator=(const AjouteurTache&);
public:
    virtual void afficher()const = 0;
    /**
     * \brief AjouteurTache constructeur qui donne les paramètres qui doivent être renseignés
     */
    AjouteurTache():Ajouteur()
    {
        types.insert("id");
        types.insert("titre");
        types.insert("dispo");
        types.insert("deadline");
    }
};
#endif // AJOUTEURTACHE_H
