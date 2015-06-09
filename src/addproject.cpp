#include "../headers/addproject.h"

AddProject::AddProject(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(QString("Créer un projet"));
    _vlayout=new QVBoxLayout(this);
    _titreLayout=new QHBoxLayout();
    _datesLayout=new QHBoxLayout();
    _buttonsLayout=new QHBoxLayout();
    _titre_l=new QLabel("Titre:",this);
    _dateDispo_l=new QLabel("Date de disponibilité:",this);
    _dateEcheance_l=new QLabel("Date d'échéance:",this);
    _ajouter=new QPushButton("Créer le projet",this);
    _annuler=new QPushButton("Annuler",this);
    _titre=new QLineEdit(this);
    _dateDispo=new QDateEdit(this);
    _dateEcheance=new QDateEdit(this);
    _dateDispo->setCalendarPopup(true);
    _dateEcheance->setCalendarPopup(true);

    _titreLayout->addWidget(_titre_l);
    _titreLayout->addWidget(_titre);

    _datesLayout->addWidget(_dateDispo_l);
    _datesLayout->addWidget(_dateDispo);
    _datesLayout->addWidget(_dateEcheance_l);
    _datesLayout->addWidget(_dateEcheance);

    _buttonsLayout->addWidget(_ajouter);
    _buttonsLayout->addWidget(_annuler);

    _vlayout->addLayout(_titreLayout);
    _vlayout->addLayout(_datesLayout);
    _vlayout->addLayout(_buttonsLayout);
    connect(_annuler,SIGNAL(clicked()),this,SLOT(close()));
    connect(_ajouter,SIGNAL(clicked()),this,SLOT(newProject()));
}

void AddProject::newProject()
{
   QDate dd = _dateDispo->date();
   QDate de = _dateEcheance->date();
   QString titre =_titre->text();
   QMap<QString,QVariant> params;
   params["dispo"] = QVariant(dd);
   params["echeance"] = QVariant(de);
   params["titre"] = QVariant(titre);
   try
   {
       ProjetManager::getInstance()->ajouterItem("PROJET",params);
       QMessageBox::information(this,"ajout réussi","projet bien ajouté ! ");
   }
   catch(AgendaException &e)
   {
       QMessageBox::critical(this,"Erreur ajout",e.getInfo());
   }
}


