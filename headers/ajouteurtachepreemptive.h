#ifndef AJOUTEURTACHEPREEMPTIVE_H
#define AJOUTEURTACHEPREEMPTIVE_H
#include "ajouteurtacheunitaire.h"
#include "tachepreemptive.h"
/**
 * \class       AjouteurTachePreemptive ajouteurtachepreemptive.h "headers/ajouteurtachepreemptive.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe AjouteurTachePreemptive
 * \extends     AjouteurTacheUnitaire
 * \details     Cette classe définit les ajouteurs de programmation de tâche unitaire preemptive
 *              Les ajouteurs sont des objets qui servent à construire des objets d'un type données.
 *              Ils sont utiles pour que les managers puissent gérer de nouveaux types d'objets sans
 *              avoir à tout recompiler.
 */
class AjouteurTachePreemptive : public AjouteurTacheUnitaire
{
protected:
    virtual Tache* construire(QMap<QString,QVariant>& params)const throw(AgendaException) override;
    AjouteurTachePreemptive(const AjouteurTachePreemptive&);
    AjouteurTachePreemptive& operator=(const AjouteurTachePreemptive&);
public:
    virtual void afficher()const {std::cout << "je suis un ajouteur de tâche préemptive\n";}
    AjouteurTachePreemptive():AjouteurTacheUnitaire(){}
};
#endif // AJOUTEURTACHEPREEMPTIVE_H
