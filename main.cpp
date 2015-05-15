#include "ajouteurtachecomposite.h"
#include "ajouteurtacheunitaire.h"
#include "tmanager.h"
int main(int argc, char *argv[])
{
    Ajouteur* atu = new AjouteurTacheUnitaire();
    Ajouteur* atc = new AjouteurTacheComposite();
    TManager<Tache> t;
    t.addAjouteur(atu,"Unitaire");
    t.addAjouteur(atc,"Composite");
    QDate dispo, deadline;
    QTime duree(12,0);
    AjouteurTacheUnitaire* au = dynamic_cast<AjouteurTacheUnitaire*>(t.getAjouteur("Unitaire"));
    au->ajout(t.getTaches(),"1",dispo,deadline,duree,true);
    std::cout << t.getItem("1").getTitre().toStdString() << std::endl;
    return 0;
}
