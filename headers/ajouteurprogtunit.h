#ifndef AJOUTEURPROGTUNIT_H
#define AJOUTEURPROGTUNIT_H
#include "ajouteurprogrammation.h"
#include "progTUnit.h"
#include <QString>
#include <QDate>
/**
 * \class       AjouteurProgTUnit ajouteurprogtunit.h "headers/ajouteurprogtunit.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe AjouteurProgTUnit
 * \details    Cette classe définit les ajouteurs de programmation de tâche unitaire
 *             Les ajouteurs sont des objets qui servent à construire des objets d'un type données.
 *             Ils sont utiles pour que les managers puissent gérer de nouveaux types d'objets sans
 *             avoir à tout recompiler.
 */
class AjouteurProgTUnit : public AjouteurProgrammation
{
protected:
    virtual Programmation* construire(QMap<QString, QVariant> &params)const throw(AgendaException) override;
    AjouteurProgTUnit(const AjouteurProgTUnit&);
    AjouteurProgTUnit& operator=(const AjouteurProgTUnit&);
public:
    virtual void afficher()const override {std::cout << "j'ajoute des tâches unitaires\n";}
    AjouteurProgTUnit():AjouteurProgrammation()
    {}
};
#endif // AJOUTEURPROGTUNIT_H
