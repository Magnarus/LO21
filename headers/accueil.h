#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include "emploidutemps.h"
#include "projectview.h"

class Accueil : public QWidget
{
    Q_OBJECT
    QComboBox* _chooseInterface;
    QVBoxLayout* _mainLayout;
    EmploiDuTemps* _edtInterface;
    ProjectView *_projectTree;
public:
    explicit Accueil(QWidget *parent = 0);
    ~Accueil();

signals:

public slots:
    void changeInterface(QString q){
        if(q.compare("Emploi du temps")){
            _mainLayout->removeWidget(_edtInterface);
            _mainLayout->addWidget(_projectTree);
            _edtInterface->hide();
            _projectTree->show();
        }else{
            _mainLayout->removeWidget(_projectTree);
            _mainLayout->addWidget(_edtInterface);
            _projectTree->hide();
            _edtInterface->show();
        }
    }

};

#endif // ACCUEIL_H
