#ifndef EDITEUR_H
#define EDITEUR_H
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
/**
 * \class Editeur editeur.h "headers/editeur.h"
 * \author      DELAUNAY Grégory et NEVEUX Anaïs
 * \version     1.0
 * \date        08 juin 2015
 * \brief       Implémente la classe Editeur
 * \details    Ce widget est un widget abstrait qui sert de base
 * pour les widget qui servent à éditer des objets déjà existant.
 */
class Editeur : public QWidget
{
    Q_OBJECT
protected:
    QPushButton* _valider; /** bouton de validation*/
    QHBoxLayout* _buttonLayout; /** layout pour les boutons */
signals:
    void modifie();
public:
    Editeur(QWidget* parent=0);
    virtual void initChamps() = 0;
};

#endif // EDITEUR_H
