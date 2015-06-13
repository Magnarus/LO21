#include "../headers/emploidutemps.h"

EmploiDuTemps::EmploiDuTemps(QWidget *parent) : QWidget(parent)
{
    _calendarBarLayout=new QHBoxLayout();
    _aujourdhui = QDate::currentDate();
    int toLundi = _aujourdhui.dayOfWeek()-1;
    int toDimanche = 7-_aujourdhui.dayOfWeek();
    _lundi = _aujourdhui.addDays(-toLundi);
    _dimanche = _aujourdhui.addDays(toDimanche);
    _forward=new QToolButton(this);
    _forward->setIcon(QIcon(":/res/leftarrow.png"));
    _next=new QToolButton(this);
    _next->setIcon(QIcon(":/res/rightarrow.png"));
    _dateLabel=new QLabel(this);
    _calendarBarLayout->addWidget(_forward);
    _calendarBarLayout->addWidget(_dateLabel);
    _calendarBarLayout->addWidget(_next);
    QFont f= _dateLabel->font();
    f.setPixelSize(28);
    _dateLabel->setFont(f);
    _dateLabel->setText(QDate::currentDate().toString("dddd dd MMMM yyyy"));
    _dateLabel->setAlignment(Qt::AlignCenter);
    _edtlayout=new QVBoxLayout();
    _edt=new QTableWidget(24,7,this);
    _edt->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList headers;
    headers.push_back(QString("Lundi"));
    headers.push_back(QString("Mardi"));
    headers.push_back(QString("Mercredi"));
    headers.push_back(QString("Jeudi"));
    headers.push_back(QString("Vendredi"));
    headers.push_back(QString("Samedi"));
    headers.push_back(QString("Dimanche"));

    _edt->setHorizontalHeaderLabels(headers);
    QStringList vheaders;
    std::ostringstream stream;
    for(int i=0;i<24;i++){
        stream << i <<"h00-"<< (i+1)%24 << "h00";
        vheaders.push_back(QString::fromStdString(stream.str()));
        stream.str("");
        stream.clear();
    }
    _edt->setVerticalHeaderLabels(vheaders);
    _edt->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    _edt->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    _edt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _edtlayout->addLayout(_calendarBarLayout);
    _edtlayout->addWidget(_edt);

    _mainLayout = new QHBoxLayout(this);
    _mainLayout->addLayout(_edtlayout);
    this->setLayout(_mainLayout);
    connect(_forward,SIGNAL(clicked()),this,SLOT(semainePassee()));
    connect(_next,SIGNAL(clicked()),this,SLOT(semaineSuivante()));
}
void EmploiDuTemps::setDate(QDate& d)
{
    _aujourdhui = d;
    _dateLabel->setText(d.toString("dddd dd MMMM yyyy"));
    int passerALundi = d.dayOfWeek()-1;
    int passerADimanche = 7 - d.dayOfWeek();
    _lundi = _aujourdhui.addDays(-passerALundi);
    _dimanche = _aujourdhui.addDays(passerADimanche);
    changerProg();
}
void EmploiDuTemps::semaineSuivante()
{
    _aujourdhui = _aujourdhui.addDays(7);
    _dateLabel->setText(_aujourdhui.toString("dddd dd MMMM yyyy"));
    _lundi = _lundi.addDays(7);
    _dimanche = _dimanche.addDays(7);
    changerProg();
}

void EmploiDuTemps::semainePassee()
{
    _aujourdhui = _aujourdhui.addDays(-7);
    _dateLabel->setText(_aujourdhui.toString("dddd dd MMMM yyyy"));
    _lundi = _lundi.addDays(-7);
    _dimanche = _dimanche.addDays(-7);
    changerProg();
}

void EmploiDuTemps::changerProg()
{
    _edt->clearContents();

    QDate dimancheAvant = _lundi.addDays(-1);

    ProgManager::IteratorIntervale it = dynamic_cast<ProgManager*>(ProgManager::getInstance())->getIteratorIntervale(dimancheAvant,dimancheAvant);
    while(it.courant() != it.end())
    {
        qDebug() << "j'en ai trouvé une quand même";
        int jour;
        int heure;
        int duree;
        int difference;
        QString titre;
        QVariant v;
        if (it.valeur()->getType() == PROGTACHE)
        {
            ProgTUnit* p = dynamic_cast<ProgTUnit*>(it.valeur());
            jour = p->getDate().dayOfWeek();
            heure = p->getHoraire().hour();
            duree = p->getDuree().hour();
            titre = p->getProgramme()->getTitre();
            v.setValue(p);
        }
        else
        {
           ProgActivite* p = dynamic_cast<ProgActivite*>(it.valeur());
           jour = p->getDate().dayOfWeek();
           qDebug() << "jour de la semaine : " << jour;
           heure = p->getHoraire().hour();
           duree = p->getDuree().hour();
           titre = p->getProgramme()->getNom();
           v.setValue(p);
        }
        difference = heure+duree;
        qDebug() << "heure + durée = " << difference;
        if(difference >= 24){
           jour=1;
           difference -=24;
           int i=0;
           while(i<difference)
           {
               QTableWidgetItem* item = new QTableWidgetItem();
               item->setData(32,v);
               item->setBackgroundColor(QColor("red"));
               item->setTextColor(QColor("white"));
               item->setText(titre);
               _edt->setItem(i,jour-1,item);
               i++;
           }
        }
        it.next();
    }
    it = dynamic_cast<ProgManager*>(ProgManager::getInstance())->getIteratorIntervale(_lundi,_dimanche);
    while(it.courant() != it.end())
    {
        int jour;
        int heure;
        int duree;
        QString titre;
        QVariant v;
        if (it.valeur()->getType() == PROGTACHE)
        {
            ProgTUnit* p = dynamic_cast<ProgTUnit*>(it.valeur());
            jour = p->getDate().dayOfWeek();
            heure = p->getHoraire().hour();
            duree = p->getDuree().hour();
            titre = p->getProgramme()->getTitre();
            v.setValue(p);
        }
        else
        {
           ProgActivite* p = dynamic_cast<ProgActivite*>(it.valeur());
           jour = p->getDate().dayOfWeek();
           qDebug() << "jour de la semaine : " << jour;
           heure = p->getHoraire().hour();
           duree = p->getDuree().hour();
           titre = p->getProgramme()->getNom();
           v.setValue(p);
        }
        int i=0;
        while (i<duree && jour-1 <7)
        {
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setData(32,v);
            item->setBackgroundColor(QColor("red"));
            item->setTextColor(QColor("white"));
            item->setText(titre);
            if(heure>=24){
                jour++;
                heure -= 24;
            }
            if(jour-1<7)
            {
                _edt->setItem(heure,jour-1,item);
                heure++;
            }
            i++;
        }
        it.next();
    }
    emit progChanged();
}

