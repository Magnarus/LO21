#ifndef AJOUTEURTACHEPREEMPTIVE_H
#define AJOUTEURTACHEPREEMPTIVE_H
#include "ajouteurtacheunitaire.h"
#include "tachepreemptive.h"

class AjouteurTachePreemptive : public AjouteurTacheUnitaire
{
protected:
    virtual Tache* construire(std::map<QString,QVariant>& params)const override;
public:
    virtual void afficher()const {std::cout << "je suis un ajouteur de tâche préemptive\n";}
    AjouteurTachePreemptive():AjouteurTacheUnitaire(){}
    AjouteurTachePreemptive(const AjouteurTachePreemptive&);
    AjouteurTachePreemptive& operator=(const AjouteurTachePreemptive&);
};
#endif // AJOUTEURTACHEPREEMPTIVE_H
