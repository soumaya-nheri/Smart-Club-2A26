#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipement.h"
#include "fournisseur.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QPrinter>
#include <QFileDialog>
#include<QTextDocument>
#include <QDate>
#include <QDateEdit>
#include <QSystemTrayIcon>
#include<QPainter>
#include <QMediaPlayer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabfournisseur->setModel(f.afficher());
    ui->tabequipement->setModel(e.afficher());
}
bool MainWindow::verifID()
{
    if (ui->lineedit_id->text().contains(QRegExp("[^0-9 ]") ) || ui->lineedit_id->text().isEmpty())
    {
        ui->lineedit_id->clear();

        ui->lineedit_id->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifTYPE()
{
    if (ui->lineEdit_type->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_type->text().isEmpty())
    {
        ui->lineEdit_type->clear();
        ui->lineEdit_type->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifQuantite()
{
    if (ui->lineEdit_quantite->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_quantite->text().isEmpty())
    {
        ui->lineEdit_quantite->clear();

        ui->lineEdit_quantite->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineedit_id->text().toInt();
    QString type= ui->lineEdit_type->text();
    int quantite= ui->lineEdit_quantite->text().toInt();
    QDate date= ui->dateEdit_2->date();
    QString etat= ui->lineEdit_etat->text();
    QDate deadline= ui->dateEdit->date();
    int prix= ui->lineEdit_prix->text().toInt();

    srand (time(NULL));

    QDate d = QDate::currentDate() ;
    QString datee =d.toString("dd / MM / yyyy ") ;
    QString fn="ajouter" ;
   QString nom1 = ui->lineEdit_type->text();

    equipementh pp(nom1,datee,fn) ;
    bool test1=pp.ajoutehis() ;



    Equipement e (id, prix,quantite, date,deadline ,etat,type);
    if(verifID()&&verifTYPE()&&verifQuantite()) {
        bool test=e.ajouter();
    if(test)
    {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("icone.png"));
        notifyIcon->showMessage("gestion equipement ","equipement ajouter",QSystemTrayIcon::Information,15000);


        QMediaPlayer * erreur = new QMediaPlayer ;
        erreur->setMedia(QUrl("C:/Users/Eya/Desktop/gestion_equipement/sounds/projetajoute.mp3")) ;
            erreur->setVolume(100) ;
            erreur->play() ;
    ui->tabequipement->setModel(e.afficher());

    QMessageBox::information(nullptr, QObject::tr("Ajout effectue"),
    QObject::tr("OK.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);

    }
    }
    else{
        QMediaPlayer * erreur = new QMediaPlayer ;
       erreur->setMedia(QUrl("C:/Users/Eya/Desktop/gestion_equipement/sounds/erreur.mp3")) ;
           erreur->setVolume(100) ;
           erreur->play() ;
    QMessageBox::critical(nullptr, QObject::tr("Ajout non effectue"),
    QObject::tr("KO.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_5_clicked()
{
    int id = ui->lineEdit_id2->text().toInt();
    QString email= ui->lineEdit_email->text();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_pren->text();
    int tel = ui->lineEdit_tele->text().toInt();

    fournisseur f(id,tel,email,nom,prenom);
    bool test=f.ajouter();
    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
    le->clear();
    }
    if(test)
    {
    ui->tabfournisseur->setModel(f.afficher());
    QMessageBox::information(nullptr, QObject::tr("Ajout effectue"),
    QObject::tr("OK.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    QMessageBox::critical(nullptr, QObject::tr("Ajout non effectue"),
    QObject::tr("KO.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton10_clicked()
{
    QDate d = QDate::currentDate() ;
     QString datee =d.toString("dd / MM / yyyy ") ;
     QString fn="modifier" ;

       int id = ui->lineEdit_modid->text().toInt();
       int quantite= ui->lineEdit_modquan->text().toInt();
       QString type= ui->lineEdit_modtype->text();
       QDate date= ui->dateEdit_2->date();
       QDate deadline= ui->dateEdit->date();
       QString etat= ui->lineEdit_modetat->text();
       int prix= ui->lineEdit_modprix->text().toInt();

       QString nom1 = ui->lineEdit_modtype->text();
       equipementh pp(nom1,datee,fn) ;
       bool test1=pp.modifierhis() ;
       Equipement e;
       bool test=e.modifier(id, prix,quantite, date,deadline ,etat,type);
       foreach(QLineEdit* le, findChildren<QLineEdit*>())
       {
          le->clear();
       }
       if(test)
       {
           QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                   notifyIcon->show();
                   notifyIcon->setIcon(QIcon("icone.png"));
                   notifyIcon->showMessage("gestion equipement ","equipement modifié",QSystemTrayIcon::Information,15000);


                   QMediaPlayer * erreur = new QMediaPlayer ;
                   erreur->setMedia(QUrl("C:/Users/Eya/Desktop/gestion_equipement/sounds/projetmodif.mp3")) ;
                       erreur->setVolume(100) ;
                       erreur->play() ;
           QMessageBox::information(nullptr, QObject::tr("Modification effectue"),
                       QObject::tr("OK.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tabequipement->setModel(e.afficher());

      }
       else {
           QMediaPlayer * erreur = new QMediaPlayer ;
          erreur->setMedia(QUrl("C:/Users/Eya/Desktop/gestion_equipement/sounds/erreur.mp3")) ;
              erreur->setVolume(100) ;
              erreur->play() ;
           QMessageBox::critical(nullptr, QObject::tr("Modification non effectue"),
                       QObject::tr("KO.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int id;

        id=ui->lineEdit_rech->text().toInt();
    bool test= true;
    if(test==(true))
    {
      ui->tabequipement->setModel(e.rechercher(id));
}
}

void MainWindow::on_pb_supprimer_3_clicked()
{
    int id = ui->lineEdit_sup->text().toInt();

    bool test=e.supprimer(id);
    QDate d = QDate::currentDate() ;
     QString datee =d.toString("dd / MM / yyyy ") ;
     QString fn="supprimer" ;
     QString nom1 = ui->lineEdit_modtype->text();
      equipementh pp(nom1,datee,fn) ;
     bool test1=pp.modifierhis() ;
    if(test)
    {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();
                notifyIcon->setIcon(QIcon("icone.png"));
                notifyIcon->showMessage("gestion equipement ","equipement supprimé",QSystemTrayIcon::Information,15000);


                QMediaPlayer * erreur = new QMediaPlayer ;
                erreur->setMedia(QUrl("C:/Users/Eya/Desktop/gestion_equipement/sounds/equipementsup.mp3")) ;
                    erreur->setVolume(100) ;
                    erreur->play() ;

        ui->tabequipement->setModel(e.afficher());     //refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un equipement"),
                    QObject::tr("Equipement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{
    QString str;
    str.append("<html><head></head><body><center>"+QString("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;;<font size=""10"" color =""red""> GESTION DES EQUIPEMENTS </font><br /> <br /> "));
    str.append("<table border=1><tr>");
    str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">id</font>&nbsp;&nbsp;"+"</td>");
    str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">type</font>&nbsp;&nbsp;"+"</td>");
    str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""20"">quantite</font>&nbsp;&nbsp;")+"</td>");
    str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">date</font>&nbsp;&nbsp;")+"</td>");
    QSqlQuery * query=new QSqlQuery();
    query->exec("SELECT id_produit,type,quantite,date_arrivee FROM equipement");
    while(query->next())
    {
        str.append("<tr><td>");
        str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(0).toString()+"&nbsp;&nbsp;");
        str.append("</td><td>");
        str.append("&nbsp;&nbsp;<font color =""green""  size=""10"">"+query->value(1).toString()+"&nbsp;&nbsp;");
        str.append("</td><td>");
        str.append("&nbsp;&nbsp;<font color =""green"" size=""10"">"+query->value(2).toString()+"&nbsp;&nbsp;");
         str.append("</td><td>");
        str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(3).toString()+"&nbsp;&nbsp;");
        str.append("</td></tr>");

}

    str.append("</table></center><body></html>");

    QPrinter printer;
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);

    QString path= QFileDialog::getSaveFileName(NULL,"imprimer","gestion des equipements","PDF(*.pdf");
     if(path.isEmpty()) return;
     printer.setOutputFileName(path);
     QTextDocument doc;
     doc.setHtml(str);
     doc.print(&printer);
}

void MainWindow::on_pushButton_mod_clicked()
{
       int id = ui->lineEdit_modid_2->text().toInt();
       QString email=ui->lineedit_modemail->text();
       QString nom= ui->lineEdit_modnom->text();
       QString prenom= ui->lineEdit_modprenom->text();
       int tel= ui->lineEdit_modtel->text().toInt();


       fournisseur f;
       bool test=f.modifier( id, tel, email, nom, prenom);
       foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
          le->clear();
       }
       if(test)
       {
           ui->tabfournisseur->setModel(f.afficher());

           QMessageBox::information(nullptr, QObject::tr("Modification effectue"),
                       QObject::tr("OK.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Modification non effectue"),
                       QObject::tr("KO.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_supp_clicked()
{
    int id = ui->lineEdit_14->text().toInt();
    bool test=f.supprimer(id);
    if(test)
    {             ui->tabfournisseur->setModel(f.afficher());     //refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                    QObject::tr("Fournisseur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_dateEdit_2_userDateChanged(const QDate )
{
   QDateTimeEdit *dateEdit = new QDateTimeEdit(QDate::currentDate());
    dateEdit->setMinimumDate(QDate::currentDate().addDays(-365));
    dateEdit->setMaximumDate(QDate::currentDate().addDays(365));
    dateEdit->setDisplayFormat("yyyy.MM.dd");
}
void MainWindow::on_dateEdit_userDateChanged(const QDate )
{
    QDateTimeEdit *dateEdit = new QDateTimeEdit(QDate::currentDate());
    dateEdit->setMinimumDate(QDate::currentDate().addDays(-365));
    dateEdit->setMaximumDate(QDate::currentDate().addDays(365));
    dateEdit->setDisplayFormat("yyyy.MM.dd");
}

void MainWindow::on_pushButton_clicked()
{
    ui->tabhis->setModel(tmph.afficherhis()) ;
    ui->tabhis->setModel(tmph.afficherhis());//refresh
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tabequipement->setModel(e.afficher());
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tabequipement->setModel( e.afficher_tri());
    ui->tabequipement->setModel( e.afficher_tri());
}

void MainWindow::on_pushButton_6_clicked()
{
    lng="ANG";
                    // page biblo

                    ui->pb_ajouter->setText("ADD");
                    ui->pb_ajouter_2->setText("FIND");
                    ui->pushButton10->setText("EDIT");
                    ui->pb_supprimer_3->setText("REMOVE");
                    ui->pushButton_2->setText("PRINT");
                    ui->label_8->setText("enter the project ID");
                    //----------------------------------//
}

void MainWindow::on_pushButton_7_clicked()
{
    lng="FR";
                    // page biblo

                    ui->pb_ajouter->setText("AJOUTER");
                    ui->pb_ajouter_2->setText("RECHERCHER");
                    ui->pushButton10->setText("MODIFIER");
                    ui->pb_supprimer_3->setText("SUPPRIMER");
                    ui->pushButton_2->setText("IMPRIMER");
                    ui->label_8->setText("entrer l'ID de l'equipement");
}

void MainWindow::on_pushButton_8_clicked()
{
    QTableView *table;
                           table = ui->tabequipement;
                           QString filters("CSV files (.csv);;All files (.*)");
                           QString defaultFilter("CSV files (*.csv)");
                           QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                              filters, &defaultFilter);
                           QFile file(fileName);
                           QAbstractItemModel *model =  table->model();
                           if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                               QTextStream data(&file);
                               QStringList strList;
                               for (int i = 0; i < model->columnCount(); i++) {
                                   if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                       strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                                   else
                                       strList.append("");
                               }
                               data << strList.join(";") << "\n";
                               for (int i = 0; i < model->rowCount(); i++) {
                                   strList.clear();
                                   for (int j = 0; j < model->columnCount(); j++) {
                                       if (model->data(model->index(i, j)).toString().length() > 0)
                                           strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                       else
                                           strList.append("");
                                   }
                                   data << strList.join(";") + "\n";
                               }
                               file.close();
                               //QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");

}}
