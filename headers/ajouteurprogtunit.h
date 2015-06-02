#ifndef AJOUTEURPROGTUNIT_H
#define AJOUTEURPROGTUNIT_H
#include "ajouteurprogrammation.h"
#include "progTUnit.h"
#include <QString>
#include <QDate>
class AjouteurProgTUnit : public AjouteurProgrammation
{
protected:
    virtual Programmation* construire(std::map<QString,QVariant>& params)const override;
public:
    virtual void afficher()const override {std::cout << "j'ajoute des tâches unitaires\n";}
    AjouteurProgTUnit():AjouteurProgrammation()
    {}
    AjouteurProgTUnit(const AjouteurProgTUnit&);
    AjouteurProgTUnit& operator=(const AjouteurProgTUnit&);
};
#endif // AJOUTEURPROGTUNIT_H
