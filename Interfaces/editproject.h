#ifndef EDITPROJECT_H
#define EDITPROJECT_H
#include"addproject.h"
#include<QWidget>
#include<QString>
class EditProject : public AddProject
{
public:
    EditProject(QWidget* parent=0):AddProject(parent){ setWindowTitle(QString("Editer un projet"));
                                                  setAjouterTitle(QString("Enregistrer les modifications"));   }
};

#endif // EDITPROJECT_H
