#include "../headers/programmation.h"
#include "../headers/progmanager.h"
Programmation::Programmation(const int id, const QDate &d, const QTime &dur, const QTime &h):id(id),date(d),duree(dur),horaire(h)
{
   ProgManager::Iterator it = ProgManager::getInstance()->getIterator();
   int jour = d.day();
   int debut = h.hour();
   int fin = debut + dur.hour();
   bool commencePendant=false;
   bool terminePendant=false;
   bool memeJour=false;
   while(it.courant() != ProgManager::getInstance()->end())
   {
       Programmation *p = it.valeur();
       int pH = p->getHoraire().hour();
       int pFin = pH + p->getDuree().hour();
       int pJour = it.valeur()->getDate().day();
       commencePendant = (debut >= pH && debut <= pFin);
       terminePendant = (fin >= pH && fin <= pFin);
       memeJour = jour == pJour;
       if( memeJour && (commencePendant || terminePendant))
               throw AgendaException("Une programmation occupe déjà une partie de cette plage horaire");
       it.next();
   }
}
