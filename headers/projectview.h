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
/**
 * \class ProjectView projectview.h "headers/projectview.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        08 juin 2015
 * \brief       Implémente la classe ProjectView
 * \details    Ce widget est l'un des widgets principaux de l'application.
 * Il sert à gérer tout ce qui est création et édition de projet, et de tâches.
 * Il permet également de gérer les liens entre les différentes entités.
 */
class ProjectView : public QWidget
{
    Q_OBJECT
    QPushButton *_creerProjet; /** le bouton pour créer un projet */
    QTreeWidget *_lesProjets; /** l'arborescence*/
    QHBoxLayout *_mainLayout; /** layout principal */
    QVBoxLayout *_leftLayout; /** layout de gauche */
    AddProject *_ajouterProjet; /** fenetre de création de projet */
    AddTache *_ajouterTache; /** fenetre de création de tâche*/
    EditProject *_editerProjet; /** fenetre d'édition de projet */
    QTreeWidgetItem* _noeudClic; /** noeud cliqué sur l'arborescence */
    QAction* _ajout; /** action d'ajout */
    QAction* _suppr; /** action de suppression */
    Editeur* _edit; /** éditeur associé */
    QMenu* _export; /** premier niveau du menu d'exportation */
    QMenu* _exportProgProj; /** choix du type d'exportation */
    QAction* _exportProgProjXML; /** choix du format XML */

    /**
     * \brief supprimerValeurAssocieeQVariant
     * supprime l'objet associé au QVariant passé
     * \param varsupp
     * variant à supprimer
     */
    void supprimerValeurAssocieeQVariant(QVariant& varsupp);

    /**
     * \brief supprimerLienProjet
     * supprime le lien entre une tâche et son projet
     * \param t
     * tâche à délier
     */
    void supprimerLienProjet(Tache* t);

    /**
     * \brief supprimerLienTacheComposite
     * supprime le lien entre une tâche et sa tâche mère
     * \param t
     * tâche à délier
     */
    void supprimerLienTacheComposite(Tache *t);
public:

    /**
     * \brief ProjectView
     * constructeur
     * \param parent s'il y en a un
     */
    explicit ProjectView(QWidget *parent = 0);
    ~ProjectView(){}
    /**
     * \brief ajouterRacine
     * ajoute un noeud à la racine de l'arborescence
     * \param name
     * nom du noeud
     * \param description
     * description du noeud
     * \param data
     * donnée à lier au noeud
     * \return le noeud ajouté
     */
    QTreeWidgetItem *ajouterRacine(QString &name, QString &description, QVariant &data);

    /**
     * \brief ajouterEnfant
     * ajoute un noeud à un noeud parent
     * \param parent
     * le noeud parent
     * \param name
     * nom du noeud
     * \param description
     * description du noeud
     * \param data
     * donnée à lier au noeud
     * \return noeud créé
     */
    QTreeWidgetItem* ajouterEnfant(QTreeWidgetItem *parent,
                                   QString& name, QString& description, QVariant& data);

    /**
     * \brief ajouterTache
     * ajoute une tâche à un noeud parent
     * \param t
     * tâche à ajouter
     * \param parent
     */
    void ajouterTache(Tache* t, QTreeWidgetItem* parent);

    /**
     * \brief init
     * initialise l'arborescence avec le contenu des manager
     */
    void init();

signals:
    /**
     * \brief previentAccueil
     * prévient le widget accueil qu'il y a eu des changements
     */
    void previentAccueil();
public slots:
    /**
     * \brief showCreateProject
     * créé la fenêtre d'ajout de projet
     */
    void showCreateProject(){
        delete _ajouterProjet;
        _ajouterProjet=new AddProject();
        _ajouterProjet->exec();
        actualiser();
    }

    /**
     * \brief showCreateTache
     * créé la fenêtre d'ajout de tâches
     */
    int showCreateTache(){
        delete _ajouterTache;
        _ajouterTache=new AddTache();
        connect(_ajouterTache,SIGNAL(accepted()),this,SLOT(prevenirAccueil()));
        return _ajouterTache->exec();
    }

    /**
     * \brief actualiser
     * actualise l'affichage de l'arborescence
     */
    void actualiser(){
        _lesProjets->clear();
        init();
    }

    /**
     * \brief clicDroit
     * gère le clic droit sur l'arborescence en ouvrant un menu contextuel
     * \param pos
     * la position de la souris lors du clic
     */
    void clicDroit(QPoint pos);

    /**
     * \brief slotAjouterTache
     * créé la tâche générée par la fenêtre
     */
    void slotAjouterTache();

    /**
     * \brief suppressionNoeud
     * supprime un noeud
     */
    void suppressionNoeud();

    /**
     * \brief exporterProgProjetXML
     * permet l'exportation au format XML des programmations relatives au projet donné
     */
    void exporterProgProjetXML();

    /**
     * \brief lancerEdit
     * edite l'item donné
     * \param item
     * item a éditer
     * \param column
     * colonne à éditer
     */
    void lancerEdit(QTreeWidgetItem* item, int column);

    /**
     * \brief prevenirAccueil
     * prévient l'accueil des changements
     */
    void prevenirAccueil(){
        emit previentAccueil();
    }
};

#endif // PROJECTVIEW_H
