#include "ajouteurtacheunitaire.h"

AjouteurTacheUnitaire::AjouteurTacheUnitaire()
{
}

void AjouteurTacheUnitaire::ajout(std::vector<Tache *> &conteneur,
                                  const int id, const QString &titre,
                                  const QDate &dispo, const QDate &deadline,
                                  const QTime &dur, bool preemptive)
{
    Tache_Unitaire* tu = new Tache_Unitaire(id,titre,dispo,deadline,dur,preemptive);
    conteneur.push_back(tu);
}
