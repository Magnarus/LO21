#ifndef PROGMANAGER_H
#define PROGMANAGER_H
#include "tmanager.h"
#include "ajouteurprogactivite.h"
#include "ajouteurprogtunit.h"
#include<iostream>
class ProgManager : public TManager<Programmation*>
{
    ProgManager(const ProgManager&);
    ProgManager& operator=(const ProgManager&);
public:
    ProgManager();
    virtual void afficher()const {std::cout << "Je suis un manager de tâches\n";}
    static TManager<Programmation*> *getInstance();
};
#endif // PROGMANAGER_H
