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
#include "edittache.h"
#include "tache_composite.h"
class ProjectView : public QWidget
{
    Q_OBJECT
    QPushButton *_creerProjet,*_creerTache,*_Editer,*_actualiser;
    QTreeWidget *_lesProjets;
    QVBoxLayout *_mainLayout;
    QHBoxLayout *_buttonLayout,*_treeLayout;
    AddProject *_ajouterProjet;
    AddTache *_ajouterTache;
    EditProject *_editerProjet;
    QTreeWidgetItem* _noeudClic;
    QAction* _ajout;
    QAction* _suppr;
    Editeur* _edit;

    void supprimerValeurAssocieeQVariant(QVariant& varsupp);
    void supprimerLienProjet(Tache* t);
    void supprimerLienTacheComposite(Tache *t);
public:
    explicit ProjectView(QWidget *parent = 0);
    ~ProjectView(){}
    QTreeWidgetItem *ajouterRacine(QString &name, QString &description, QVariant &data);
    QTreeWidgetItem* ajouterEnfant(QTreeWidgetItem *parent,
                                   QString& name, QString& description, QVariant& data);
    void ajouterTache(Tache* t, QTreeWidgetItem* parent);
    void init();

signals:

public slots:
    void showCreateProject(){
        delete _ajouterProjet;
        _ajouterProjet=new AddProject();
        _ajouterProjet->exec();
    }
    void showCreateTache(){
        delete _ajouterTache;
       _ajouterTache=new AddTache();
       _ajouterTache->exec();
    }
    void showEditProject(){
        /*delete _editerProjet;
        _editerProjet=new EditProject();
        _editerProjet->exec();*/
    }
    void actualiser(){
       // _lesProjets->reset();
        init();
    }
    void clicDroit(QPoint pos);
    void slotAjouterTache();
    void suppressionNoeud();
};

#endif // PROJECTVIEW_H
