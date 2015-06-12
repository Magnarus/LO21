#include "headers/ProgrammationExport.h"

const QString ProgrammationExport::generateFilename(){
    return TExport<Programmation*>::generateFilename() + "programmation_";
}

void ProgrammationExport::exportData(MethodExport *e){
    if(e==NULL && getExportMethod()) throw ExportException("Aucune stratégie d'exportation indiquée. Exportation impossible.");
    if(getExportMethod()==NULL) setExportMethod(e);

}
