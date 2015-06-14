#ifndef AJOUTEURPROJET_H
#define AJOUTEURPROJET_H
#include "ajouteur.h"
#include "projet.h"
/**
 * \class       AjouteurProjet ajouteurprojet.h "headers/ajouteurprojet.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe AjouteurProjet
 * \details    Cette classe définit les ajouteurs de projet
 *             Les ajouteurs sont des objets qui servent à construire des objets d'un type données.
 *             Ils sont utiles pour que les managers puissent gérer de nouveaux types d'objets sans
 *             avoir à tout recompiler.
 */
class AjouteurProjet : public Ajouteur<Projet*>
{
protected:
    virtual Projet* construire(QMap<QString,QVariant>& params)const throw(AgendaException) override;
    AjouteurProjet(const AjouteurProjet&);
    AjouteurProjet& operator=(const AjouteurProjet&);
public:
    virtual void afficher()const override {std::cout << "je suis un ajouteur de projet\n";}
    /**
     * \brief AjouteurProjet constructeur qui donne les paramètres qui doivent être renseignés
     */
    AjouteurProjet():Ajouteur()
    {
        types.insert("id");
        types.insert("titre");
        types.insert("dispo");
        types.insert("echeance");
    }
};

#endif // AJOUTEURPROJET_H
