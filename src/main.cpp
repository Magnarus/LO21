#include <QApplication>
#include "../headers/addprog.h"
#include "../headers/addprogunitaire.h"
#include "../headers/accueil.h"
#include "../headers/addproject.h"
#include "../headers/addtache.h"
#include "../headers/edittache.h"
#include "../headers/editproject.h"
#include "../headers/Agenda.h"

#include "headers/tachepreemptive.h"
#include "headers/ProgrammationProjetExport.h"
#include "headers/XMLExport.h"
#include "headers/tache_unitaire.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Accueil acc;
    Agenda principale(&acc);
    principale.show();
    //AddProject ap;*/
    //ap.show();
    //AddTache ad;
    //ad.show();
    //EmploiDuTemps edt;
    //edt.show();
    //EditTache e;
    //e.show();
    //EditProject ep;
    //ep.show();
     //AddProgUnitaire ap;
    //ap.exec();
    //Creation d'un projet
    /*QDate dd(2016,6,14);
    QDate de(2016,6,30);
    QString titre("Toto");
    QMap<QString,QVariant> params;
    params["dispo"] = QVariant(dd);
    params["echeance"] = QVariant(de);
    params["titre"] = QVariant(titre);
    ProjetManager::getInstance()->ajouterItem("PROJET",params);
    Projet* p=ProjetManager::getInstance()->getIterator().valeur();
    TachePreemptive* t=new TachePreemptive(1,"titi",QDate(2016,6,14),QDate(2016,6,18),QTime(3,0));
    p->ajouterTache(t);


    //Creation de la programmation de la tache
    QMap<QString,QVariant> params2;
    params2["date"] = QVariant(QDate(2016,6,14));
    params2["duree"]= QVariant(QTime(2,0));
    params2["horaire"] = QVariant(QTime(11,0));;
        QVariant v;
        v.setValue(dynamic_cast<Tache_Unitaire*>(t));
        params2["programme"]=v;
        try{
        ProgManager::getInstance()->ajouterItem("UNITAIRE",params2);


    try{
    ProgrammationProjetExport(p,p->getTitre(),new XMLExport("xml")).exportData();
    }catch(ExportException e){
        qDebug() << e.getInfo();
    }
        }catch(AgendaException aexcp){
            qDebug() << aexcp.getInfo();
        }
*/

    return a.exec();
}
