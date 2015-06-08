#ifndef PROJECTVIEW_H
#define PROJECTVIEW_H

#include <QWidget>
#include <QTreeView>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "addproject.h"
#include "addtache.h"
#include "editproject.h"

class projectView : public QWidget
{
    Q_OBJECT
    QPushButton *_creerProjet,*_creerTache,*_Editer;
    QTreeView *_lesProjets;
    QVBoxLayout *_vlayout;
    QHBoxLayout *_buttonLayout;
    AddProject *_ajouterProjet;
    addTache *_ajouterTache;
    EditProject *_editerProjet;
public:
    explicit projectView(QWidget *parent = 0);
    ~projectView();

signals:

public slots:
    void showCreateProject(){
        delete _ajouterProjet;
        _ajouterProjet=new AddProject();
        _ajouterProjet->show();
    }
    void showCreateTache(){
        delete _ajouterTache;
       _ajouterTache=new addTache();
       _ajouterTache->show();
    }
    void showEditProject(){
        delete _editerProjet;
        _editerProjet=new EditProject();
        _editerProjet->show();
    }
};

#endif // PROJECTVIEW_H
