
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
    ui->id_planning->setValidator(new QIntValidator(0,9999999,this));


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
bool test=c.ajouter();
if(test)
{QMessageBox msgBox ;
    QMessageBox::information(this,"information","cavalier ajouté");

}
else {QMessageBox msgBox ;
    QMessageBox::information(this,"information","echec lors de l ajout");
 }
}

//void MainWindow::on_afficher_clicked()
//{


//}

void MainWindow::on_affiche_cavaliers_currentChanged(int index)
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

    bool test1=c.modifier(ID, nom,prenom,dateN,dateI, type, Email,nomE,num, maladie);
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
{Cavalier c;
    int id = ui->Id_2->text().toInt();
    bool test=c.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("supprimer un cavalier"),
                                 QObject::tr("cavalier  supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_cavalier->setModel(c.afficher()) ;

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer un cavalier "),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}




void MainWindow::on_ajouter_planning_clicked()
{   int id_cavalier=ui->id_cavalier->text().toInt ();
    int id_planning=ui->id_planning->text().toInt ();
    QString horaire=ui->horaire->text () ;
    int appreciation=ui->appreciation->text().toInt ();
    int id_coach=ui->id_coach->text().toInt ();
    int id_cheval=ui->id_cheval->text().toInt ();
    int id_evenement=ui->id_evenement->text().toInt ();

 planning_cavalier p(id_cavalier,id_planning,horaire,appreciation,id_coach,id_cheval ,id_evenement);


}



void MainWindow::on_afficher_planning_2_currentChanged(int index)
{
   planning_cavalier p  ;
    ui->afficher_planning->setModel(p.afficher()) ;
}

void MainWindow::on_supprimer_cavalier_clicked()
{

    planning_cavalier p1 ;

        int id = ui->id_planning_supp->text().toInt();
        bool test=p1.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("supprimer un planning"),
                                 QObject::tr("planning  supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->afficher_planning->setModel(p1.afficher()) ;

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer un planning "),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_modifier_planning_clicked()
{int id_cavalier=ui->id_cavalier->text().toInt ();
    int id_planning=ui->id_planning->text().toInt ();
    QString horaire=ui->horaire->text () ;
    int appreciation=ui->appreciation->text().toInt ();
    int id_coach=ui->id_coach->text().toInt ();
    int id_cheval=ui->id_cheval->text().toInt ();
    int id_evenement=ui->id_evenement->text().toInt ();

 planning_cavalier p(id_cavalier,id_planning,horaire,appreciation,id_coach,id_cheval ,id_evenement);



bool test1=p.modifier(id_cavalier,id_planning,horaire,appreciation,id_coach,id_cheval ,id_evenement);
if(test1)
{
    QMessageBox::information(nullptr, QObject::tr("Modifier un planning"),
                             QObject::tr("planning  modifié.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Modifier un planning "),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_envoyermail_clicked()
{

}

void MainWindow::on_imprimer_planning_clicked()
{

}

void MainWindow::on_satat_clicked()
{

}
