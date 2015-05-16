#ifndef TMANAGER_H
#define TMANAGER_H
#include "ajouteur.h"
#include<vector>
#include<QString>
#include<map>
template<typename T>
class TManager
{
protected:
    std::map<QString,Ajouteur*> ajouts;
    std::vector<T*> managable;
public:
    TManager(size_t capacity=0)
    {
        if(capacity > 0) managable.reserve(capacity);
    }

    std::vector<T*>& getT() {return managable;}
    T& getItem(const int id)
    {
        typename std::vector<T*>::iterator it = managable.begin();
        while(it!=managable.end() && id!=(*it)->getId())
            ++it;
        return **it;
    }
    const T& getItem(const int id) const
    {
            typename std::vector<T*>::const_iterator it = managable.cbegin();
            while(it!=managable.cend() && id!=(*it)->getTitre())
                ++it;
            return **it;
    }
    void addAjouteur(Ajouteur* a,QString nom){ ajouts[nom]=a;}
    Ajouteur* getAjouteur(QString nom)const{return ajouts.at(nom);}

};
/*#include "tmanager.tpl"*/ ///On verra plus tard.
#endif // TMANAGER_H
