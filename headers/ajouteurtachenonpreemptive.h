#ifndef AJOUTEURTACHENONPREEMPTIVE_H
#define AJOUTEURTACHENONPREEMPTIVE_H
#include "ajouteurtacheunitaire.h"
#include "tachenonpreemptive.h"
/**
 * \class       AjouteurTacheNonPreemptive ajouteurtachenonpreemptive.h "headers/ajouteurtachenonpreemptive.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe AjouteurTacheNonPreemptive
 * \extends     AjouteurTache
 * \details     Cette classe définit les ajouteurs de Tache_Composite
 *              Les ajouteurs sont des objets qui servent à construire des objets d'un type données.
 *              Ils sont utiles pour que les managers puissent gérer de nouveaux types d'objets sans
 *              avoir à tout recompiler.
 */
class AjouteurTacheNonPreemptive : public AjouteurTacheUnitaire
{
protected:
    virtual Tache* construire(QMap<QString,QVariant>& params)const override;
    AjouteurTacheNonPreemptive(const AjouteurTacheNonPreemptive&);
    AjouteurTacheNonPreemptive& operator=(const AjouteurTacheNonPreemptive&);
public:
    virtual void afficher()const {std::cout << "je suis un ajouteur de tâche préemptive\n";}
    AjouteurTacheNonPreemptive():AjouteurTacheUnitaire(){}

};
#endif // AJOUTEURTACHENONPREEMPTIVE_H
