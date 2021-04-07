#ifndef ADMIN_H
#define ADMIN_H

#include"mainwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class admin : public admin
{
    Q_OBJECT

public:
    admin *parent = nullptr);
    ~admin();

private slots:
    void on_connecter_clicked();

    void on_modepasseoublie_clicked();

private:

    MainWindow*mainwindow;
   // Dialog *Dialog;
};
#endif // MAINWINDOW_H

#endif // ADMIN_H
