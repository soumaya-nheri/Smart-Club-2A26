
#include "ui_mainwindow.h"
#include "cavalier.h"
#include"QIntValidator"
#include "mainwindow.h"
#include"QMessageBox"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ID->setValidator(new QIntValidator(0,9999999,this));
    ui->Id_2->setValidator(new QIntValidator(0,9999999,this));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{
    int ID=ui->ID->text().toInt ();
    QString nom=ui->nom->text () ;
    QString prenom=ui->prenom->text () ;
    QString dateN=ui->dateN->text () ;
    QString  dateI=ui->dateI->text () ;
    QString type=ui->type->text () ;
    QString Email=ui->Email->text () ;
    QString nomE=ui->nomE->text () ;
    int num=ui->num->text().toInt ();
    QString maladie=ui->maladie->text () ;

 Cavalier c(ID,nom,prenom,dateN,dateI,type ,Email,nomE,num, maladie);


}


void MainWindow::on_afficher_clicked()
{
    Cavalier c ;
    ui->tab_cavalier->setModel(c.afficher()) ;

}



void MainWindow::on_modifier_clicked()
{
        int ID=ui->ID->text().toInt ();
        QString nom=ui->nom->text () ;
        QString prenom=ui->prenom->text () ;
        QString dateN=ui->dateN->text () ;
        QString  dateI=ui->dateI->text () ;
        QString type=ui->type->text () ;
        QString Email=ui->Email->text () ;
        QString nomE=ui->nomE->text () ;
        int num=ui->num->text().toInt ();
        QString maladie=ui->maladie->text () ;
         Cavalier c(ID,nom,prenom,dateN,dateI,type ,Email,nomE,num, maladie);

    bool test1=c.ajouter();
    if(test1)
    {
        QMessageBox::information(nullptr, QObject::tr("Modifier un cavalier"),
                                 QObject::tr("cavalier  modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un cavalier "),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_supprimer_clicked()
{
    Cavalier  c1 ;
    c1.setID(ui->Id_2->text().toInt());
    bool test =c1.supprimer(c1.getID());
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("supprimer un cavalier"),
                                 QObject::tr("cavalier  supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_cavalier->setModel(c1.afficher()) ;

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer un cavalier "),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}
