CONFIG += C++11
QT += widgets

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
    headers/etats.h

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
    src/progtunit.cpp
