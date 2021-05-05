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
#include <QSound>
#include <QMessageBox>
#include <QMediaPlayer>
#include "cavalier.h"
#include"QIntValidator"

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
#include <QFileDialog>
#include<QTimer>
#include<QDateTime>
#include"QMessageBox"
#include <QPainter>
#include<QTimer>
#include<QDateTime>

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


#include<QMediaPlayer>
#include<QVideoWidget>
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

#include <QPixmap>
#include "boutique.h"
#include "blog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);




    //timer Authentification
        QTimer *timer=new  QTimer(this);
        connect (timer ,SIGNAL(timeout()),this ,SLOT(showTime()));
        timer->start() ;
    //end timer
        //timer Menu
            QTimer *t=new  QTimer(this);
            connect (t ,SIGNAL(timeout()),this ,SLOT(showTime_menu()));
            t->start() ;
        //end timer

    son=new QMediaPlayer(this);
    connect(son, &QMediaPlayer::positionChanged,this,&MainWindow::on_positionChanged);
    connect(son, &QMediaPlayer::durationChanged,this,&MainWindow::on_durationChanged);
    //son=new QSound(":/sons/cheval.mp3");
    //makeplotet
    MainWindow::makePlotZAINEB();
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
    ui->tab_planning->setModel(tmp.afficher());//refresh
    ui->tableView_2->setModel(temp.afficher());//refresh


}
void MainWindow::showTime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->digital_clock->setText(time_text);
}
void MainWindow::showTime_menu()
{
    QTime t=QTime::currentTime();
    QString time_text=t.toString("hh : mm : ss");
    ui->digital_clock_2->setText(time_text);
}
MainWindow::~MainWindow()
{

    delete ui;
}

//les verifs du cheval



bool MainWindow::verifnomZ()
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
bool MainWindow::verifgenreZ()
{
    if (ui->genreChev_2->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->genreChev_2->text().isEmpty())
    {
        ui->genreChev_2->clear();
        ui->genreChev_2->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifraceZ()
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
bool MainWindow::verifNationnaliteZ()
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
bool MainWindow::verifType_actZ()
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
bool MainWindow::verifVacZ()
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
bool MainWindow::verifIDZ()
{
    if (ui->idChev_2->text().contains(QRegExp("[^0-9 ]") ) || ui->idChev_2->text().isEmpty())
    {
        ui->idChev_2->clear();

        ui->idChev_2->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }
}

bool MainWindow::verifPoidsZ()
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
bool MainWindow::verifNumBoxZ()
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

bool MainWindow::verifID2Z()
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

bool MainWindow::verifnomActZ()
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

bool MainWindow::verifDureeZ()
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

bool MainWindow::verifIDCavalierZ()
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
void MainWindow::on_ajouter_plann_cheval_clicked()
{

         int Id_cheval=ui->Id_cheval->text().toInt ();
        QString Nom_activite=ui->Nom_activite->text() ;
        QString date_activite=ui->date_activite->text () ;
        QString duree=ui->duree->text();
        int  Id_cavalier=ui->Id_cavalier->text().toUInt();
        planningCheval p(Id_cheval,Nom_activite,date_activite,duree,Id_cavalier);
        N.notifications_ajoutcheval();
        bool test=p.ajouter();
        if(verifID2Z()&&verifnomActZ()&&verifDureeZ()&&verifIDCavalierZ())
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
void MainWindow::on_modifier_plann_2_clicked()
{
    int id= ui->Id_cheval_4->text().toInt();
    QString Nom_activite=ui->Nom_activite_3->text();

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
  MainWindow::makePlotZAINEB();
}

void MainWindow::on_pushButton_Quitter_clicked()
{
    close();
}



//*******************************************************************************************************************************
//cheval
void MainWindow::on_ajouter_cheval_clicked()
{
    int Id_cheval=ui->idChev_2->text().toInt();
    QString Nom=ui->nomChev->text() ;
    QString genre=ui->genreChev_2->text() ;
    QString date_de_naiss=ui->dateChev_2->text();
    QString  vaccins=ui->vaccinsChev->text();
    QString date_limite_vacc=ui->dateLimiteVaccin->text();
    int poids=ui->poidsChev->text().toInt();
    QString race=ui->raceChev->text() ;
    QString nationnalite =ui->nationnaliteChev->text();
    int num_box=ui->num_box->text().toInt();
    QString type_act=ui->type_actChev->text();

    cheval c(Id_cheval,Nom,genre,date_de_naiss,vaccins,date_limite_vacc,poids,race,nationnalite,num_box,type_act);
   bool test=c.ajouter();
  if((verifIDZ())&&(verifnomZ())&&(verifgenreZ())&&(verifraceZ())&& (verifNationnaliteZ())&&(verifType_actZ())&&(verifVacZ())&&(verifPoidsZ())&&(verifNumBoxZ()))
       {
          if(test)
            {

               QMessageBox msgBox ;
               QMessageBox::information(this,"information","cheval ajouté");
               ui->tableView_2->setModel(temp.afficher());//refresh

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

    int Id= ui->lineEdit_IDCheval->text().toInt ();
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

        q.prepare("SELECT DUREE FROM PLANNINGCHEVAL WHERE DUREE<=1");
        q.exec();
        while (q.next())
        {
            stat[0]++;
        }
        q.prepare("SELECT DUREE FROM PLANNINGCHEVAL WHERE DUREE<=2");
        q.exec();
        while (q.next())
        {
            stat[1]++;
        }
        q.prepare("SELECT DUREE FROM PLANNINGCHEVAL WHERE DUREE<=3");
        q.exec();
        while (q.next())
        {
            stat[2]++;
        }

        return stat;
    }
void MainWindow::makePlotZAINEB()
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
















void MainWindow::on_imprimer_planning_cheval_clicked()
{
    QPdfWriter pdf("C:\\Users\\mariem\\Desktop\\integraton\\cheval+\\integ\\Pdf.pdf");
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
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:\\Users\\mariem\\Desktop\\integraton\\cheval+\\integ\\Pdf.pdf"));
            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();

    }
}

/*void MainWindow::on_pushButton_clicked()//tri
{
     cheval c;
     ui->tableView_2->setModel(c.trier());

}*/

void MainWindow::on_pushButton_2_clicked()//tri planning
{
    ui->tab_planning->setModel(tmp.tri());
    ui->tab_planning->setModel(tmp.triePlanningChev());
    ui->tab_planning->setModel(tmp.tri3());
}




/*void MainWindow::on_comboBox_ID_cheval_activated(const QString &arg1)
{
    QString ID=ui->comboBox_ID_cheval->currentText();
    QSqlQuery queryy ;
    queryy.prepare("SELECT * from CHEVAL where ID_CHEVAL=='"+ID+"'");
    if(queryy.exec())
    {
        while(queryy.next())
        {
            ui->numbox_2->setText(queryy.value(7).toString()) ;


        }
    }
}*/

void MainWindow::on_pushButton_TRI_NUM_BOX_clicked()
{
    cheval c;
    ui->tableView_2->setModel(temp.trie());
}

void MainWindow::on_pushButton_TRI_NOM_clicked()
{
    cheval c;
    ui->tableView_2->setModel(temp.trie2());
}

void MainWindow::on_PUSH_BUTTON_TRI_DATE_NAISS_clicked()
{
    //cheval c;
    ui->tableView_2->setModel(temp.trier());
}

void MainWindow::on_ButtonConnecter_clicked()
{

    QString Indentifiant=ui->lineEdit_Identifiant->text();
    QString motdepasse=ui->lineEdit_motdepasse->text();

    if(Indentifiant=="test"&& motdepasse=="test")
        {
            QMessageBox::information(this,"connecter","connecter");
            //hide();
            ui->stackedWidget->setCurrentIndex(3);


        }

    else
        {
            QMessageBox::warning(this,"connecter","erreur");
            hide();
             //ui->stackedWidget->setCurrentIndex(2);
        }

}






/*void MainWindow::on_pushButton_4_clicked()
{
   QString filename = QFileDialog::getOpenFileName(this,"ouvrir");
   if (filename.isEmpty()){
       return;
   }
   son->setMedia(QUrl::fromLocalFile("/Users/zaine/Desktop/Smart-Club-2A26-cheval-/cheval.mp3"));
   son->play();
}*/

//son
void MainWindow::on_pushButton_Reglage_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_positionChanged(qint32 position)
{
  ui->progressSlider->setValue(position);
}

void MainWindow::on_durationChanged(qint32 position)
{
  ui->progressSlider->setMaximum(position);
}



void MainWindow::on_pushButton_start_clicked()
{
    son->setMedia(QUrl::fromLocalFile("C:\\Users\\mariem\\Desktop\\integraton\\cheval+\\integ\\son.mp3"));
    son->play();
    qDebug()<<son->errorString();
}

void MainWindow::on_pushButton_stop_clicked()
{
    son->stop();
}

void MainWindow::on_progressSlider_sliderMoved(int position)
{
  son->setPosition(position);
}

void MainWindow::on_volumeSlider_sliderMoved(int position)
{
 son->setVolume(position);
}

void MainWindow::on_pushButton_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}








void MainWindow::on_pushButton_Reglage_3_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}
//mariem
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
void MainWindow::on_ajouter_cavalier_clicked()
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
void MainWindow::on_supprimer_planning_cavalier_clicked()
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
{ QPdfWriter pdf("C:\\Users\\mariem\\Desktop\\integraton\\cheval+\\integ\\Pdf.pdf");
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
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:\\Users\\mariem\\Desktop\\integraton\\cheval+\\integ\\Pdf.pdf"));
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

 ui->tab_cavalier->setModel(c.trie());
}
void MainWindow::on_trie_nom_clicked()
{Cavalier c;
    ui->tab_cavalier->setModel(c.trier());

}
void MainWindow::on_trie_ID_clicked()
{
    Cavalier c;
        ui->tab_cavalier->setModel(c.trie_ID());

}
QVector<double> MainWindow::Statistique_Cavalier()
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
    bars1->setData(x3, MainWindow::Statistique_Cavalier());
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

void MainWindow::on_trie_idCoach_clicked()
{
    planning_cavalier p;
    ui->afficher_planning->setModel(p.trie_coach());
}
void MainWindow::on_trie_horraire_clicked()
{
    planning_cavalier p;
    ui->afficher_planning->setModel(p.trie_horraire());
}




void MainWindow::on_stat_clicked()
{
MainWindow::makePlot();
}

void MainWindow::on_pushButton_10_clicked()
{
    close();
}

void MainWindow::on_pushButton_7_clicked()
{
    close();
}

void MainWindow::on_pushButton_8_clicked()
{
    close();
}

void MainWindow::on_pushButton_6_clicked()
{
    close();
}

void MainWindow::on_pushButton_9_clicked()
{
    close();
}






void MainWindow::on_evenements_vid_clicked()
{
QMediaPlayer *player=new QMediaPlayer;
QVideoWidget *w =new QVideoWidget ;
 player->setVideoOutput(w) ;
 player->setMedia(QUrl ::fromLocalFile("C:\\Users\\mariem\\Desktop\\integraton\\cheval+\\integ\\equitation.mp4"));
 w->setGeometry(100,100,300,400);
 w->show() ;
 player->play() ;
 qDebug() << player->state();
}

void MainWindow::on_retour_menu_clicked()
{
   ui->stackedWidget->setCurrentIndex(3);
}






//MENU

void MainWindow::on_cheval_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_cavalier_2_clicked()
{ui->stackedWidget->setCurrentIndex(5);

}
void MainWindow::on_click_here_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}



void MainWindow::on_pushButton_back_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_back_4_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_back_5_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_back_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}
//THANK YOU FOR WATCHING

/*void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog ::getOpenFileName(this,tr("choose"),"", tr("Images(*.png *.jpg *.bmp)"));
    if (QString ::compare(filename, QString())!= 0)
    {
        QImage image;
        bool valid = image.load(filename);
        if (valid)
        {
            image = image.scaledToWidth(ui->label_pic->width() ,Qt::SmoothTransformation);
            ui->label_pic->setPixmap(QPixmap::fromImage(image));
        }
        else
        {

        }
    }
}*/

////////////////Boutique
void MainWindow::on_pushButton_ajouterBoutique_clicked()
{
    int Ref=ui->lineEdit_Ref_2->text().toInt ();
    int Qte=ui->lineEdit_Qte_2->text().toInt ();


 Boutique B(Ref,Qte);
bool test=B.ajouter();
if(test)
{QMessageBox msgBox ;
    QMessageBox::information(this,"information","Article ajouté");

}

else {QMessageBox msgBox ;
    QMessageBox::information(this,"information","echec lors de l ajout");
 }
}

void MainWindow::on_pushButton_ModifierBoutique_clicked()
{
    int Ref= ui->lineEdit_Ref->text().toInt();
    int Qte=ui->lineEdit_Qte->text().toInt();
    Boutique B(Ref,Qte);
    bool test=B.modifier(Ref,Qte);


    if (test)
    {ui->tableView_ListeArticle->setModel(B.afficher());//refresh
        QMessageBox::information(this, "success ", "modifier article");

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un article"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButtonSupprimerBoutique_clicked()
{
    int Ref= ui->lineEdit_SupRef->text().toInt();
    int Qte= ui->lineEdit_Qte->text().toInt();
    Boutique B(Ref,Qte);
    bool test=B.supprimer(Ref);
       if(test)
       {
           ui->tableView_ListeArticle->setModel(B.afficher());//refresh
           QMessageBox msgBox ;
           QMessageBox::information(this,"information","article supprimé");
       }

       else
       {
           QMessageBox::critical(nullptr, QObject::tr("article suprimé"),
                                 QObject::tr("Erreur !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
       }
}







void MainWindow::on_pushButton_AfficherBoutique_clicked()
{
    Boutique B;
    ui->tableView_ListeArticle->setModel(B.afficher()) ;
}
////////////////// blog
void MainWindow::on_ajouter_blog_clicked()
{
    int ID_blog=ui->id_blog->text().toInt ();
    QString text=ui->text_blog->text();


 blog Blog(ID_blog,text);
bool test=Blog.ajouter();
if(test)
{QMessageBox msgBox ;
    QMessageBox::information(this,"information","Blog ajouté");

}

else {QMessageBox msgBox ;
    QMessageBox::information(this,"information","echec lors de l ajout");
 }
}


void MainWindow::on_afficher_blog_clicked()
{
   blog b  ;
 ui->afficher_blog_2->setModel(b.afficher()) ;
    }



void MainWindow::on_modifier_blog_clicked()
{
    int ID_blog= ui->id_blog_modifier->text().toInt();
    QString text=ui->text_blog_2->text();
    blog Blog(ID_blog,text);
    bool test=Blog.modifier(ID_blog,text);


    if (test)
    {ui->afficher_blog_2->setModel(Blog.afficher());//refresh
        QMessageBox::information(this, "success ", "modifier blog");

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un blog"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer_blog_clicked()
{

      blog b;
            int id_blog = ui->id_blog_supp->text().toInt();
            bool test=b.supprimer(id_blog);

            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("supprimer un blog"),
                                         QObject::tr("blog   supprimé.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);


            }
            else
                QMessageBox::critical(nullptr, QObject::tr("supprimer un blog "),
                                      QObject::tr("Erreur !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);



}



void MainWindow::on_chevaux_vid_clicked()
{QMediaPlayer *player=new QMediaPlayer;
    QVideoWidget *w =new QVideoWidget ;
     player->setVideoOutput(w) ;
     player->setMedia(QUrl ::fromLocalFile("C:\\Users\\mariem\\Desktop\\integraton\\cheval+\\integ\\cheval.mp4"));
     w->setGeometry(100,100,300,400);
     w->show() ;
     player->play() ;
     qDebug() << player->state();

}

void MainWindow::on_pushButton_VoirBoutique_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_VoirBlog_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_retour_menu_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_retour_menu_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_Reglage_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_TriBlog_clicked()
{
    blog b;
    ui->afficher_blog_2->setModel(b.tri());
}

void MainWindow::on_pushButtonPdfBoutique_clicked()
{
    QPdfWriter pdf("C:\\Users\\zaine\\Desktop\\cheval+\\integ\\Pdf.pdf");
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(1100,1200,"Liste d'article disponible ");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        painter.drawRect(100,100,7300,2600);

        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(200,3300,"REF");
        painter.drawText(1200,3300,"QTE");


        QSqlQuery query;
        query.prepare("select * from BOUTIQUE");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(2200,i,query.value(1).toString());


            i = i + 500;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:\\Users\\zaine\\Desktop\\cheval+\\integ\\Pdf.pdf"));
            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();

    }
}
