#ifndef AJOUTEURTACHECOMPOSITE_H
#define AJOUTEURTACHECOMPOSITE_H
#include "ajouteurtache.h"
#include "tache_composite.h"
#include <QString>
#include <QDate>

class AjouteurTacheComposite : public AjouteurTache
{
public:
    AjouteurTacheComposite();
    virtual void afficher()const override{ std::cout << "Je suis un ajouteur de tache composite\n";}
    void ajout(const int id,const QString& titre, const QDate&
                dispo, const QDate& deadline, const QTime& dur,
                const std::vector<Tache*>& st = std::vector<Tache*>())
    {
        Tache* tc = new Tache_Composite(id,titre,dispo,deadline,dur,st);
        ajouter(tc);
    }
};

#endif // AJOUTEURTACHECOMPOSITE_H
