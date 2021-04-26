
#include "ui_mainwindow.h"
#include "cavalier.h"
#include"QIntValidator"
#include "mainwindow.h"
#include"QMessageBox"
#include <QPainter>


#include "qcustomplot.h"
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include<QComboBox>
#include <QMessageBox>
#include <QDebug>
#include<QSystemTrayIcon>
#include<QObject>

#include <QMessageBox>

#include<smtp.h>

#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>

#include <QPrinter>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include"QSortFilterProxyModel"

#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include"QSortFilterProxyModel"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::makePlot();
    // arduino
    int ret=A.connect_arduino();
    switch(ret){
        case(0):qDebug()<< "arduino is availble and connected to :"<< A.getarduino_port_name();
            break;
        case(1):qDebug()<< "arduino is availble but not connected to :"<< A.getarduino_port_name();
            break;
        case(-1):qDebug()<< "arduino is not availble";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

    //fin arduino



    animation=new QPropertyAnimation(ui->ajouter,"geomerty");
    animation->setDuration(10000);
    animation->setStartValue(ui->ajouter->geometry());
    animation->setEndValue(QRect(200,200,100,50));
    animation->start();

    ui->ID->setValidator(new QIntValidator(0,9999999,this));
    ui->Id_2->setValidator(new QIntValidator(0,9999999,this));
    ui->id_planning->setValidator(new QIntValidator(0,9999999,this));
    ui->num->setValidator(new QIntValidator(0,9999999,this));
    ui->appreciation->setValidator(new QIntValidator(0,9999999,this));
    ui->id_coach->setValidator(new QIntValidator(0,9999999,this));
    ui->id_cheval->setValidator(new QIntValidator(0,9999999,this));
    ui->id_evenement->setValidator(new QIntValidator(0,9999999,this));
    ui->ID_COACH->setValidator(new QIntValidator(0,9999999,this));
    ui->ID_CHEVAL->setValidator(new QIntValidator(0,9999999,this));
    ui->ID_EVENEMENT->setValidator(new QIntValidator(0,9999999,this));






}

MainWindow::~MainWindow()
{
    delete ui;
}
////////////////////////////////////////////////////////////////////////
/// controle de saisie

bool MainWindow::verifID()
{
    if (ui->ID->text().contains(QRegExp("[^0-9 ]") ) || ui->ID->text().isEmpty())
    {
        ui->ID->clear();

        ui->ID->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifNOM()
{
    if (ui->nom->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->nom->text().isEmpty())
    {
        ui->nom->clear();
        ui->nom->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow::verifPRENOM()
{
    if (ui->prenom->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->prenom->text().isEmpty())
    {
        ui->prenom->clear();
        ui->prenom->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifTYPE()
{
    if (ui->type->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->type->text().isEmpty())
    {
        ui->type->clear();
        ui->type->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow ::verifEmail()
{
    if (ui->Email->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->Email->text().isEmpty())
    {
        ui->Email->clear();
        ui->Email->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow::verifNOME()
{if (ui->nomE->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->nomE->text().isEmpty())
    {
        ui->nomE->clear();
        ui->nomE->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifNUM()
{
    if (ui->num->text().contains(QRegExp("[^0-9 ]") ) || ui->num->text().isEmpty())
    {
        ui->num->clear();

        ui->num->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifMALADIE()
{if (ui->maladie->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->maladie->text().isEmpty())
    {
        ui->maladie->clear();
        ui->maladie ->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifID_SUP()
{
    if (ui->Id_2->text().contains(QRegExp("[^0-9 ]") ) || ui->Id_2->text().isEmpty())
    {
        ui->Id_2->clear();

        ui->Id_2->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}



bool MainWindow::verifID_CAVALIER()
{
    if (ui->id_cavalier->text().contains(QRegExp("[^0-9 ]") ) || ui->id_cavalier->text().isEmpty())
    {
        ui->id_cavalier->clear();

        ui->id_cavalier->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }


}
bool MainWindow::verifID_PLANNING()
{ if (ui->id_planning->text().contains(QRegExp("[^0-9 ]") ) || ui->id_planning->text().isEmpty())
    {
        ui->id_planning->clear();

        ui->id_planning->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow:: verifID_IDCAOCH()
{
    if (ui->id_coach->text().contains(QRegExp("[^0-9 ]") ) || ui->id_coach->text().isEmpty())
        {
            ui->id_coach->clear();

            ui->id_coach->setPlaceholderText("contient que des chiffres") ;
            return false;
        }
        else
        {
            return true;
        }
}
bool MainWindow::verifID_CHEVAL()
{ if (ui->id_cheval->text().contains(QRegExp("[^0-9 ]") ) || ui->id_cheval->text().isEmpty())
    {
        ui->id_cheval->clear();

        ui->id_cheval->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifAPPRECIATION()
{
    if (ui->appreciation->text().contains(QRegExp("[^0-9 ]") ) || ui->appreciation->text().isEmpty()||ui->appreciation->text().toInt()>10||ui->appreciation->text().toInt()<0 )
        {
            ui->appreciation->clear();

            ui->appreciation->setPlaceholderText("contient que des chiffres entre 0 et 10") ;
            return false;
        }
        else
        {
            return true;
        }
}
bool MainWindow::verifID_EVENEMENT()
{if (ui->id_evenement->text().contains(QRegExp("[^0-9 ]") ) || ui->id_evenement->text().isEmpty())
    {
        ui->id_evenement->clear();

        ui->id_evenement->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifID_PLANNING_SUPP()
{if (ui->id_planning_supp->text().contains(QRegExp("[^0-9 ]") ) || ui->id_planning_supp->text().isEmpty())
    {
        ui->id_planning_supp->clear();

        ui->id_planning_supp->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}

//////////////////////////////////////////////////////////////////////////
/// cavalier
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
if((verifID())&&(verifNOM())&&(verifPRENOM())&&(verifTYPE()) &&(verifNOME())&&(verifNUM())&&(verifEmail())&&(verifMALADIE()))
{
if(test)
{QMessageBox msgBox ;
    QMessageBox::information(this,"information","cavalier ajouté");

}
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
        int ID=ui->Id->text().toInt ();
        QString nom=ui->NOM->text () ;
        QString prenom=ui->PRENOM->text () ;
        QString dateN=ui->DATEN->text () ;
        QString  dateI=ui->DATEI->text () ;
        QString type=ui->TYPE->text () ;
        QString Email=ui->email->text () ;
        QString nomE=ui->NOME->text () ;
        int num=ui->NUM->text().toInt ();
        QString maladie=ui->MALADIE->text () ;
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
   if(verifID_SUP())
   {
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("supprimer un cavalier"),
                                 QObject::tr("cavalier  supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_cavalier->setModel(c.afficher()) ;

    }}
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer un cavalier "),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}



///////////////////////////////////////////////////////////////////
/// planning_cavalier
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
 if((verifID_CAVALIER())&&(verifID_PLANNING())&&(verifID_IDCAOCH())&&(verifID_EVENEMENT()) &&(verifID_CHEVAL())&&(verifAPPRECIATION()))
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



/*void MainWindow::on_afficher_planning_2_currentChanged(int index)
{
   planning_cavalier p  ;
    ui->afficher_planning->setModel(p.afficher()) ;
}
*/
void MainWindow::on_supprimer_cavalier_clicked()
{

   planning_cavalier p;
        int id = ui->id_planning_supp->text().toInt();
        bool test=p.supprimer(id);
        if(verifID_PLANNING_SUPP())
        {
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("supprimer un planning"),
                                     QObject::tr("planning  supprimé.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->afficher_planning->setModel(p.afficher()) ;

        }}
        else
            QMessageBox::critical(nullptr, QObject::tr("supprimer un planning "),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_modifier_planning_clicked()
{int id_cavalier=ui->ID_CAVALIER->text().toInt ();
    int id_planning=ui->ID_PLANNING->text().toInt ();
    QString horaire=ui->HORAIRE->text () ;
    int appreciation=ui->APPRECIATION->text().toInt ();
    int id_coach=ui->ID_COACH->text().toInt ();
    int id_cheval=ui->ID_CHEVAL->text().toInt ();
    int id_evenement=ui->ID_EVENEMENT->text().toInt ();

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
    Smtp* smtp = new Smtp("mariem.aljene@gmail.com","mariemaljene","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    smtp->sendMail("mariem.aljene@gmail.com",ui->mail_2->text(),ui->objet_mail->text(),ui->text_mail->toPlainText());
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
    painter.drawText(1200,3300,"id_planning");
    painter.drawText(2400,3300,"horaire");
    painter.drawText(4000,3300,"appreciation");
    painter.drawText(5000,3300,"id_coach");
    painter.drawText(5800,3300,"id_cheval ");
    painter.drawText(6600,3300,"id_evenement ");
    QSqlQuery query;
    query.prepare("select * from planning_cavalier");
    query.exec();
    while (query.next())
    {
        painter.drawText(200,i,query.value(0).toString());
        painter.drawText(1200,i,query.value(1).toString());
        painter.drawText(2400,i,query.value(2).toString());
        painter.drawText(4000,i,query.value(3).toString());
        painter.drawText(5000,i,query.value(4).toString());
        painter.drawText(5800,i,query.value(5).toString());
        painter.drawText(6600,i,query.value(6).toString());

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


void MainWindow::on_afficher_planning_2_clicked()
{ planning_cavalier p  ;
    ui->afficher_planning->setModel(p.afficher()) ;
}



//QVector<double> MainWindow::on_satat_clicked()
//{

//}



void MainWindow::on_recherche_cav_clicked()
{

    QString N=ui->recherche_cavalier->text();
     QString s=ui->recherche->text();
     Cavalier c;
     ui->tab_cavalier->setModel(c.rechercher(N)) ;
      ui->afficher_planning->setModel(c.rechercher_nom(s)) ;
}


void MainWindow::on_tri_cavalier_clicked()
{Cavalier c;
 ui->tab_cavalier->setModel(c.trier());
 ui->tab_cavalier->setModel(c.trie());
}
QVector<double> MainWindow::Statistique()
{
    QSqlQuery q;
    QVector<double> stat(3);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;

    q.prepare("SELECT appreciation FROM planning_cavalier WHERE  0<appreciation and appreciation<=4 ");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT appreciation FROM planning_cavalier WHERE  4<appreciation and appreciation<=8");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    q.prepare("SELECT appreciation FROM planning_cavalier WHERE  8<appreciation and appreciation<=10");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }

    return stat;
}

void MainWindow::makePlot()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
        x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
        y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::Statistique());
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(100, 40, 60, 170));
    ui->customPlot->replot();

    // move bars above graphs and grid below bars:
    ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
    ui->customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
    ui->customPlot->xAxis->grid()->setLayer("belowmain");
    ui->customPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6;
    QVector<QString> labels;
    labels<<"0-4"<<"5-7"<<"8-10";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0,4);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customPlot->axisRect()->setBackground(axisRectGradient);

    ui->customPlot->rescaleAxes();
    ui->customPlot->xAxis->setRange(0, 7);
    ui->customPlot->yAxis->setRange(0, 10);


}

void MainWindow::on_recherche_clicked()
{
    QString N=ui->recherche->text();

     planning_cavalier p;
     ui->afficher_planning->setModel(p.rechercher(N)) ;


}


void MainWindow::on_tri_planning_cavalier_clicked()
{
    planning_cavalier p;
    ui->afficher_planning->setModel(p.trier());
}

