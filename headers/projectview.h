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
#include "ProgrammationExport.h"
#include "MethodExport.h"
#include "XMLExport.h"
#include "SimpleFileExport.h"
#include "ProgrammationProjetExport.h"
class ProjectView : public QWidget
{
    Q_OBJECT
    QPushButton *_creerProjet;
    QTreeWidget *_lesProjets;
    QHBoxLayout *_mainLayout;
    QVBoxLayout *_leftLayout;
    AddProject *_ajouterProjet;
    AddTache *_ajouterTache;
    EditProject *_editerProjet;
    QTreeWidgetItem* _noeudClic;
    QAction* _ajout;
    QAction* _suppr;
    QMenu* _export;
    QMenu* _exportProgProj;
    QAction* _exportProgProjXML;
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
    void previentAccueil();
public slots:
    void showCreateProject(){
        delete _ajouterProjet;
        _ajouterProjet=new AddProject();
        _ajouterProjet->exec();
        actualiser();
    }
    int showCreateTache(){
        delete _ajouterTache;
        _ajouterTache=new AddTache();
        connect(_ajouterTache,SIGNAL(accepted()),this,SLOT(prevenirAccueil()));
        return _ajouterTache->exec();
    }
    void actualiser(){
        _lesProjets->clear();
        init();
    }
    void clicDroit(QPoint pos);
    void slotAjouterTache();
    void suppressionNoeud();
    void exporterProgProjetXML();
    void lancerEdit(QTreeWidgetItem* item, int column);
    void prevenirAccueil(){
        emit previentAccueil();
    }
};

#endif // PROJECTVIEW_H
