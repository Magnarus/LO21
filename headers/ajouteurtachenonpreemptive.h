#ifndef AJOUTEURTACHENONPREEMPTIVE_H
#define AJOUTEURTACHENONPREEMPTIVE_H
#include "ajouteurtacheunitaire.h"
#include "tachenonpreemptive.h"

class AjouteurTacheNonPreemptive : public AjouteurTacheUnitaire
{
protected:
    virtual Tache* construire(std::map<QString,QVariant>& params)const override;
public:
    virtual void afficher()const {std::cout << "je suis un ajouteur de tâche préemptive\n";}
    AjouteurTacheNonPreemptive():AjouteurTacheUnitaire(){}
    AjouteurTacheNonPreemptive(const AjouteurTacheNonPreemptive&);
    AjouteurTacheNonPreemptive& operator=(const AjouteurTacheNonPreemptive&);
};
#endif // AJOUTEURTACHENONPREEMPTIVE_H
