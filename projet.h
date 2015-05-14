#ifndef PROJET_H
#define PROJET_H
#include<QDate>
#include<vector>
#include"tache.h"
class Projet
{
    QDate dateDispo;
    QDate dateEcheance;
    std::vector<Tache> taches;
public:
    Projet();
};

#endif // PROJET_H
