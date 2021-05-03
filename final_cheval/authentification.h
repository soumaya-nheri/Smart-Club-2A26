#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

#include <QDialog>
#include "mainwindow.h"
#include "dialog.h"
namespace Ui {
class authentification;
}

class authentification : public QDialog
{
    Q_OBJECT

public:
    explicit authentification(QWidget *parent = nullptr);
    ~authentification();

private slots:
    void on_ButtonConnecter_clicked();

    void on_mot_de_passe_oubli_linkActivated(const QString &link);

private:
    Ui::authentification *ui;
    //MainWindow *mainwindow ;

};

#endif // AUTHENTIFICATION_H
