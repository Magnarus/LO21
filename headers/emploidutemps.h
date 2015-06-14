#ifndef EMPLOIDUTEMPS_H
#define EMPLOIDUTEMPS_H

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QStringList>
#include <QList>
#include <QString>
#include <QHBoxLayout>
#include <QToolButton>
#include <QLineEdit>
#include <string>
#include <sstream>
#include <QHeaderView>
#include <QAbstractItemView>
#include <QIcon>
#include<QCalendarWidget>
#include<QListWidget>
#include<QLabel>
#include"progmanager.h"
#include<qdebug.h>
/**
 * \class EmploiDuTemps emploidutemps.h "headers/emploidutemps.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        08 juin 2015
 * \brief       Implémente la classe EmploiDuTemps
 * \details    Ce widget est l'un des widgets principaux de l'application.
 * Il sert à afficher les programmations pour une semaine donnée au sein d'un tableau
 * faisant office d'agenda.
 * Il permet également de naviguer entre les semaines.
 */
class EmploiDuTemps : public QWidget
{
    Q_OBJECT
    QDate _aujourdhui; /** date sélectionnée */
    QDate _lundi; /** lundi par rapport à la date sélectionnée */
    QDate _dimanche; /** dimanche suivant par rapport à la date sélectionnée */
    QHBoxLayout* _mainLayout; /** layout principal */
    QVBoxLayout* _edtlayout; /** layout du planning */
    QTableWidget* _edt; /** Table qui sert de planning */
    QHBoxLayout* _calendarBarLayout; /** barre de navigation pour le planning */
    QToolButton* _forward; /** bouton qui avance la semaine courante de 1 */
    QToolButton*_next; /** bouton qui recule la semaine courante de 1 */
    QLabel* _dateLabel; /** label qui affiche la date sélectionnée */

public:
    /**
     * \brief EmploiDuTemps constructeur
     * \param parent s'il y en a un
     */
    explicit EmploiDuTemps(QWidget *parent = 0);

    /**
     * \brief setDate modifie la date courante
     * \param d nouvelle date
     */
    void setDate(QDate& d);

    /**
     * \brief getLundi récupère le lundi associé la date courante
     * \return \e QDate qui correspond au lundi
     */
    inline const QDate& getLundi()const{ return _lundi;}
    /**
     * \brief getDimanche récupère le dimanche suivant associé à la date courante
     * \return \e QDate qui correspond au dimanche suivant
     */
    inline const QDate& getDimanche()const{ return _dimanche;}
    ~EmploiDuTemps(){}
signals:
    /**
     * \brief progChanged indique que les programmations affichées sont actualisées
     */
    void progChanged();
public slots:
    /**
     * \brief semaineSuivante modifie les dates de telle sorte à passer à la semaine suivant
     */
    void semaineSuivante();

    /**
     * \brief semainePassee modifie les dates de telle sorte à passer à la semaine précédente
     */
    void semainePassee();

    /**
     * \brief changerProg change les programmations affichées au sein du planning
     */
    void changerProg();
};

#endif // EMPLOIDUTEMPS_H
