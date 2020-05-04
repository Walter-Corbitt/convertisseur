#include <QtWidgets/QFormLayout>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QComboBox>
#include "Fenetre.h"

#define MILES_KILOMETRES 0
#define KILOMETRES_MILES 1

Fenetre::Fenetre(QWidget *parent):QWidget()
{
    valeur = new QLineEdit(this);
    resultat = new QLabel(this);
    unite = new QLabel(this);
    choixConversion = new QComboBox(this);
    bConvertir = new QPushButton(QString::fromUtf8("Convertir"),this);
    bQuitter = new QPushButton(QString::fromUtf8("Quitter"),this);

    valeur->setStyleSheet("color: #0a214c; background-color: #C19A6B;");
    valeur->clear();
    QFont font("Liberation Sans", 12,QFont::Bold);
    choixConversion->setFont(font);choixConversion->addItem(QString::fromUtf8("Miles -> Kilomètres"));
    choixConversion->addItem(QString::fromUtf8("Kilomètres -> Miles"));
    resultat->setStyleSheet("color: #0a214c;");
    unite->setStyleSheet("color: #0a214c;");

    QHBoxLayout*hLayout1 = new QHBoxLayout;
    QHBoxLayout*hLayout2 = new QHBoxLayout;
    QVBoxLayout*mainLayout = new QVBoxLayout;

    hLayout1->addWidget(valeur);
    hLayout1->addWidget(choixConversion);
    hLayout1->addWidget(resultat);
    hLayout1->addWidget(unite);
    hLayout2->addWidget(bConvertir);
    hLayout2->addWidget(bQuitter);
    mainLayout->addLayout(hLayout1);
    mainLayout->addLayout(hLayout2);
    setLayout(mainLayout);

    connect(bConvertir,SIGNAL(clicked()),this,SLOT(convertir()));
    connect(this,SIGNAL(actualiser()),this,SLOT(convertir()));
    connect(choixConversion,SIGNAL(currentIndexChanged(int)),this,SLOT(permuter(int)));
    connect(bQuitter,SIGNAL(clicked()), qApp,SLOT(quit()));
    connect(valeur,SIGNAL(textChanged(const QString&)),this,SLOT(convertir()));

    setWindowTitle(QString::fromUtf8("Convertisseur de températures"));
    adjustSize();
}


void Fenetre::convertir(){
    QString distance = valeur->text();
    if(distance.isEmpty()){
        resultat->setText(QString::fromUtf8("--.--"));
        afficherUnite();return;
    }
    switch(choixConversion->currentIndex())
    {
        case MILES_KILOMETRES:
            resultat->setText(QString::fromUtf8("%1").arg(distance.toDouble() * 1.609, 0, 'f', 2));
        break;
        case KILOMETRES_MILES:
            resultat->setText(QString::fromUtf8("%1").arg(distance.toDouble() * 0.621371, 0, 'f', 2));
            break;
    }
}


void Fenetre::permuter(int index){
    if(resultat->text() != "--.--"){
        valeur->setText(resultat->text());
        emit actualiser();
    }
    afficherUnite();
}

void Fenetre::afficherUnite(){
    switch(choixConversion->currentIndex())
    {
        case MILES_KILOMETRES:
            unite->setText(QString::fromUtf8("Km"));
            break;
            case KILOMETRES_MILES:
                unite->setText(QString::fromUtf8("Miles"));
                break;
    }
}




