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
    void changeDockVisible();
public slots:
    void setTreeOn()
    {
        _mainLayout->removeWidget(_edtInterface);
        _mainLayout->addWidget(_projectTree);
        _edtInterface->hide();
        _projectTree->show();
        emit changeDockVisible();
    }
    void setPlanningOn()
    {
        _mainLayout->removeWidget(_projectTree);
        _mainLayout->addWidget(_edtInterface);
        _projectTree->hide();
        _edtInterface->show();
        emit changeDockVisible();
    }
    void setDate(QDate d)
    {
        _edtInterface->setDate(d);
    }
};

#endif // ACCUEIL_H
