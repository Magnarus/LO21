#ifndef AJOUTEURACTIVITE_H
#define AJOUTEURACTIVITE_H
#include "headers/ajouteur.h"
#include "headers/activite.h"
/**
 * \class       AjouteurActivite ajouteuractivite.h "headers/ajouteuractivite.h"
 * \author      NEVEUX Anaïs
 * \version     1.0
 * \date        11 juin 2015
 * \brief       Implémente la classe AjouteurActivite
 * \details     Cette classe définit les ajouteurs d'activité
 *              Les ajouteurs sont des objets qui servent à construire des objets d'un type données.
 *              Ils sont utiles pour que les managers puissent gérer de nouveaux types d'objets sans
 *              avoir à tout recompiler.
 */
class AjouteurActivite : public Ajouteur<Activite*>
{
protected:
    virtual Activite* construire(QMap<QString,QVariant>& params)const throw(AgendaException) override;
    AjouteurActivite(const AjouteurActivite&);
    AjouteurActivite& operator=(const AjouteurActivite&);
public:
    virtual void afficher()const override {std::cout <<"j'ajoute des activités\n";}
    /**
     * \brief AjouteurActivite  constructeur qui donne les paramètres qui doivent être renseignés
     */
    AjouteurActivite():Ajouteur()
    {
        types.insert("id");
        types.insert("date");
        types.insert("duree");
        types.insert("nom");
    }
};

#endif // AJOUTEURACTIVITE_H
