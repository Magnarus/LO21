#ifndef EMPLOITDUTEMPS_H
#define EMPLOITDUTEMPS_H

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

class EmploitDuTemps : public QWidget
{
    Q_OBJECT
    QVBoxLayout* _layout;
    QTableWidget* _edt;
    QHBoxLayout* _calendarBarLayout;
    QToolButton* _forward,*_next;
    QLineEdit* _dateLabel;

public:
    explicit EmploitDuTemps(QWidget *parent = 0);
    ~EmploitDuTemps();

signals:

public slots:
};

#endif // EMPLOITDUTEMPS_H
