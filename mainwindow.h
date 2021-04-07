#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "event.h"
#include <QVariant>

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
    void on_pushButton_clicked();





    void on_pb_supprimer_clicked();

    void on_pb_ajouter2_clicked();


    void on_pb_modifier_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_modifier2_clicked();

    void on_pb_pdf_clicked();



private:
    Ui::MainWindow *ui;
    class event E;
signals:
    void setCenter(QVariant,QVariant);


};

#endif // MAINWINDOW_H
