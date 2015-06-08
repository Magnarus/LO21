#include <QApplication>
#include "acceuil.h"
#include "addproject.h"
#include "addtache.h"
#include "edittache.h"
#include "editproject.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Acceuil accueil;
    accueil.show();
    //AddProject ap;
    //ap.show();
    //addTache ad;
    //ad.show();
    //EditTache e;
    //e.show();
  //  EditProject ep;
  //  ep.show();
    return a.exec();
}
