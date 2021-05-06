#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "staff.h"
#include "planning.h"
#include "todolist.h"



#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    int Statistique_partie2() ;
    int Statistique_partie3() ;
    int Statistique_partie4() ;

    void paintEvent(QPaintEvent *) ;
    ~MainWindow();


private slots:








    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();



    void on_pb_ajouter_clicked();

    void on_ajouter2_clicked();

    void on_supp_clicked();

    void on_modifier_clicked();

    void on_pb_ajouter_2_clicked();

private:
    Ui::MainWindow *ui;
    Staff tmpstaff;
    planning tmpplanning;
    CToDoList *app;

};

#endif // MAINWINDOW_H
