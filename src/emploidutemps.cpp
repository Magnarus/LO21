#include "../headers/emploidutemps.h"

EmploiDuTemps::EmploiDuTemps(QWidget *parent) : QWidget(parent)
{
    _layout=new QVBoxLayout(this);

    _calendarBarLayout=new QHBoxLayout();
    _forward=new QToolButton(this);
    _next=new QToolButton(this);
    _dateLabel=new QLineEdit(this);
    _calendarBarLayout->addWidget(_forward);
    _calendarBarLayout->addWidget(_dateLabel);
    _calendarBarLayout->addWidget(_next);
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
    _layout->addLayout(_calendarBarLayout);
    _layout->addWidget(_edt);
    this->setLayout(_layout);
}

EmploiDuTemps::~EmploiDuTemps()
{
    delete _dateLabel;
    delete _forward;
    delete _next;
    delete _calendarBarLayout;
    delete _edt;
    delete _layout;
}

