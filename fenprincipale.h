#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

#include <QtGui>
#include <QtWidgets>

class FenPrincipale : public QWidget
{
    Q_OBJECT


    public:
        FenPrincipale();

    private slots:
        void genererCode();
        void genererHeader(const QString &nomClasse);
        void voirHeader();

    private:
        QLineEdit *nom;
        QLineEdit *classeMere;
        QCheckBox *protections;
        QLineEdit *header;
        QCheckBox *genererConstructeur;
        QCheckBox *genererDestructeur;
        QGroupBox *groupCommentaires;
        QLineEdit *auteur;
        QDateEdit *date;
        QTextEdit *role;
        QPushButton *generer;
        QPushButton *quitter;

};

#endif
