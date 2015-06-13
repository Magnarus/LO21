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
#include<qdebug.h>
class EmploiDuTemps : public QWidget
{
    Q_OBJECT
    QDate _aujourdhui, _lundi, _dimanche;
    QHBoxLayout* _mainLayout;
    QVBoxLayout* _edtlayout;
    QTableWidget* _edt;
    QHBoxLayout* _calendarBarLayout;
    QToolButton* _forward,*_next;
    QLabel* _dateLabel;

public:
    explicit EmploiDuTemps(QWidget *parent = 0);
    void setDate(QDate& d)
    {
        _aujourdhui = d;
        _dateLabel->setText(d.toString("dddd dd MMMM yyyy"));
        int passerALundi = d.dayOfWeek()-1;
        int passerADimanche = 7 - d.dayOfWeek();
        _lundi = _aujourdhui.addDays(-passerALundi);
        _dimanche = _aujourdhui.addDays(passerADimanche);
    }

    ~EmploiDuTemps(){}

signals:

public slots:
    void semaineSuivante();
    void semainePassee();
};

#endif // EMPLOIDUTEMPS_H
