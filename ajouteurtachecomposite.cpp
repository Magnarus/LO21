#include "ajouteurtachecomposite.h"

AjouteurTacheComposite::AjouteurTacheComposite()
{
}

void AjouteurTacheComposite::ajout(std::vector<Tache *> conteneur, const int id,
                              const QString &titre, const QDate &dispo,
                              const QDate &deadline, const QTime &dur,
                              const std::vector<Tache *> &st)
{
    Tache_Composite* tc = new Tache_Composite(id,titre,dispo,deadline,dur,st);
    conteneur.push_back(tc);
}
