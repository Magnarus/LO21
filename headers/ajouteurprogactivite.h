#ifndef AJOUTEURPROGACTIVITE_H
#define AJOUTEURPROGACTIVITE_H
#include "ajouteurprogrammation.h"
#include "progActivite.h"
class AjouteurProgActivite : public AjouteurProgrammation
{
protected:
    virtual Programmation* construire(std::map<QString,QVariant>& params)const override;
public:
    virtual void afficher()const override {std::cout << "j'ajoute des tâches unitaires\n";}
    AjouteurProgActivite():AjouteurProgrammation(){}
    AjouteurProgActivite(const AjouteurProgActivite&);
    AjouteurProgActivite& operator=(const AjouteurProgActivite&);
};
#endif // AJOUTEURPROGACTIVITE_H
