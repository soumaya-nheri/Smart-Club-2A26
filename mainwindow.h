#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "equipement.h"
#include "fournisseur.h"
#include <QObject>
#include <QDate>
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
    void on_pb_ajouter_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton10_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_mod_clicked();

    void on_pushButton_supp_clicked();

    void on_dateEdit_2_userDateChanged(const QDate );

    void on_dateEdit_userDateChanged(const QDate );

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    bool verifID();
    bool verifTYPE();
    bool verifQuantite();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    fournisseur f;
    Equipement e;
    equipementh tmph;
    QString lng="fr";
};
#endif // MAINWINDOW_H
