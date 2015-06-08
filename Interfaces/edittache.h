#ifndef EDITTACHE_H
#define EDITTACHE_H
#include "addtache.h"
#include <QWidget>
#include <QString>
class EditTache : public addTache
{
public:
    EditTache(QWidget *parent=0):addTache(parent){ setWindowTitle(QString("Editer une tâche"));
                                                 setAjouterTitle(QString("Enregistrer les modifications"));}
};

#endif // EDITTACHE_H
