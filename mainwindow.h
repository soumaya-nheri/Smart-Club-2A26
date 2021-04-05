#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "planningcheval.h"
#include "cheval.h"
#include <QMainWindow>

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


    void on_ajouter_clicked();

    void on_afficher_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_pushButton_Quitter_clicked();

    void on_ajouter_cheval_clicked();

    void on_QUITTER_1_clicked();

    void on_QUITTER_2_clicked();

    void on_QUITTER_3_clicked();

    void on_QUITTER_4_clicked();

    //void on_afficher_cheval_clicked();

    void on_modifier_cheval_clicked();

    void on_supprimer_cheval_clicked();

   // void on_tabWidget_2_currentChanged(int index);

    void on_afficher_chev_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    planningCheval tmp;
    cheval temp;

};
#endif // MAINWINDOW_H
