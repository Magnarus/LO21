#include "../headers/addprogactivite.h"

AddProgActivite::AddProgActivite(QWidget *parent):AddProg(parent)
{
    setWindowTitle("Ajout d'une programmation d'activite");
    _activite = new QFormLayout;
    _dateAct = new QDateEdit(this);
    _dateAct->setDate(QDate::currentDate());
    _dateAct->setEnabled(false);
    _dureeAct = new QTimeEdit(this);
    _dureeAct->setEnabled(false);
    _titreAct = new QLineEdit(this);
    _activite->addRow("Titre Activite : ",_titreAct);
    _activite->addRow("Date Activite : ", _dateAct);
    _activite->addRow("Duree Activite : ",_dureeAct);
    _contour = new QGroupBox("Nouvelle Activite");
    _contour->setLayout(_activite);
    _mainLayout->addWidget(_contour);
    _mainLayout->addLayout(_buttonLayout);
    connect(_valider,SIGNAL(clicked()),this,SLOT(creation()));
    connect(_duree,SIGNAL(timeChanged(QTime)),this,SLOT(majDuree(QTime)));
    connect(_date,SIGNAL(dateChanged(QDate)),this,SLOT(majDate(QDate)));

}

void AddProgActivite::creation()
{
    QMap<QString,QVariant> params;
    params["date"] = QVariant(_dateAct->date());
    params["duree"] = QVariant(_dureeAct->time());
    params["nom"] = QVariant(_titreAct->text());
    try
    {
        ActiviteManager::getInstance()->ajouterItem("ACTIVITE",params);
        QMap<QString,QVariant> paramsProg;
        paramsProg["date"] = QVariant(_date->date());
        paramsProg["duree"]= QVariant(_duree->time());
        paramsProg["horaire"] = QVariant(_horaire->time());
        Activite* a = ActiviteManager::getInstance()->getDernierItem();
        QVariant p;
        p.setValue(a);
        paramsProg["programme"] = p;
        ProgManager::getInstance()->ajouterItem("ACTIVITE",paramsProg);
        QMessageBox::information(this,"ajout réussi","programmation bien ajoutée !");
        done(1);
    }
    catch(AgendaException &e)
    {
        QMessageBox::critical(this,"Erreur ajout",e.getInfo());
        done(0);
    }
}
