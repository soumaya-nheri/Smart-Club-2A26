
#include "ui_mainwindow.h"
#include "cavalier.h"
#include"QIntValidator"
#include "mainwindow.h"
#include"QMessageBox"
#include <QPainter>
#include "smtp.h"
#include <QPdfWriter>
#include <QDesktopServices>
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
{
    int id_cavalier=ui->id_cavalier->text().toInt ();
    int id_planning=ui->id_planning->text().toInt ();
    QString horaire=ui->horaire_2->text () ;
    int appreciation=ui->appreciation->text().toInt ();
    int id_coach=ui->id_coach->text().toInt ();
    int id_cheval=ui->id_cheval->text().toInt ();
    int id_evenement=ui->id_evenement->text().toInt ();

 planning_cavalier p(id_cavalier,id_planning,horaire,appreciation,id_coach,id_cheval ,id_evenement);
 bool test=p.ajouter();
 if(test)
 {
     QMessageBox::information(nullptr, QObject::tr("ajouter un cavalier"),
                              QObject::tr("planning_cavalier  ajouté.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tab_cavalier->setModel(p.afficher()) ;

 }
 else
     QMessageBox::critical(nullptr, QObject::tr("ajouter un cavalier "),
                           QObject::tr("Erreur !.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);



}



void MainWindow::on_afficher_planning_2_currentChanged(int index)
{
   planning_cavalier p  ;
    ui->afficher_planning->setModel(p.afficher()) ;
}

void MainWindow::on_supprimer_cavalier_clicked()
{

   planning_cavalier p;
        int id = ui->id_planning_supp->text().toInt();
        bool test=p.supprimer(id);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("supprimer un planning"),
                                     QObject::tr("planning  supprimé.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->afficher_planning->setModel(p.afficher()) ;

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
    smtp* smtp = new smtp("mariem.aljene0@gmail.com","zainebtriki ","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
}

void MainWindow::on_imprimer_planning_clicked()
{ QPdfWriter pdf("C:\\Users\\mariem\\Desktop\\Atelier_Connexion\\cavalier\\PDF.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(1100,1200,"planning de la semaine ");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    painter.drawRect(100,100,7300,2600);

    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(200,3300,"id_cavalier");
    painter.drawText(1700,3300,"id_planning");
    painter.drawText(3200,3300,"horaire");
    painter.drawText(6600,3300,"appreciation");
    painter.drawText(4900,3300,"id_coach");
    painter.drawText(8100,3300,"id_cheval ");
    painter.drawText(9600,3300,"id_evenement ");
    QSqlQuery query;
    query.prepare("select * from planning_cavalier");
    query.exec();
    while (query.next())
    {
        painter.drawText(200,i,query.value(0).toString());
        painter.drawText(1700,i,query.value(1).toString());
        painter.drawText(3200,i,query.value(2).toString());
        painter.drawText(4900,i,query.value(3).toString());
        painter.drawText(6600,i,query.value(4).toString());
        painter.drawText(8100,i,query.value(5).toString());
        painter.drawText(9600,i,query.value(6).toString());

        i = i + 500;
    }
    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:\\Users\\mariem\\Desktop\\Atelier_Connexion\\cavalier\\PDF.pdf"));
        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();

}
}
void MainWindow::on_satat_clicked()
{

}
