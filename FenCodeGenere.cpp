#include "FenCodeGenere.h"

FenCodeGenere::FenCodeGenere(QString &code,QString &codecpp, QString &nom, QWidget *parent = 0) : QDialog(parent)
{

    nomClasse = new QString(nom);

    // Création du QTabWidget
    onglets = new QTabWidget();
    onglets->setGeometry(30,20,240,160);

    // Création des onglets
    QWidget *page1 = new QWidget();
    QWidget *page2 = new QWidget();


    //Création du contenu des onglets

        // Page 1 classe.h
        codeGenere = new QTextEdit();
        codeGenere->setPlainText(code);
        codeGenere->setReadOnly(true);
        codeGenere->setFont(QFont("Courier"));
        codeGenere->setLineWrapMode(QTextEdit::NoWrap);

        QVBoxLayout *layoutPage1 = new QVBoxLayout;
        layoutPage1->addWidget(codeGenere);

        page1->setLayout(layoutPage1);


        // Page 2 classe.cpp
        codecppgenere = new QTextEdit();
        codecppgenere->setPlainText(codecpp);
        codecppgenere->setReadOnly(true);
        codecppgenere->setFont(QFont("Courier"));
        codecppgenere->setLineWrapMode(QTextEdit::NoWrap);

        QVBoxLayout *layoutPage2 = new QVBoxLayout;
        layoutPage2->addWidget(codecppgenere);

        page2->setLayout(layoutPage2);

    // Ajout des onglets au QTabWidget avec un titre
    onglets->addTab(page1,nom + ".h");
    onglets->addTab(page2,nom + ".cpp");

    // Création des boutons
    fermer = new QPushButton("Fermer");
    enregistrer = new QPushButton("Enregistrer");

    QHBoxLayout *layoutBtn = new QHBoxLayout();
    layoutBtn->setAlignment(Qt::AlignRight);

    layoutBtn->addWidget(enregistrer);
    layoutBtn->addWidget(fermer);

    // Définition du layout principal
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(onglets);
    layout->addLayout(layoutBtn);


    setLayout(layout);
    resize(350, 450);

    // Connexions des signaux et des slots
    connect(fermer, SIGNAL(clicked()), this, SLOT(accept()));
    connect(enregistrer, SIGNAL(clicked()), this, SLOT(enregistrerFichier()));
}

void FenCodeGenere::enregistrerFichier()
{
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", *nomClasse, "Tous les fichiers(*)");
    if(!fichier.isEmpty())
    {
        //Enregistrement
        // .h
        QFile saveH(fichier + ".h");
        if(saveH.open(QFile::WriteOnly))
        {
            QTextStream out(&saveH);
            out << codeGenere->toPlainText();
        }
        // .cpp
        QFile saveCpp(fichier + ".cpp");
        if (saveCpp.open(QFile::WriteOnly))
        {
            QTextStream out(&saveCpp);
            out << codecppgenere->toPlainText();
        }
    }
}
