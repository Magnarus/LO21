#include "headers/ProgrammationSemaineExport.h"

const QString ProgrammationSemaineExport::generateFilename(){
    return ProgrammationExport::generateFilename()+"week_"+_debutSemaine.toString()+"_"+_finSemaine.toString();
}

QVector<Programmation*> ProgrammationSemaineExport::findElements(){
    QVector<Programmation*> result;
    QDateTime tmp;
    for(ProgManager::Iterator it=ProgManager::getInstance()->getIterator(); it.courant()!=ProgManager::getInstance()->end();it.next()){
        tmp.setDate(it.valeur()->getDate());
        tmp.setTime(it.valeur()->getHoraire());
        tmp.addMSecs(it.valeur()->getHoraire().msec());
        //Si une programmation est à cheval entre une semaine et une autre, on va quand même l'exporter
        if(it.valeur()->getDate()<_debutSemaine && tmp.date()>_debutSemaine){
            result.push_back(it.valeur());
        }else if(it.valeur()->getDate()>=_debutSemaine && it.valeur()->getDate()<=_finSemaine){
            result.push_back(it.valeur());
        }
    }
    return result;
}
