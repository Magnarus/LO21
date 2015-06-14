#ifndef ETATS_H
#define ETATS_H
/**
 * \enum Etats
 *
 * etats possibles pour une tâche
 */
enum Etats
{
    PAUSE,
    EN_COURS,
    TERMINEE
};

/**
 * \enum typeTache
 *
 * différents types de tâches possibles
 */
enum typeTache
{
    TACHE,
    UNITAIRE,
    COMPOSITE,
    PREEMPTIVE,
    NON_PREEMPTIVE
};
/**
 * \enum typeProg
 *
 * différents types de programmations possibles
 */
enum typeProg
{
    PROGTACHE,
    PROGACTIVITE,
};


#endif // ETATS_H
