#include <QApplication>
#include "../headers/addprog.h"
#include "../headers/addprogunitaire.h"
#include "../headers/accueil.h"
#include "../headers/addproject.h"
#include "../headers/addtache.h"
#include "../headers/edittache.h"
#include "../headers/editproject.h"
#include "../headers/Agenda.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Accueil acc;
    Agenda principale(&acc);
    principale.show();
    //AddProject ap;
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
    return a.exec();
}
