
#ifndef LOGIN_FENETRE_H
#define LOGIN_FENETRE_H

#include <QtWidgets/QFormLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QApplication>

class Fenetre: public QWidget {

Q_OBJECT
public:
    Fenetre(QWidget *parent = 0 );

public slots:
    void convertir();
    void permuter(int index);

signals:
    void actualiser();

private:
    QLineEdit *valeur;
    QLabel *resultat;
    QLabel *unite;
    QComboBox *choixConversion;
    QPushButton *bConvertir;
    QPushButton *bQuitter;
    QDoubleValidator *doubleValidator;
    void afficherUnite();
};


#endif //LOGIN_FENETRE_H