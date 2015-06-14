#ifndef AJOUTEURPROGACTIVITE_H
#define AJOUTEURPROGACTIVITE_H
#include "ajouteurprogrammation.h"
#include "progActivite.h"
/**
 * \class       AjouteurProgActivite ajouteurprogactivite.h "headers/ajouteurprogactivite.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe AjouteurProgActivite
 * \details    Cette classe définit les ajouteurs de programmation d'activite
 *             Les ajouteurs sont des objets qui servent à construire des objets d'un type données.
 *             Ils sont utiles pour que les managers puissent gérer de nouveaux types d'objets sans
 *             avoir à tout recompiler.
 */
class AjouteurProgActivite : public AjouteurProgrammation
{
protected:
    virtual Programmation* construire(QMap<QString,QVariant>& params)const throw(AgendaException) override;
    AjouteurProgActivite(const AjouteurProgActivite&);
    AjouteurProgActivite& operator=(const AjouteurProgActivite&);
public:
    virtual void afficher()const override {std::cout << "j'ajoute des tâches unitaires\n";}
    AjouteurProgActivite():AjouteurProgrammation(){}
};
#endif // AJOUTEURPROGACTIVITE_H
