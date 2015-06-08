#ifndef ACCEUIL_H
#define ACCEUIL_H

#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include "emploitdutemps.h"
#include "projectview.h"

class Acceuil : public QWidget
{
    Q_OBJECT
    QComboBox* _chooseInterface;
    QVBoxLayout* _mainLayout;
    EmploitDuTemps* _edtInterface;
    projectView *_projectTree;
public:
    explicit Acceuil(QWidget *parent = 0);
    ~Acceuil();

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

#endif // ACCEUIL_H
