#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "planningcheval.h"
#include "cheval.h"
#include <QMainWindow>
//#include <QtCharts>

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

    void on_afficher_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_pushButton_Quitter_clicked();

   // void on_ajouter_cheval_clicked();

    void on_QUITTER_1_clicked();

    void on_QUITTER_2_clicked();

    void on_QUITTER_3_clicked();

    void on_QUITTER_4_clicked();

    //void on_afficher_cheval_clicked();

    void on_modifier_cheval_clicked();

    void on_supprimer_cheval_clicked();

   // void on_tabWidget_2_currentChanged(int index);

    //void on_afficher_chev_currentChanged(int index);

    //void on_tabWidget_3_currentChanged(int index);

    //void on_Afficher_currentChanged(int index);

    //void on_pushButton_8_clicked();

    void on_recherche_chev_clicked();

    void on_statistique_clicked();
    QVector<double> Statistique();
   // void on_Afficher_currentChanged(int index);

    //void on_remplir_currentChanged(int index);

    void on_afficher_chev_currentChanged(int index);

    void on_ajouter_cheval_clicked();

    void on_afficher_plann_currentChanged(int index);

    void on_supprimer_plann_currentChanged(int index);

    void on_afficher_plann_clicked();

    void on_modifier_plann_clicked();

    void on_supprimer_plann_clicked();

    void on_statistique_plann_clicked();

    void on_afficher_cheval_clicked();

    void on_imprimer_planning_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_CHEVAL_currentChanged(int index);

    void on_comboBox_ID_cheval_activated(const QString &arg1);

    void on_pushButton_TRI_NUM_BOX_clicked();

    void on_pushButton_TRI_NOM_clicked();

    void on_PUSH_BUTTON_TRI_DATE_NAISS_clicked();

private:
    Ui::MainWindow *ui;
    planningCheval tmp;
    cheval temp;

    void makePlot();
};
#endif // MAINWINDOW_H
