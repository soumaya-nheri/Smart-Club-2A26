#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "staff.h"
#include "planning.h"
#include  <QMessageBox>
#include   <QIntValidator>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include  <QUrl>
#include  <QPrinter>
#include  <QFileDialog>
#include <QTextDocument>
#include "mailing/SmtpMime"
#include  <QDialog>

#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
  ui->tabstaff->setModel(tmpstaff.afficher());
   // ui->lineedit_id->setValidator(new QIntValidator(100, 999, this));
   ui->tableView2->setModel(tmpplanning.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString type= ui->comboBox_type->currentText();
    int numero = ui->lineEdit_numero->text().toInt();
    QString adresse= ui->lineEdit_adresse->text();
    int salaire= ui->lineEdit_salaire->text().toInt();
    QString date_naiss = ui->lineEdit_date->text();
    QString email = ui->lineEdit_email->text();
    QString diplome = ui->lineEdit_diplome->text();
    QString activite = ui->lineEdit_activite->text();



  Staff e(id,nom,prenom,date_naiss,adresse,email,type,activite,diplome,numero,salaire);
  bool test=e.ajouter();
  if(test)
{

     ui->tabstaff->setModel(tmpstaff.afficher());
QMessageBox::information(nullptr, QObject::tr("Ajouter un projet"),
                  QObject::tr("Projet ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Projet"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString type= ui->comboBox_type->currentText();
    int numero = ui->lineEdit_numero->text().toInt();
    QString adresse= ui->lineEdit_adresse->text();
    int salaire= ui->lineEdit_salaire->text().toInt();
    QString date_naiss = ui->lineEdit_date->text();
    QString email = ui->lineEdit_email->text();
    QString diplome = ui->lineEdit_diplome->text();
    QString activite = ui->lineEdit_activite->text();



        Staff f;
        bool test=f.modifier(id,nom,prenom,date_naiss,adresse,email,type,activite,diplome,numero,salaire);

        if(test)
        {
            ui->tabstaff->setModel(tmpstaff.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifie une fonction"),
                              QObject::tr("fonctin modifiée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_3_clicked()
{
    int id = ui->lineEdit_sup->text().toInt();
    bool test=tmpstaff.supprimer(id);
    if(test)
    {ui->tabstaff->setModel(tmpstaff.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Projet"),
                    QObject::tr("Projet supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Projet"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{
    int id;

        id=ui->lineEdit_recherche->text().toInt();
    bool test= true;
    if(test==(true))
    {
      ui->tabstaff->setModel(tmpstaff.rechercher(id));
}
}

void MainWindow::on_pushButton_6_clicked()
{
    QString str;
    str.append("<html><head></head><body><center>"+QString("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;;<font size=""10"" color =""red""> GESTION DE STAFF </font><br /> <br /> "));
    str.append("<table border=1><tr>");
    str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">id</font>&nbsp;&nbsp;"+"</td>");
    str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">nom</font>&nbsp;&nbsp;"+"</td>");
    str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">Prenom</font>&nbsp;&nbsp;"+"</td>");
    str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""20"">adresse</font>&nbsp;&nbsp;")+"</td>");
    str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">numero</font>&nbsp;&nbsp;")+"</td>");
    str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">diplome</font>&nbsp;&nbsp;")+"</td>");
    str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">salaire</font>&nbsp;&nbsp;")+"</td>");
    str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">email</font>&nbsp;&nbsp;")+"</td>");
    str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">activite</font>&nbsp;&nbsp;")+"</td>");
    str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">type</font>&nbsp;&nbsp;")+"</td>");
    QSqlQuery * query=new QSqlQuery();
    query->exec("SELECT nom,prenom,adresse,numero FROM staff");
    while(query->next())
    {
        str.append("<tr><td>");
        str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(0).toString()+"&nbsp;&nbsp;");
        str.append("</td><td>");
        str.append("&nbsp;&nbsp;<font color =""green""  size=""10"">"+query->value(1).toString()+"&nbsp;&nbsp;");
        str.append("</td><td>");
        str.append("&nbsp;&nbsp;<font color =""green"" size=""10"">"+query->value(2).toString()+"&nbsp;&nbsp;");
         str.append("</td><td>");
        str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(3).toString()+"&nbsp;&nbsp;");
        str.append("</td></tr>");
        str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(4).toString()+"&nbsp;&nbsp;");
        str.append("</td></tr>");
        str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(5).toString()+"&nbsp;&nbsp;");
        str.append("</td></tr>");
        str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(6).toString()+"&nbsp;&nbsp;");
        str.append("</td></tr>");
        str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(7).toString()+"&nbsp;&nbsp;");
        str.append("</td></tr>");
        str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(8).toString()+"&nbsp;&nbsp;");
        str.append("</td></tr>");
        str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(9).toString()+"&nbsp;&nbsp;");
        str.append("</td></tr>");

}

    str.append("</table></center><body></html>");

    QPrinter printer;
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);

    QString path= QFileDialog::getSaveFileName(NULL,"imprimer","gestion des Staff","PDF(*.pdf");
     if(path.isEmpty()) return;
     printer.setOutputFileName(path);
     QTextDocument doc;
     doc.setHtml(str);
     doc.print(&printer);
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->tabstaff->setModel( tmpstaff.afficher_tri());
    ui->tabstaff->setModel( tmpstaff.afficher_tri());
}

void MainWindow::on_pushButton_8_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

           smtp.setUser("eya.dhamna@esprit.tn");
           smtp.setPassword("eya123");

           MimeMessage message;

           message.setSender(new EmailAddress("eya.dhamna@esprit.tn", "EYA"));
           message.addRecipient(new EmailAddress(ui->lineEdit_email_2->text(), "EYA"));
           message.setSubject("Service Client");

           MimeText text;
           QString text1 = ui->textEdit->toPlainText();
           text.setText(text1);

           message.addPart(&text);

           smtp.connectToHost();

           smtp.login();
           smtp.sendMail(message);
           QMessageBox::information(nullptr, QObject::tr("mail envoyer"),
                       QObject::tr("mail envoyer.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           smtp.quit();
}
int MainWindow::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from staff where salaire BETWEEN '0' AND '100'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int MainWindow::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from staff where salaire BETWEEN '200' AND '300'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int MainWindow::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from staff where salaire BETWEEN '300' AND '400'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}
void MainWindow::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
   // cout<<b<<endl ;
    int c=Statistique_partie3();
    //cout<<c<<endl ;
    int d=Statistique_partie4();
   // cout<<d<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c+d ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z  ;
        z=360-(y+m) ;
    QPainter painter(this);
    QRectF size=QRectF(10,10,this->width()-100,this->width()-100);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,5*y);
    ui->label_bleu->setText("0-100") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,5*y,5*m);
    ui->label_vert->setText("101-200") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,5*(m+y),5*z);
    ui->label_rouge->setText("201-300") ;

}



void MainWindow::on_ajouter2_clicked()
{
    int id_planning=ui->l1->text().toInt();
    int nb_heures=ui->l2->text().toInt();
        QString cours=ui->l3->text();
        QString jours_feriers=ui->l4->text();


    class planning P(id_planning, nb_heures, cours,jours_feriers);
    bool test=P.ajouter();

    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
    le->clear();
    }
    if(test)
    {
        class planning P;
   ui->tableView2->setModel(P.afficher());

    QMessageBox::information(nullptr, QObject::tr("Ajout effectue"),
    QObject::tr("OK.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    QMessageBox::critical(nullptr, QObject::tr("Ajout non effectue"),
    QObject::tr("KO.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supp_clicked()
{
    int id_planning = ui->supp2->text().toInt();
    class planning P;
    bool test=P.supprimer(id_planning);
    if(test)
    {ui->tableView2->setModel(P.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Projet"),
                    QObject::tr("Projet supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Projet"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_modifier_clicked()
{
    int id_planning = ui->l1->text().toInt();
    int nb_heures= ui->l2->text().toInt();
    QString cours= ui->l3->text();
    QString jours_feriers= ui->l4->text();





        planning P;
        bool test=P.modifier(id_planning,nb_heures,cours,jours_feriers);

        if(test)
        {
            ui->tableView2->setModel(P.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifie une fonction"),
                              QObject::tr("fonctin modifiée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_ajouter_2_clicked()
{
    app=new CToDoList();
    app->show();
}
