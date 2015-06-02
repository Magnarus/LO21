#ifndef AJOUTEURPROGRAMMATION_H
#define AJOUTEURPROGRAMMATION_H
#include "ajouteur.h"
#include "programmation.h"
class AjouteurProgrammation : public Ajouteur<Programmation*>
{
protected:
    virtual Programmation* construire(std::map<QString,QVariant>& params)const = 0;
public:
    virtual void afficher()const = 0;
    AjouteurProgrammation(const AjouteurProgrammation&){}
    AjouteurProgrammation& operator=(const AjouteurProgrammation&){}
    AjouteurProgrammation():Ajouteur()
    {
        types.insert("id");
        types.insert("date");
        types.insert("duree");
        types.insert("programme");
    }
};
#endif // AJOUTEURPROGRAMMATION_H
