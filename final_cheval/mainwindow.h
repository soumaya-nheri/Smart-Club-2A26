#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "planningcheval.h"
#include "cheval.h"
#include <QMainWindow>
//#include <QtCharts>
#include "notifications.h"
#include "authentification.h"
#include <QMediaPlayer>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    bool verifID();
    bool verifnom();
    bool verifgenre();
    bool verifrace();
    bool verifNationnalite();
    bool verifType_act();
    bool verifVac();
    bool verifPoids();
    bool verifNumBox();
    //verif plann
    bool verifID2();
    bool verifnomAct();
    bool verifDuree();
    bool verifIDCavalier();

    void on_ajouter_clicked();


    void on_pushButton_Quitter_clicked();



    void on_QUITTER_1_clicked();

    void on_QUITTER_2_clicked();

    void on_QUITTER_3_clicked();

    void on_QUITTER_4_clicked();



    void on_modifier_cheval_clicked();

    void on_supprimer_cheval_clicked();



    void on_recherche_chev_clicked();


    QVector<double> Statistique();




    void on_ajouter_cheval_clicked();



    void on_afficher_plann_clicked();


    void on_supprimer_plann_clicked();

    void on_statistique_plann_clicked();

    void on_afficher_cheval_clicked();

    void on_imprimer_planning_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_TRI_NUM_BOX_clicked();

    void on_pushButton_TRI_NOM_clicked();

    void on_PUSH_BUTTON_TRI_DATE_NAISS_clicked();

    void on_ButtonConnecter_clicked();



    void on_modifier_plann_2_clicked();


    void on_positionChanged(qint32 position);
    void on_durationChanged(qint32 position);
    void on_pushButton_Reglage_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

    void on_progressSlider_sliderMoved(int position);

    void on_volumeSlider_sliderMoved(int position);

    void on_pushButton_back_clicked();
    void showTime();



private:
    Ui::MainWindow *ui;
    planningCheval tmp;
    cheval temp;
    notifications N;
    //authentification a;
    void makePlot();
    QMediaPlayer *son;

};
#endif // MAINWINDOW_H
