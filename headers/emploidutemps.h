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
class EmploiDuTemps : public QWidget
{
    Q_OBJECT
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
        _dateLabel->setText(d.toString("dddd dd MMMM yyyy"));
    }

    ~EmploiDuTemps(){}

signals:

public slots:
};

#endif // EMPLOIDUTEMPS_H
