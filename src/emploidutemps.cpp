#include "../headers/emploidutemps.h"

EmploiDuTemps::EmploiDuTemps(QWidget *parent) : QWidget(parent)
{
    _calendarBarLayout=new QHBoxLayout();
    _forward=new QToolButton(this);
    _next=new QToolButton(this);
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
}


