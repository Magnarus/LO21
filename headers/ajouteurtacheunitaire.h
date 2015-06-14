#ifndef AJOUTEURTACHEUNITAIRE_H
#define AJOUTEURTACHEUNITAIRE_H
#include "ajouteurtache.h"
#include "tache_unitaire.h"
#include "tachemanager.h"
#include <QString>
#include <QDate>
/**
 * \class       AjouteurTacheUnitaire ajouteurtacheunitaire.h "headers/ajouteurtacheunitaire.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe AjouteurTacheUnitaire
 * \details     Cette classe définit les ajouteurs de programmation de tâche unitaire
 *              Les ajouteurs sont des objets qui servent à construire des objets d'un type données.
 *              Ils sont utiles pour que les managers puissent gérer de nouveaux types d'objets sans
 *              avoir à tout recompiler.
 */
class AjouteurTacheUnitaire : public AjouteurTache
{
protected:
    virtual Tache* construire(QMap<QString,QVariant>& params)const = 0;
    AjouteurTacheUnitaire(const AjouteurTacheUnitaire&);
    AjouteurTacheUnitaire& operator=(const AjouteurTacheUnitaire&);
public:
    virtual void afficher()const =0;
    /**
     * \brief AjouteurTacheUnitaire  constructeur qui donne les paramètres qui doivent être renseignés
     */
    AjouteurTacheUnitaire():AjouteurTache()
    {
        types.insert("dur");
    }
};

#endif // AJOUTEURTACHEUNITAIRE_H
