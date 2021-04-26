#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cavalier.h"
#include"planning_cavalier.h"
#include<qpropertyanimation>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QLineSeries>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include <QStackedWidget>
#include "arduino.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_ajouter_clicked();

   // void on_pushButton_clicked();

    //void on_afficher_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();
    QVector<double> Statistique();


  //  void on_tabWidget_currentChanged(int index);

    void on_affiche_cavaliers_currentChanged(int index);

    void on_ajouter_planning_clicked();

   // void on_imprimer_currentChanged(int index);

   // void on_afficher_planning_2_currentChanged(int index);

    void on_supprimer_cavalier_clicked();

//    void on_pushButton_2_clicked();

    void on_modifier_planning_clicked();

    void on_envoyermail_clicked();
     bool verifID();
     bool verifNOM();
     bool verifPRENOM();
     bool verifTYPE();
     bool verifEmail();
     bool verifNOME();
     bool verifNUM();
     bool verifMALADIE();

    bool verifID_SUP() ;



     bool verifID_CAVALIER() ;
     bool verifID_PLANNING();
     bool verifID_IDCAOCH();
     bool verifID_CHEVAL() ;
     bool verifID_EVENEMENT() ;
     bool  verifAPPRECIATION();
     bool verifID_PLANNING_SUPP() ;





    void on_imprimer_planning_clicked();

    //void on_satat_clicked();

    //void on_mail_currentChanged(int index);

    void on_afficher_planning_2_clicked();

   // void on_pushButton_clicked();

    void on_recherche_cav_clicked();

  //  void on_pushButton_clicked();

    void on_tri_cavalier_clicked();

    //void on_satat_clicked();

    void on_recherche_clicked();

   // void on_recherche_planning_cursorPositionChanged(int arg1, int arg2);

    void on_tri_planning_cavalier_clicked();

    void on_statistiques_currentChanged(int index);

private:
    Ui::MainWindow *ui;
// Cavalier C  ;
   //planning_cavalier p ;
    QPropertyAnimation *animation ;
    QByteArray data;
    arduino A;

    void makePlot();
};

#endif // MAINWINDOW_H
