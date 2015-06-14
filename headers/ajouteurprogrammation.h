#ifndef AJOUTEURPROGRAMMATION_H
#define AJOUTEURPROGRAMMATION_H
#include "ajouteur.h"
#include "programmation.h"
/**
 * \class       AjouteurProgrammation ajouteurprogrammation.h "headers/ajouteurprogrammation.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe AjouteurProgrammation
 * \details    Cette classe définit les ajouteurs de programmation
 *             Les ajouteurs sont des objets qui servent à construire des objets d'un type données.
 *             Ils sont utiles pour que les managers puissent gérer de nouveaux types d'objets sans
 *             avoir à tout recompiler.
 */
class AjouteurProgrammation : public Ajouteur<Programmation*>
{
protected:
    virtual Programmation* construire(QMap<QString,QVariant>& params)const = 0;
    AjouteurProgrammation(const AjouteurProgrammation&);
    AjouteurProgrammation& operator=(const AjouteurProgrammation&);
public:
    virtual void afficher()const = 0;
    /**
     * \brief AjouteurProgrammation constructeur qui donne les paramètres qui doivent être renseignés
     */
    AjouteurProgrammation():Ajouteur()
    {
        types.insert("id");
        types.insert("date");
        types.insert("duree");
        types.insert("horaire");
        types.insert("programme");
    }
};
#endif // AJOUTEURPROGRAMMATION_H
