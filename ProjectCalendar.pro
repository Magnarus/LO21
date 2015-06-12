CONFIG += C++11
QT += core gui widgets xml

HEADERS += \
    headers/ajouteur.h \
    headers/ajouteurprojet.h \
    headers/ajouteurtache.h \
    headers/ajouteurtachecomposite.h \
    headers/ajouteurtacheunitaire.h \
    headers/projet.h \
    headers/projetmanager.h \
    headers/tache.h \
    headers/tache_composite.h \
    headers/tache_unitaire.h \
    headers/tachemanager.h \
    headers/tmanager.h \
    headers/programmation.h \
    headers/activite.h \
    headers/ajouteurprogrammation.h \
    headers/ajouteurprogtunit.h \
    headers/ajouteurprogactivite.h \
    headers/progmanager.h \
    headers/progactivite.h \
    headers/progtunit.h \
    headers/tachepreemptive.h \
    headers/tachenonpreemptive.h \
    headers/ajouteurtachepreemptive.h \
    headers/ajouteurtachenonpreemptive.h \
    headers/agendaexception.h \
    headers/etats.h \
    headers/accueil.h \
    headers/addproject.h \
    headers/addtache.h \
    headers/editproject.h \
    headers/edittache.h \
    headers/emploidutemps.h \
    headers/projectview.h \
    headers/Agenda.h \
    headers/editeur.h \
    headers/addprog.h \
    headers/addprogunitaire.h \
    headers/ajouteuractivite.h \
    headers/activitemanager.h \
    headers/MethodExport.h \
    headers/ProgrammationExport.h \
    headers/SimpleFileExport.h \
    headers/TExport.h \
    headers/XMLExport.h \
    headers/exportexception.h \
    headers/addprogactivite.h

SOURCES += \
    src/ajouteur.cpp \
    src/ajouteurprojet.cpp \
    src/ajouteurtache.cpp \
    src/ajouteurtachecomposite.cpp \
    src/ajouteurtacheunitaire.cpp \
    src/main.cpp \
    src/projet.cpp \
    src/projetmanager.cpp \
    src/tache.cpp \
    src/tache_composite.cpp \
    src/tache_unitaire.cpp \
    src/tachemanager.cpp \
    src/tmanager.cpp \
    src/programmation.cpp \
    src/activite.cpp \
    src/tachenonpreemptive.cpp \
    src/ajouteurtachepreemptive.cpp \
    src/ajouteurtachenonpreemptive.cpp \
    src/ajouteurprogactivite.cpp \
    src/ajouteurprogtunit.cpp \
    src/progmanager.cpp \
    src/progactivite.cpp \
    src/progtunit.cpp \
    src/accueil.cpp \
    src/addtache.cpp \
    src/editproject.cpp \
    src/edittache.cpp \
    src/emploidutemps.cpp \
    src/projectview.cpp \
    src/agenda.cpp \
    src/addproject.cpp \
    src/editeur.cpp \
    src/addprog.cpp \
    src/addprogunitaire.cpp \
    src/ajouteuractivite.cpp \
    src/activitemanager.cpp \
    src/MethodExport.cpp \
    src/ProgrammationExport.cpp \
    src/SimpleFileExport.cpp \
    src/TExport.cpp \
    src/XMLExport.cpp \
    src/exportexception.cpp \
    src/addprogactivite.cpp

RESOURCES += \
    resGraphiques.qrc
