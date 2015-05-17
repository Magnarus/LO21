#ifndef TMANAGER_H
#define TMANAGER_H
#include<vector>
#include<QString>
#include<map>
template<typename U>
class Ajouteur;
template<typename T, typename U>
class TManager
{
    friend class Ajouteur<T>;

protected:
    std::vector<T> managable;
    std::map<QString, U> ajouteurs;
    void addItem(T i){managable.push_back(i);}
    TManager(TManager* t);
    TManager& operator=(TManager* t);

    struct HandlerTM{
            TManager* instance;
            HandlerTM():instance(0){}
            // destructeur appelé à la fin du programme
            ~HandlerTM(){ if (instance) delete instance; }
    };
    static HandlerTM handler;

public:
    TManager(size_t capacity=0)
    {
        if(capacity > 0) managable.reserve(capacity);
    }
    T& getItem(const int id)
    {
        typename std::vector<T>::iterator it = managable.begin();
        while(it!=managable.end() && id!=(*it)->getId())
            ++it;
        return **it;
    }
    const T& getItem(const int id) const
    {
            typename std::vector<T>::const_iterator it = managable.cbegin();
            while(it!=managable.cend() && id!=(*it)->getTitre())
                ++it;
            return **it;
    }
    virtual void afficher()const{}
    static TManager* getInstance();
    static void libererInstance();
    U getAjouteur(const QString& nom)const{return ajouteurs.at(nom);}
    inline int nbItem()const {return managable.size();}
};

template<typename T,typename U>
typename TManager<T,U>::HandlerTM TManager<T,U>::handler=TManager<T,U>::HandlerTM();

template<typename T,typename U>
TManager<T,U>* TManager<T,U>::getInstance(){
    if (handler.instance==0) handler.instance =new TManager;
    return handler.instance;
}

template<typename T,typename U>
void TManager<T,U>::libererInstance(){
    if (handler.instance!=0) delete handler.instance;
    handler.instance=0;
}
/*#include "tmanager.tpl"*/ ///On verra plus tard.
#endif // TMANAGER_H
