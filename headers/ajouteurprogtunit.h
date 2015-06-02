#ifndef AJOUTEURPROGTUNIT_H
#define AJOUTEURPROGTUNIT_H
#include "ajouteurprogrammation.h"
#include "progTUnit.h"
#include <QString>
#include <QDate>
class AjouteurProgTUnit : public AjouteurProgrammation
{
protected:
    virtual Programmation* construire(QMap<QString, QVariant> &params)const override;
    AjouteurProgTUnit(const AjouteurProgTUnit&);
    AjouteurProgTUnit& operator=(const AjouteurProgTUnit&);
public:
    virtual void afficher()const override {std::cout << "j'ajoute des tâches unitaires\n";}
    AjouteurProgTUnit():AjouteurProgrammation()
    {}
};
#endif // AJOUTEURPROGTUNIT_H
