#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "planningcheval.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}








void MainWindow::on_ajouter_clicked()
{
        int Id_cheval=ui->Id_cheval->text().toInt ();
        QString Nom_activite=ui->Nom_activite->text () ;
        QString date_activite=ui->date_activite->text () ;
        int duree=ui->duree->text().toInt ();
        QString Id_cavalier=ui->Id_cavalier->text () ;
        planningCheval P(Id_cheval,Nom_activite,date_activite,duree,Id_cavalier);

}

void MainWindow::on_afficher_clicked()
{ planningCheval P ;
    ui->tab_planning->setModel(P.afficher()) ;

}

void MainWindow::on_modifier_clicked()
{

}

void MainWindow::on_supprimer_clicked()
{
    planningCheval  P ;
        P.setId_cheval(ui->Id_cheval2->text().toInt());
        bool test =P.supprimer(P.getId_cheval());
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("supprimer un cavalier"),
                                     QObject::tr("cavalier  supprimé.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_cavalier->setModel(P.afficher()) ;

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("supprimer un cavalier "),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

}
