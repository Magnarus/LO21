#ifndef AJOUTEURTACHECOMPOSITE_H
#define AJOUTEURTACHECOMPOSITE_H
#include "ajouteur.h"
#include "tache_composite.h"
#include <QString>
#include <QDate>
class AjouteurTacheComposite : public Ajouteur
{
public:
    AjouteurTacheComposite();
    virtual void afficher()const override{ std::cout << "Je suis un ajouteur de tache composite\n";}
    void ajout(std::vector<Tache*> conteneur, const int id,const QString& titre, const QDate&
                            dispo, const QDate& deadline, const QTime& dur,
                            const std::vector<Tache*>& st = std::vector<Tache*>());
};

#endif // AJOUTEURTACHECOMPOSITE_H
