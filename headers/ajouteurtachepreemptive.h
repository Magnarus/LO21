#ifndef AJOUTEURTACHEPREEMPTIVE_H
#define AJOUTEURTACHEPREEMPTIVE_H
#include "ajouteurtacheunitaire.h"
#include "tachepreemptive.h"

class AjouteurTachePreemptive : public AjouteurTacheUnitaire
{
protected:
    virtual Tache* construire(QMap<QString,QVariant>& params)const override;
    AjouteurTachePreemptive(const AjouteurTachePreemptive&);
    AjouteurTachePreemptive& operator=(const AjouteurTachePreemptive&);
public:
    virtual void afficher()const {std::cout << "je suis un ajouteur de tâche préemptive\n";}
    AjouteurTachePreemptive():AjouteurTacheUnitaire(){}
};
#endif // AJOUTEURTACHEPREEMPTIVE_H
