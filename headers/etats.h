#ifndef ETATS_H
#define ETATS_H
enum Etats
{
    PAUSE,
    EN_COURS,
    TERMINEE
};

enum typeTache
{
    TACHE,
    UNITAIRE,
    COMPOSITE,
    PREEMPTIVE,
    NON_PREEMPTIVE
};

enum typeProg
{
    PROGTACHE,
    PROGACTIVITE,
};

#endif // ETATS_H
