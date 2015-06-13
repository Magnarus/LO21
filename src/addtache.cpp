#include "../headers/addtache.h"

AddTache::AddTache(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Ajouter une tâche");
    _vlayout= new QVBoxLayout(this);
    _datesLayout=new QHBoxLayout;
    _timeLayout=new QHBoxLayout;
    _datetimeLayout=new QVBoxLayout;
    _buttonLayout=new QHBoxLayout;
    _titreLayout=new QHBoxLayout;

    _dateDispo=new QDateEdit(this);
    _duree = new QTimeEdit(this);
    _duree->stepBy(1);
    _duree_l = new QLabel("Durée :",this);
    _dateDispo->setCalendarPopup(true);
    _dateDispo->setMinimumDate(QDate::currentDate());
    _dateEcheance=new QDateEdit(this);
    _dateEcheance->setCalendarPopup(true);
    _dateEcheance->setMinimumDate(QDate::currentDate());
    _dateDispo_l=new QLabel("Date de disponibilité:",this);
    _dateEcheance_l=new QLabel("Date d'échéance:",this);
    _titre=new QLineEdit(this);
    _titre_l=new QLabel("Nom:",this);
    _preemptive=new QCheckBox(this);
    _preemptive_l=new QLabel("Préemptive?",this);
    _unitaire=new QCheckBox(this);
    _unitaire->setChecked(true);
    _unitaire_l=new QLabel("Unitaire?");
    _ajouter=new QPushButton("Ajouter");
    _annuler=new QPushButton("Annuler");

    _titreLayout->addWidget(_titre_l);
    _titreLayout->addWidget(_titre);
    _titreLayout->addWidget(_preemptive_l);
    _titreLayout->addWidget(_preemptive);
    _titreLayout->addWidget(_unitaire_l);
    _titreLayout->addWidget(_unitaire);
    _datesLayout->addWidget(_dateDispo_l);
    _datesLayout->addWidget(_dateDispo);
    _datesLayout->addWidget(_dateEcheance_l);
    _datesLayout->addWidget(_dateEcheance);
    _timeLayout->addWidget(_duree_l);
    _timeLayout->addWidget(_duree);
    _buttonLayout->addWidget(_ajouter);
    _buttonLayout->addWidget(_annuler);

    _datetimeLayout->addLayout(_datesLayout);
    _datetimeLayout->addLayout(_timeLayout);

    _vlayout->addLayout(_titreLayout);
    _vlayout->addLayout(_datetimeLayout);
    _vlayout->addLayout(_buttonLayout);
    connect(_unitaire,SIGNAL(clicked(bool)),this,SLOT(switchingTache(bool)));
    connect(_annuler,SIGNAL(clicked()),this,SLOT(close()));
    connect(_ajouter,SIGNAL(clicked()),this,SLOT(newTache()));
}

void AddTache::newTache()
{
    QMap<QString,QVariant> params;
    params["dispo"]= QVariant(_dateDispo->date());
    params["deadline"] = QVariant(_dateEcheance->date());
    params["titre"] = QVariant(_titre->text());
    try
    {
        if(_unitaire->isChecked())
        {
            params["dur"] = QVariant(_duree->time());
            if(_preemptive->isChecked())
                TacheManager::getInstance()->ajouterItem("PREEMPTIVE",params);
            else
                TacheManager::getInstance()->ajouterItem("NON_PREEMPTIVE",params);
        }
        else
            TacheManager::getInstance()->ajouterItem("COMPOSITE",params);
        QMessageBox::information(this,"ajout réussi","tâche bien ajoutée ! ");
        done(1);
    }
    catch(AgendaException &e)
    {
        QMessageBox::critical(this,"Erreur ajout",e.getInfo());
    }

}
