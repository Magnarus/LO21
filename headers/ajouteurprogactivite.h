#ifndef AJOUTEURPROGACTIVITE_H
#define AJOUTEURPROGACTIVITE_H
#include "ajouteurprogrammation.h"
#include "progActivite.h"
class AjouteurProgActivite : public AjouteurProgrammation
{
protected:
    virtual Programmation* construire(QMap<QString,QVariant>& params)const override;
    AjouteurProgActivite(const AjouteurProgActivite&);
    AjouteurProgActivite& operator=(const AjouteurProgActivite&);
public:
    virtual void afficher()const override {std::cout << "j'ajoute des tâches unitaires\n";}
    AjouteurProgActivite():AjouteurProgrammation(){}
};
#endif // AJOUTEURPROGACTIVITE_H
