#ifndef EDITEUR_H
#define EDITEUR_H
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
class Editeur : public QWidget
{
protected:
    QPushButton* _valider;
    QHBoxLayout* _buttonLayout;
public:
    Editeur(QWidget* parent=0);
    virtual void initChamps() = 0;
};

#endif // EDITEUR_H
