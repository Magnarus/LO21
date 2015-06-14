#include "../headers/programmation.h"
#include "../headers/progmanager.h"
Programmation::Programmation(const int id, const QDate &d, const QTime &dur, const QTime &h):id(id),date(d),duree(dur),horaire(h)
{
   ProgManager::Iterator it = ProgManager::getInstance()->getIterator();
   int jour = d.day();
   /*int debut = h.hour();
   int fin = debut + dur.hour();*/
   QTime debut=h;
   QTime fin;
   fin.setHMS(h.hour()+dur.hour(),h.minute()+dur.minute(),h.second()+dur.second());
   /*bool commencePendant=false;
   bool terminePendant=false;*/
   bool horaireinvalide=false;
   bool memeJour=false;
   while(it.courant() != ProgManager::getInstance()->end())
   {
       Programmation *p = it.valeur();
       /*int pH = p->getHoraire().hour();
       int pFin = pH + p->getDuree().hour();*/
       int pJour = it.valeur()->getDate().day();
     /*  commencePendant = (debut >= pH && debut <= pFin); //On autorise qu'un evenement se finisse à une heure h et qu'un autre commence tout de suite après
       terminePendant = (fin >= pH && fin <= pFin);*/
       QTime pDeb=p->getHoraire();
       QTime pFin;
       pFin.setHMS(p->getHoraire().hour()+p->getDuree().hour(),p->getHoraire().minute()+p->getDuree().minute(),p->getHoraire().second()+p->getDuree().second());
       /*commencePendant= (debut>=pDeb && debut<pFin);
       terminePendant= (fin>pDeb && fin<=pFin);*/
       horaireinvalide=(debut<=pDeb && fin>=pFin)
               || (debut<=pDeb && (fin<=pFin && fin>pDeb))
               || ((debut>=pDeb && debut<pFin) && fin>=pFin)
               || ((debut>=pDeb && debut<pFin) && (fin>=pDeb && fin<=pFin));
       memeJour = jour == pJour;
       if( memeJour && horaireinvalide)
               throw AgendaException("Une programmation occupe déjà une partie de cette plage horaire");
       it.next();
   }
}
