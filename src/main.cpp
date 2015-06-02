#include "../headers/ajouteurtachecomposite.h"
#include "../headers/ajouteurtacheunitaire.h"
#include "../headers/tachemanager.h"
#include "../headers/progmanager.h"
int main()
{
    /*Voici un exemple d'ajout d'une tache unitaire dans le manager
    Typiquement, c'est ce qu'il faudra faire dans les slots de nos widget,
    en initialisant les var avec les champs de la fenêtre*/

    QDate dispo, deuxieme;
    QTime dur(12,0),durprog(8,0);
    QString nom("bonjour toi");
    Activite a(dispo,dur,nom);
    QVariant var = QVariant::fromValue(&a);
    /*ProgManager::getInstance()->ajouterItem("ACTIVITE",params);
    int i = ProgManager::getInstance()->nbItem();
    std::cout << "nombre de taches : " << i << std::endl;
    std::cout << ProgManager::getInstance()->getItem(1)->getDuree().hour() << std::endl;*/
    return 0;
}
