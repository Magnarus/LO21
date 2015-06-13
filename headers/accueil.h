#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QWidget>
#include <QMainWindow>
#include <QComboBox>
#include <QVBoxLayout>
#include "emploidutemps.h"
#include "projectview.h"

class Accueil : public QWidget
{
    Q_OBJECT
    QVBoxLayout* _mainLayout;
    EmploiDuTemps* _edtInterface;
    ProjectView *_projectTree;
public:
    explicit Accueil(QWidget *parent = 0);
    ~Accueil(){}

signals:
    void changeDockVisible(bool);
public slots:
    void setTreeOn()
    {
        _mainLayout->removeWidget(_edtInterface);
        _mainLayout->addWidget(_projectTree);
        _edtInterface->hide();
        _projectTree->show();
        emit changeDockVisible(false);
    }
    void setPlanningOn()
    {
        _mainLayout->removeWidget(_projectTree);
        _mainLayout->addWidget(_edtInterface);
        _projectTree->hide();
        _edtInterface->show();
        emit changeDockVisible(true);
    }
    void setDate(QDate d)
    {
        _edtInterface->setDate(d);
    }
    void majEDT()
    {
        qDebug() << "trigerred";
        _edtInterface->changerProg();
    }
};

#endif // ACCUEIL_H
