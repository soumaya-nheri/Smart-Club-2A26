#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>

admin::admin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_connecter_clicked()
{
    QString Indentifiant=ui->lineEdit_Identifiant->text();
    QString motdepasse=ui->lineEdit_motdepasse->text();

    if(Indentifiant=="test"&& motdepasse=="test")
        {
            QMessageBox::information(this,"connecter","connecter");
            hide();
            MainWindow = new class MainWindow(this);
            MainWindow->show();
        }

    else
        {
            QMessageBox::warning(this,"connecter","erreur");
        }
}


/*void MainWindow::on_modepasseoublie_clicked()
{
    hide();
    Dialog = new class Dialog(this);
    Dialog->show();
}
