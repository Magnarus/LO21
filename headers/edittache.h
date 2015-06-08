#ifndef EDITTACHE_H
#define EDITTACHE_H
#include "addtache.h"
#include <QWidget>
#include <QString>
class EditTache : public AddTache
{
public:
    EditTache(QWidget *parent=0):AddTache(parent){ setWindowTitle(QString("Editer une tâche"));
                                                 setAjouterTitle(QString("Enregistrer les modifications"));}
};

#endif // EDITTACHE_H
