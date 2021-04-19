#include "notifications.h"
#include <QSystemTrayIcon>
#include<QString>
notifications::notifications()
{

}
void notifications::notifications_ajoutcheval()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des chevaux ","Nouveau cheval ajouté ",QSystemTrayIcon::Information,15000);
}
