#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "planningcheval.h"
#include "cheval.h"
#include <QMainWindow>
//#include <QtCharts>
#include "notifications.h"
#include <QMediaPlayer>
#include <QDebug>
#include <QMainWindow>
#include "cavalier.h"
#include"planning_cavalier.h"
#include<QPropertyAnimation>
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
#include "QFileDialog"
#include "boutique.h"

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

    bool verifIDZ();
    bool verifnomZ();
    bool verifgenreZ();
    bool verifraceZ();
    bool verifNationnaliteZ();
    bool verifType_actZ();
    bool verifVacZ();
    bool verifPoidsZ();
    bool verifNumBoxZ();
    //verif plann
    bool verifID2Z();
    bool verifnomActZ();
    bool verifDureeZ();
    bool verifIDCavalierZ();



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

    //void on_imprimer_planning_clicked();



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



    void on_ajouter_plann_cheval_clicked();

    void on_imprimer_planning_cheval_clicked();



    void on_pushButton_Reglage_3_clicked();
    //mariem
    void showTime_menu();

     //   void on_ajouter_clicked();

       // void on_pushButton_clicked();

        //void on_afficher_clicked();

        void on_modifier_clicked();

        void on_supprimer_clicked();
        QVector<double> Statistique_Cavalier();


      //  void on_tabWidget_currentChanged(int index);

        void on_affiche_cavaliers_currentChanged(int index);

        void on_ajouter_planning_clicked();

       // void on_imprimer_currentChanged(int index);

       // void on_afficher_planning_2_currentChanged(int index);

       // void on_supprimer_cavalier_clicked();

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

       // void on_statistiques_currentChanged(int index);

        void on_cavalier_2_clicked();

       // void on_statistiques_2_clicked();

        //void on_pushButton_clicked();

        void on_stat_clicked();

        //void on_pushButton_5_clicked();

        void on_pushButton_7_clicked();

        void on_pushButton_8_clicked();

        void on_pushButton_6_clicked();

        void on_pushButton_9_clicked();

        void on_trie_nom_clicked();

        void on_trie_ID_clicked();

        void on_trie_idCoach_clicked();

        void on_trie_horraire_clicked();

        void on_click_here_clicked();

        void on_evenements_vid_clicked();

        void on_retour_menu_clicked();

        void on_ajouter_cavalier_clicked();

        void on_supprimer_planning_cavalier_clicked();

        void on_pushButton_10_clicked();


        void on_cheval_2_clicked();

        void on_pushButton_back_3_clicked();

        void on_pushButton_back_4_clicked();

        void on_pushButton_back_5_clicked();

        void on_pushButton_back_6_clicked();



        //void on_ajouterBoutique_clicked();

        void on_pushButton_ModifierBoutique_clicked();

        void on_pushButtonSupprimerBoutique_clicked();

        //void on_pushButton_4_clicked();

        //void on_pushButton_3_clicked();

        void on_pushButton_ajouterBoutique_clicked();

        void on_pushButton_AfficherBoutique_clicked();
        void on_ajouter_blog_clicked();

        void on_afficher_blog_clicked();

        void on_modifier_blog_clicked();

        void on_supprimer_blog_clicked();

       // void on_blog_clicked();

        void on_retour_menu_2_clicked();

        void on_chevaux_vid_clicked();


        void on_pushButton_VoirBoutique_clicked();

        void on_pushButton_VoirBlog_clicked();

        void on_retour_menu_3_clicked();

        void on_pushButton_Reglage_4_clicked();

        void on_pushButton_TriBlog_clicked();

        void on_pushButtonPdfBoutique_clicked();

private:
    Ui::MainWindow *ui;
    planningCheval tmp;
    cheval temp;
    notifications N;
    //authentification a;
    void makePlotZAINEB();
    QMediaPlayer *son;
    QPropertyAnimation *animation ;
    QByteArray data;
    arduino A;


    void makePlot();


};
#endif // MAINWINDOW_H
