#ifndef TMANAGER_H
#define TMANAGER_H
#include<vector>
#include<QString>

template<typename T>
class TManager
{
protected:
    std::vector<T*> managable;
    inline void addItem(T* t){managable.push_back(t);}
public:
    TManager(size_t capacity=0)
    {
        if(capacity > 0) managable.reserve(capacity);
    }

    T& getItem(const QString& id)
    {
        typename std::vector<T*>::iterator it = managable.begin();
        while(it!=managable.end() && id!=*it->getId())
            ++it;
        return *it;
    }
    const T& getItem(const QString& id) const
    {
            typename std::vector<T*>::const_iterator it = managable.cbegin();
            while(it!=managable.cend() && id!=*it->getId())
                ++it;
            return **it;
    }

    virtual void afficher() = 0;
};
/*#include "tmanager.tpl"*/ ///On verra plus tard.
#endif // TMANAGER_H
