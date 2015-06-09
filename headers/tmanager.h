#ifndef TMANAGER_H
#define TMANAGER_H
#include<QVector>
#include<QString>
#include<QVariant>
#include<QMap>
#include<QSet>
#include<QDate>
#include "agendaexception.h"
//Interdépendance => Forward declaration !
template<typename U>
class Ajouteur;
template<typename T>
/**
 * \class       TManager manager.h "headers/manager.h"
 * \author      DELAUNAY Grégory
 * \version     1.0
 * \date        04 juin 2015
 * \brief       Implémente la classe manager
 *
 * \details     Cette classe définit les manager génériques
 *              Les manager sont des objets singleton qui servent à gerer le cycle et l'utilisation des types associés.
 */
class TManager
{

protected:
    QVector<T> managable; //L'ensemble des objets du Manager
    QMap<QString, Ajouteur<T>*> ajouteurs; //Les ajouteurs : ressemble au design pattern Factory !
    QSet<QString> cles;
    int idDispo;
    void addItem(T i){managable.push_back(i); idDispo++;}
    TManager(TManager* t);
    TManager& operator=(TManager* t);
    TManager(size_t capacity=0):idDispo(1)
    {
        if(capacity > 0) managable.reserve(capacity);
    }
    TManager(const TManager&);
    TManager& operator=(const TManager&);
    struct HandlerTM{
            TManager<T>* instance;
            HandlerTM():instance(0){}
            // destructeur appelé à la fin du programme
            ~HandlerTM(){ if (instance) delete instance; }
    };
    static HandlerTM handler;
    class Iterator{
        QVector<T*> resultats;
        QVector<T*> itRes;
        QDate dispo;
        QDate echeance;
        Iterator(QDate& d, QDate& e = QDate()):dispo(d),echeance(e)
        {
           typename QVector<T*>::iterator it = managable.begin();
            //S'il n'y a pas d'échéance mais une date simple
            if(echeance.isNull())
            {
                while(it != managable.end())
                {
                    if((*it)->getDate() == dispo)
                        resultats.push_back((*it));
                    ++it;
                }
            }
            else // Il y a bien une dispo et une echeance
            {
                while(it!= managable.end())
                {
                    if((*it)->getDateDispo() >= dispo && (*it)->getEcheance() <= echeance)
                        resultats.push_back((*it));
                    ++it;
                }
            }
            itRes = resultats.begin();
        }
    public:
        T* valeur(){return *itRes;}
        typename QVector<T*>::iterator& courant(){return itRes;}
        typename QVector<T*>::iterator& end(){return resultats.end();}
        void next() { ++itRes;}
    };
    Iterator getIterator(QDate& d, QDate &e = QDate()){return Iterator(d,e);}

public:
    T& getItem(const int id)
    {
        typename QVector<T>::iterator it = managable.begin();
        while(it!=managable.end() && id!=(*it)->getId())
            ++it;
        return *it;
    }
    const T& getItem(const int id) const
    {
            typename QVector<T>::const_iterator it = managable.cbegin();
            while(it!=managable.cend() && id!=(*it)->getTitre())
                ++it;
            return *it;
    }
    T& getDernierItem()const {return managable.last();}
    virtual void afficher()const = 0;
    //static TManager* getInstance();
    static void libererInstance();
    const int getIdDispo()const {return idDispo;}
    inline int nbItem()const {return managable.size();}
    inline int nbAjouteurs()const {return ajouteurs.size();}
    inline void ajouterItem(const QString& AjouteurType, QMap<QString,QVariant>& params)
    {
        if(cles.find(AjouteurType) == cles.end()) throw AgendaException("Impossible d'utiliser cet ajouteur : il n'existe pas");
        params["id"] = idDispo;
        this->addItem(ajouteurs[AjouteurType]->construire(params));
    }
    inline void ajouterAjouteur(const QString ajouteurType, Ajouteur<T>* a)
    {
        ajouteurs[ajouteurType] = a;
        cles.insert(ajouteurType);
    }
};

//Initialisation du Handler Statique
template<typename T>
typename TManager<T>::HandlerTM TManager<T>::handler=TManager<T>::HandlerTM();

/*template<typename T>
TManager<T>* TManager<T>::getInstance(){
    if (handler.instance==0) handler.instance =new TManager;
    return handler.instance;
}*/

template<typename T>
void TManager<T>::libererInstance(){
    if (handler.instance!=0) delete handler.instance;
    handler.instance=0;
}
/*#include "tmanager.tpl"*/ ///On verra plus tard.
#endif // TMANAGER_H
