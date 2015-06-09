#ifndef PROJECTVIEW_H
#define PROJECTVIEW_H

#include <QWidget>
#include <QTreeWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "addproject.h"
#include "addtache.h"
#include "editproject.h"

class ProjectView : public QWidget
{
    Q_OBJECT
    QPushButton *_creerProjet,*_creerTache,*_Editer;
    QTreeWidget *_lesProjets;
    QVBoxLayout *_vlayout;
    QHBoxLayout *_buttonLayout;
    AddProject *_ajouterProjet;
    AddTache *_ajouterTache;
    EditProject *_editerProjet;
public:
    explicit ProjectView(QWidget *parent = 0);
    ~ProjectView(){}
    QTreeWidgetItem *ajouterRacine(QString name, QString description);
    QTreeWidgetItem *ajouterEnfant(QTreeWidgetItem *parent,
                       QString name, QString description);

signals:

public slots:
    void showCreateProject(){
        delete _ajouterProjet;
        _ajouterProjet=new AddProject();
        _ajouterProjet->show();
    }
    void showCreateTache(){
        delete _ajouterTache;
       _ajouterTache=new AddTache();
       _ajouterTache->show();
    }
    void showEditProject(){
        delete _editerProjet;
        _editerProjet=new EditProject();
        _editerProjet->show();
    }
};

#endif // PROJECTVIEW_H
