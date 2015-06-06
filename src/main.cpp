#include "../headers/ajouteurtachecomposite.h"
#include "../headers/ajouteurtacheunitaire.h"
#include "../headers/tachemanager.h"
#include "../headers/progmanager.h"
int main()
{
    /*Voici un exemple d'ajout d'une tache unitaire dans le manager
    Typiquement, c'est ce qu'il faudra faire dans les slots de nos widget,
    en initialisant les var avec les champs de la fenêtre*/

    QDate dispo(1,1,1), deuxieme(1,1,1);
    QTime dur(12,0),durprog(12,0);
    QString nom("bonjour toi");
    Activite a(dispo,dur,nom);
    QVariant var = QVariant::fromValue(&a);
    QMap<QString,QVariant> params;
    params["date"] = deuxieme;
    params["duree"] = durprog;
    params["programme"] = var;
    try
    {
        ProgManager::getInstance()->ajouterItem("ACTIVITE",params);
    }
    catch(AgendaException a)
    {
        std::cout << a.getInfo().toStdString() << std::endl;
    }

    int i = ProgManager::getInstance()->nbItem();
    std::cout << "nombre de programmations : " << i << std::endl;
    i = TacheManager::getInstance()->nbItem();
    std::cout << "nombre de taches : " << i << std::endl;
    /*ProgManager::getInstance()->getItem(1)->afficher();*/
    return 0;
}
