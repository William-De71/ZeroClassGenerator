#ifndef HEADER_FENCODEGENERE
#define HEADER_FENCODEGENERE

#include <QtGui>
#include <QtWidgets>

class FenCodeGenere : public QDialog
{

    Q_OBJECT

    public:
        FenCodeGenere(QString &code, QString &codecpp, QString &nom, QWidget *parent);

    private slots:
        void enregistrerFichier();

    private:
        QString *nomClasse;
        QTabWidget *onglets;
        QTextEdit *codeGenere;
        QTextEdit *codecppgenere;
        QPushButton *enregistrer;
        QPushButton *fermer;

};


#endif
