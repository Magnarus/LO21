#ifndef TMANAGER_H
#define TMANAGER_H
#include<vector>
#include<QString>
#include<QVariant>
#include<map>
//Interdépendance => Forward declaration !
template<typename U>
class Ajouteur;
template<typename T>
class TManager
{

protected:
    std::vector<T> managable; //L'ensemble des objets du Manager
    std::map<QString, Ajouteur<T>*> ajouteurs; //Les ajouteurs : ressemble au design pattern Factory !
    void addItem(T i){managable.push_back(i); idDispo++;}
    TManager(TManager* t);
    TManager& operator=(TManager* t);
    TManager(size_t capacity=0)
    {
        if(capacity > 0) managable.reserve(capacity);
    }

    struct HandlerTM{
            TManager* instance;
            HandlerTM():instance(0){}
            // destructeur appelé à la fin du programme
            ~HandlerTM(){ if (instance) delete instance; }
    };
    static HandlerTM handler;
    int idDispo;

public:
    T& getItem(const int id)
    {
        typename std::vector<T>::iterator it = managable.begin();
        while(it!=managable.end() && id!=(*it)->getId())
            ++it;
        return *it;
    }
    const T& getItem(const int id) const
    {
            typename std::vector<T>::const_iterator it = managable.cbegin();
            while(it!=managable.cend() && id!=(*it)->getTitre())
                ++it;
            return *it;
    }
    virtual void afficher()const = 0;
    static TManager* getInstance();
    static void libererInstance();
    const int getIdDispo()const {return idDispo;}
    inline int nbItem()const {return managable.size();}
    inline int nbAjouteurs()const {return ajouteurs.size();}
    inline void ajouterItem(const QString& AjouteurType, std::map<QString,QVariant>& params)
    {
        params["id"] = idDispo;
        //Jdois vérifier que AjouteurType existe mais pour l'instant j'ai la flemme, jsuis fatigué XD
        this->addItem(ajouteurs[AjouteurType]->construire(params));
    }
};

//Initialisation du Handler Statique
template<typename T>
typename TManager<T>::HandlerTM TManager<T>::handler=TManager<T>::HandlerTM();

template<typename T>
TManager<T>* TManager<T>::getInstance(){
    if (handler.instance==0) handler.instance =new TManager;
    return handler.instance;
}

template<typename T>
void TManager<T>::libererInstance(){
    if (handler.instance!=0) delete handler.instance;
    handler.instance=0;
}

/*#include "tmanager.tpl"*/ ///On verra plus tard.
#endif // TMANAGER_H
