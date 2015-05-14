#ifndef TACHE_H
#define TACHE_H
#include<QString>
#include<vector>
#include<QDate>
#include<QTime>
class Tache
{
    QString titre;
    std::vector<Tache*> precedence;
    QDate dateDispo;
    QDate dateEcheance;
    QTime duree;
public:
    Tache(const QString& id, const QDate&
          dispo, const QDate& deadline, const QTime& dur)
         :titre(id),dateDispo(dispo),dateEcheance(deadline),duree(dur)
    {}
    void ajouterPrecedence(Tache* pred);
    virtual void afficher() = 0;
};

#endif // TACHE_H
