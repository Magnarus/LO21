#-------------------------------------------------
#
# Project created by QtCreator 2015-05-11T13:51:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjectCalendar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    projet.cpp \
    tache.cpp \
    tache_unitaire.cpp \
    tache_composite.cpp \
    tmanager.cpp \
    tachemanager.cpp

HEADERS  += mainwindow.h \
    projet.h \
    tache.h \
    tache_unitaire.h \
    tache_composite.h \
    tmanager.h \
    tachemanager.h

FORMS    += mainwindow.ui
