#ifndef EXPORTVIEW_H
#define EXPORTVIEW_H
#include <QWidget>
/**
 * \class       ExportView ExportView.h "headers/ExportView.h"
 * \author      NEVEUX Anais
 * \version     1.0
 * \date        13 juin 2015
 * \brief       Implémente la classe ExportView
 * \details     La classe ExportView est une vue permettant le choix du type d'exportation et le format.
 */
class ExportView : public QWidget
{
    Q_OBJECT

public:
    explicit ExportView(QWidget *parent = 0);
    ~ExportView(){}

signals:

public slots:

};

#endif //EXPORTVIEW_H
