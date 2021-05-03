#include "authentification.h"
#include "ui_authentification.h"

#include <QMessageBox>
authentification::authentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentification)
{
    ui->setupUi(this);
}

authentification::~authentification()
{
    delete ui;
}

void authentification::on_ButtonConnecter_clicked()
{
    QString Indentifiant=ui->lineEdit_Identifiant->text();
    QString motdepasse=ui->lineEdit_motdepasse->text();

    if(Indentifiant=="test"&& motdepasse=="test")
        {
            QMessageBox::information(this,"connecter","connecter");
            //hide();


        }

    else
        {
            QMessageBox::warning(this,"connecter","erreur");
            //hide();
        }
}

void authentification::on_mot_de_passe_oubli_linkActivated(const QString &link)
{
    hide();
    //Dialog = new class Dialog(this);
    //Dialog->show();
}
