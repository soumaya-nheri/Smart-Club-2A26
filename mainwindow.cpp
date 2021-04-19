#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "planningcheval.h"
#include "cheval.h"
#include <QMessageBox>
#include <QDebug>
#include <QRadioButton>
#include <QDateEdit>
#include<QTableWidget>
#include <QIntValidator>
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



#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
//#include <QPrintDialog>
//#include <QPieSlice>
//#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    MainWindow::makePlot();
  /*  ui->Id_cheval->setValidator(new QIntValidator(0,9999999,this));
    ui->ID3->setValidator(new QIntValidator(0,9999999,this));
    ui->poidsChev->setValidator(new QIntValidator(0,9999999,this));
    ui->num_box->setValidator(new QIntValidator(0,9999999,this));
    ui->duree->setValidator(new QIntValidator(0,9999999,this));
    ui->idChev->setValidator(new QIntValidator(0,9999999,this));
    ui->duree_3->setValidator(new QIntValidator(0,9999999,this));
    ui->numbox_2->setValidator(new QIntValidator(0,9999999,this));
    ui->Id_cheval2->setValidator(new QIntValidator(0,9999999,this));
    ui->Id_cavalier->setValidator(new QIntValidator(0,9999999,this));
    ui->Id_cheval_3->setValidator(new QIntValidator(0,9999999,this));
    ui->poidsChev_2->setValidator(new QIntValidator(0,9999999,this));

*/
    ui->tab_planning->setModel(tmp.afficher());//refresh
    ui->tableView_2->setModel(temp.afficher());//refresh
    ui->comboBox_ID_cheval->setModel(temp.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

//les verifs du cheval



bool MainWindow::verifnom()
{
    if (ui->nomChev->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->nomChev->text().isEmpty())
    {
        ui->nomChev->clear();
        ui->nomChev->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifgenre()
{
    if (ui->genreChev->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->genreChev->text().isEmpty())
    {
        ui->genreChev->clear();
        ui->genreChev->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifrace()
{
    if (ui->raceChev->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->raceChev->text().isEmpty())
    {
        ui->raceChev->clear();
        ui->raceChev->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifNationnalite()
{
    if (ui->nationnaliteChev->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->nationnaliteChev->text().isEmpty())
    {
        ui->nationnaliteChev->clear();
        ui->nationnaliteChev->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifType_act()
{
    if (ui->type_actChev->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->type_actChev->text().isEmpty())
    {
        ui->type_actChev->clear();
        ui->type_actChev->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifVac()
{
    if (ui->vaccinsChev->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->vaccinsChev->text().isEmpty())
    {
        ui->vaccinsChev->clear();
        ui->vaccinsChev->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifID()
{
    if (ui->idChev->text().contains(QRegExp("[^0-9 ]") ) || ui->idChev->text().isEmpty())
    {
        ui->idChev->clear();

        ui->idChev->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }
}

bool MainWindow::verifPoids()
{
    if (ui->poidsChev->text().contains(QRegExp("[^0-9 ]") ) || ui->poidsChev->text().isEmpty())
    {
        ui->poidsChev->clear();

        ui->poidsChev->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }
}
bool MainWindow::verifNumBox()
{
    if (ui->num_box->text().contains(QRegExp("[^0-9 ]") ) || ui->num_box->text().isEmpty())
    {
        ui->num_box->clear();

        ui->num_box->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }
}

// les verifs du planning

bool MainWindow::verifID2()
{
    if (ui->Id_cheval->text().contains(QRegExp("[^0-9 ]") ) || ui->Id_cheval->text().isEmpty())
    {
        ui->Id_cheval->clear();

        ui->Id_cheval->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }
}

bool MainWindow::verifnomAct()
{
    if (ui->Nom_activite->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->Nom_activite->text().isEmpty())
    {
        ui->Nom_activite->clear();
        ui->Nom_activite->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool MainWindow::verifDuree()
{
    if (ui->duree->text().contains(QRegExp("[^0-9 ]") ) || ui->duree->text().isEmpty())
    {
        ui->duree->clear();

        ui->duree->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }
}

bool MainWindow::verifIDCavalier()
{
    if (ui->Id_cavalier->text().contains(QRegExp("[^0-9 ]") ) || ui->Id_cavalier->text().isEmpty())
    {
        ui->Id_cavalier->clear();

        ui->Id_cavalier->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }
}

 //PLANNING_CHEVAL
void MainWindow::on_ajouter_clicked()
{

         int Id_cheval=ui->Id_cheval->text().toInt ();
        QString Nom_activite=ui->Nom_activite->text() ;
        QString date_activite=ui->date_activite->text () ;
        QString duree=ui->duree->text();
        int  Id_cavalier=ui->Id_cavalier->text().toUInt();
        planningCheval p(Id_cheval,Nom_activite,date_activite,duree,Id_cavalier);

        bool test=p.ajouter();
        if(verifID2()&&verifnomAct()&&verifDuree()&&verifIDCavalier())
            {
                 if(test)
                 {
                  //   ui->tableView->setModel(tmp.afficher());//refresh
                     QMessageBox msgBox ;
                    QMessageBox::information(this,"information","planning ajouté");

                 }
            }

             else
             {
                 QMessageBox msgBox ;
                msgBox.setText("planning non ajouté ");
            }

}
void MainWindow::on_afficher_plann_clicked()
{

     ui->tab_planning->setModel(tmp.afficher())  ;
}

void MainWindow::on_modifier_plann_clicked()
{
    int id= ui->Id_cheval_3->text().toInt();
    QString Nom_activite=ui->Nom_activite_2->text();

    bool test=tmp.modifier(id,Nom_activite);
    //N.notifications_modifierarchives();

    if (test)
    {ui->tab_planning->setModel(tmp.afficher());//refresh
        QMessageBox::information(this, "success ", "modifier un cheval");

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un cheval"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer_plann_clicked()
{
    int id_cheval= ui->Id_cheval2->text().toInt();
       bool test=tmp.supprimer(id_cheval);
       if(test)
       {
           ui->tab_planning->setModel(tmp.afficher());//refresh
           QMessageBox msgBox ;
           QMessageBox::information(this,"information","planning supprimé");
       }

       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Supprimer un planning"),
                                 QObject::tr("Erreur !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
       }
}

void MainWindow::on_statistique_plann_clicked()
{

}

void MainWindow::on_pushButton_Quitter_clicked()
{
    close();
}



//*******************************************************************************************************************************
//cheval
void MainWindow::on_ajouter_cheval_clicked()
{
    int Id_cheval=ui->idChev->text().toInt ();
    QString Nom=ui->nomChev->text() ;
    QString genre=ui->genreChev->text() ;
    QString date_de_naiss=ui->dateChev->text();
    QString  vaccins=ui->vaccinsChev->text();
    QString date_limite_vacc=ui->dateLimiteVaccin->text();
    int poids=ui->poidsChev->text().toInt ();
    QString race=ui->raceChev->text() ;
    QString nationnalite =ui->nationnaliteChev->text();
    int num_box=ui->num_box->text().toInt ();
    QString type_act=ui->type_actChev->text();

    cheval c(Id_cheval,Nom,genre,date_de_naiss,vaccins,date_limite_vacc,poids,race,nationnalite,num_box,type_act);
   bool test=c.ajouter();
   if((verifID())&&(verifnom())&&(verifgenre())&&(verifrace())&& (verifNationnalite())&&(verifType_act())&&(verifVac())&&(verifPoids())&&(verifNumBox()))
       {
          if(test)
            {

               QMessageBox msgBox ;
               QMessageBox::information(this,"information","cheval ajouté");
              // ui->tableView_2->setModel(temp.afficher());//refresh

               }
   }
                else
                {
                    QMessageBox msgBox ;
                    msgBox.setText("cheval non ajouté ");
                }
}
void MainWindow::on_afficher_cheval_clicked()
{
    cheval c;
    ui->tableView_2->setModel(c.afficher()) ;
}




void MainWindow::on_modifier_cheval_clicked()
{

    int Id= ui->comboBox_ID_cheval->currentText().toInt();
    int numB= ui->numbox_2->text().toInt();
    bool test=temp.modifier(Id,numB);
    if (test)
    {
        ui->tableView_2->setModel(temp.afficher());//refresh
        QMessageBox msgBox ;
        QMessageBox::information(this,"information","cheval modifié");
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier un cheval"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_supprimer_cheval_clicked()
{cheval c ;
    int ID=ui->ID3->text().toInt();
       bool test=c.supprimer(ID);
       if(test)
       {
           ui->tableView_2->setModel(temp.afficher());//refresh
           QMessageBox msgBox ;
           QMessageBox::information(this,"information","cheval supprimé");
       }

     else
       {
           QMessageBox::critical(nullptr, QObject::tr("Supprimer un cheval"),
                                 QObject::tr("Erreur !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
       }
}

void MainWindow::on_QUITTER_1_clicked()
{
    close();
}

void MainWindow::on_QUITTER_2_clicked()
{
    close();
}

void MainWindow::on_QUITTER_3_clicked()
{
    close();
}

void MainWindow::on_QUITTER_4_clicked()
{
    close();
}





void MainWindow::on_recherche_chev_clicked() //recherche
{
    cheval c;
    QString N=ui->lineEdit_recherche->text();
    ui->tableView_2->setModel(c.rechercher(N)) ;

    QString Z=ui->lineEdit_recherche->text();
    ui->tableView_2->setModel(temp.rechercher(Z)) ;
}

QVector<double>MainWindow::Statistique()
{
        QSqlQuery q;
        QVector<double> stat(5);
        stat[0]=0;
        stat[1]=0;
        stat[2]=0;
        stat[3]=0;
        stat[4]=0;
        q.prepare("SELECT DUREE FROM PLANNINGCHEVAL WHERE DUREE<=2");
        q.exec();
        while (q.next())
        {
            stat[0]++;
        }
        q.prepare("SELECT DUREE FROM PLANNINGCHEVAL WHERE DUREE<=4");
        q.exec();
        while (q.next())
        {
            stat[1]++;
        }
        q.prepare("SELECT DUREE FROM PLANNINGCHEVAL WHERE DUREE<=6");
        q.exec();
        while (q.next())
        {
            stat[2]++;
        }
        q.prepare("SELECT DUREE FROM PLANNINGCHEVAL WHERE DUREE<=8");
        q.exec();
        while (q.next())
        {
            stat[3]++;
        }
        q.prepare("SELECT DUREE FROM PLANNINGCHEVAL WHERE DUREE 800<DUREE ");
        q.exec();
        while (q.next())
        {
            stat[4]++;
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
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customPlot->replot();

    // move bars above graphs and grid below bars:
    ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
    ui->customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
    ui->customPlot->xAxis->grid()->setLayer("belowmain");
    ui->customPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5;
    QVector<QString> labels;
    labels<<"0-1H"<<"1H-2H"<<"2H-3H"<<"3H-4H";
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
















void MainWindow::on_imprimer_planning_clicked()
{
    QPdfWriter pdf("C:\\Users\\zaine\\Desktop\\Atelier_Connexion\\Pdf.pdf");
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
        painter.drawText(200,3300,"id_cheval");
        painter.drawText(1200,3300,"nom_activite");
        painter.drawText(2400,3300,"date_activite");
        painter.drawText(4000,3300,"duree");
        painter.drawText(5000,3300,"id_cavalier");

        QSqlQuery query;
        query.prepare("select * from PLANNINGCHEVAL");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1200,i,query.value(1).toString());
            painter.drawText(2400,i,query.value(2).toString());
            painter.drawText(4000,i,query.value(3).toString());
            painter.drawText(5000,i,query.value(4).toString());


            i = i + 500;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:\\Users\\zaine\\Desktop\\Atelier_Connexion\\Pdf.pdf"));
            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();

    }
}

void MainWindow::on_pushButton_clicked()//tri
{
     cheval c;
     ui->tableView_2->setModel(c.trier());

}

void MainWindow::on_pushButton_2_clicked()//tri planning
{
    ui->tab_planning->setModel(tmp.tri());
    ui->tab_planning->setModel(tmp.trie());
    ui->tab_planning->setModel(tmp.tri3());
}




void MainWindow::on_comboBox_ID_cheval_activated(const QString &arg1)
{
    QString ID=ui->comboBox_ID_cheval->currentText();
    QSqlQuery queryy ;
    queryy.prepare("SELECT * from CHEVAL where ID_CHEVAL=='"+ID+"'");
    if(queryy.exec())
    {
        while(queryy.next())
        {
            ui->numbox_2->setText(queryy.value(10).toString()) ;


        }
    }
}

void MainWindow::on_pushButton_TRI_NUM_BOX_clicked()
{
    cheval c;
    ui->tableView_2->setModel(c.trie());
}

void MainWindow::on_pushButton_TRI_NOM_clicked()
{
    cheval c;
    ui->tableView_2->setModel(c.trie2());
}

void MainWindow::on_PUSH_BUTTON_TRI_DATE_NAISS_clicked()
{
    cheval c;
    ui->tableView_2->setModel(c.trier());
}
