#include "../headers/ajouteurtachecomposite.h"
#include "../headers/ajouteurtacheunitaire.h"
#include "../headers/tachemanager.h"

int main()
{
    /*Voici un exemple d'ajout d'une tache unitaire dans le manager
    Typiquement, c'est ce qu'il faudra faire dans les slots de nos widget,
    en initialisant les var avec les champs de la fenêtre*/

    QString titre = "God save the Queen";
    QDate dispo, deadline;
    QTime dur(12,0);
    bool ok = true;
    int id = 1;
    std::map<QString,QVariant> params;
    params.insert(std::pair<QString,QVariant>(QString("id"),QVariant(id)));
    params.insert(std::pair<QString,QVariant>(QString("titre"),QVariant(titre)));
    params.insert(std::pair<QString,QVariant>(QString("dispo"),QVariant(dispo)));
    params.insert(std::pair<QString,QVariant>(QString("deadline"),QVariant(deadline)));
    params.insert(std::pair<QString,QVariant>(QString("dur"),QVariant(dur)));
    params.insert(std::pair<QString,QVariant>(QString("preempt"),QVariant(ok)));
    TacheManager::getInstance()->ajouterItem("UNITAIRE",params);
    int i = TacheManager::getInstance()->nbItem();
    std::cout << "nombre de taches : " << i << std::endl;
    std::cout << TacheManager::getInstance()->getItem(1)->getTitre().toStdString() << std::endl;
    return 0;
}
