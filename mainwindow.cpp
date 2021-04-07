#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include "participant.h"
#include "QSqlQuery"
#include <QMessageBox>
#include <QIntValidator>
#include <QQuickItem>
#include <QPixmap>
#include <QPdfWriter>
#include <QPainter>
#include <qdesktopservices.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->id->setValidator(new QIntValidator(0,199,this));
    ui->tableView->setModel(E.afficher());
    class participant P;
    ui->tableView_2->setModel(P.afficher());
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();
    auto obj= ui->quickWidget->rootObject();
    connect(this,SIGNAL( setCenter(QVariant,QVarient)),obj,SLOT(setCenter(QVatriant,QVariant)));
    emit setCenter(25.000,50.000);
    QPixmap pix("C:/Users/Rania/Desktop/pic/horse.png");
    ui->label_pic->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{int id=ui->id->text().toInt();
    QString categorie=ui->categorie->text();
    QString nom=ui->nom->text();
    QString description=ui->description->text();
    QString date=ui->date->text();
    QString resultat=ui->resultat->text();
    int nb_participant=ui->nb_participant->text().toInt();
    int nb_cheval=ui->nb_cheval->text().toInt();
    int nb_coach=ui->nb_coach->text().toInt();
    int nb_spectacle=ui->nb_spectacle->text().toInt();
class event E(id, categorie, nom, description, date,resultat, nb_participant, nb_cheval, nb_coach, nb_spectacle);
bool test=E.ajouter();

foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
le->clear();
}
if(test)
{
ui->tableView->setModel(E.afficher());

QMessageBox::information(nullptr, QObject::tr("Ajout effectue"),
QObject::tr("OK.\n"
"Click Cancel to exit."), QMessageBox::Cancel);

}
else
QMessageBox::critical(nullptr, QObject::tr("Ajout non effectue"),
QObject::tr("KO.\n"
"Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->id_2->text().toInt();
    QString categorie=ui->categorie_2->text();
    QString nom=ui->nom_3->text();
    QString description=ui->description_2->text();
    QString date=ui->date_2->text();
    QString resultat=ui->resultat_2->text();
    int nb_participant=ui->nb_places->text().toInt();
    int nb_cheval=ui->nb_cheval_2->text().toInt();
    int nb_coach=ui->nb_coach_2->text().toInt();
    int nb_spectacle=ui->nb_spectacle_2->text().toInt();


   class event E;
    bool test=E.modifier(id, categorie, nom, description, date,resultat, nb_participant, nb_cheval, nb_coach, nb_spectacle);

    if(test)
    {
        ui->tableView->setModel(E.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifie une fonction"),
                          QObject::tr("fonctin modifiée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_pb_supprimer_clicked()
{
    int id = ui->supp->text().toInt();
    bool test=E.supprimer(id);
    if(test)
    {ui->tableView->setModel(E.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Projet"),
                    QObject::tr("Projet supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Projet"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_ajouter2_clicked()
{
    int id_participant=ui->id_participant->text().toInt();
    QString nom=ui->nom_2->text();
    QString prenom=ui->prenom->text();
    int cin=ui->cin->text().toInt();
    int id_event=ui->id_event->text().toInt();
    class participant P(id_participant, nom, prenom, cin,id_event);
    bool test=P.ajouter();

    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
    le->clear();
    }
    if(test)
    {
    ui->tableView_2->setModel(P.afficher());

    QMessageBox::information(nullptr, QObject::tr("Ajout effectue"),
    QObject::tr("OK.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    QMessageBox::critical(nullptr, QObject::tr("Ajout non effectue"),
    QObject::tr("KO.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pb_rechercher_clicked()
{
    QString categorie;

        categorie=ui->lineEdit->text();
    bool test= true;
    if(test==(true))
    {
      ui->tableView->setModel(E.rechercher(categorie));
}
}

void MainWindow::on_pb_modifier2_clicked()
{
    int id_participant = ui->lineEdit_1->text().toInt();
       QString nom= ui->lineEdit_2->text();
       QString prenom= ui->lineEdit_3->text();
       int cin= ui->lineEdit_4->text().toInt();
       int id_event= ui->lineEdit_5->text().toInt();


       participant P;
       bool test=P.modifier(id_participant,nom,prenom,cin,id_event);
       foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
          le->clear();
       }
       if(test)
       {
           ui->tableView_2->setModel(P.afficher());

           QMessageBox::information(nullptr, QObject::tr("Modification effectue"),
                       QObject::tr("OK.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("Modification non effectue"),
                       QObject::tr("KO.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_pdf_clicked()
{

        QPdfWriter pdf("C:/Users/Rania/Desktop/pic/pdf.pdf");
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(1100,1200,"Liste Des evenements ");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        painter.drawRect(100,100,7300,2600);

        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(200,3300,"id_event");
        painter.drawText(1700,3300,"categorie");
        painter.drawText(3200,3300,"date");
        painter.drawText(6600,3300,"nb_participant");
        painter.drawText(4900,3300,"nb_cheval");
        painter.drawText(8100,3300,"nb_coach");

        QSqlQuery query;
        query.prepare("select * from event");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1700,i,query.value(1).toString());
            painter.drawText(3200,i,query.value(2).toString());
            painter.drawText(4900,i,query.value(3).toString());
            painter.drawText(6600,i,query.value(4).toString());
            painter.drawText(8100,i,query.value(5).toString());

            i = i + 500;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Rania/Desktop/pic/pdf.pdf"));
            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();
        }

}


