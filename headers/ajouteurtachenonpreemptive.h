#ifndef AJOUTEURTACHENONPREEMPTIVE_H
#define AJOUTEURTACHENONPREEMPTIVE_H
#include "ajouteurtacheunitaire.h"
#include "tachenonpreemptive.h"

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
