#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "planningcheval.h"
#include "cheval.h"
#include <QMessageBox>
#include <QDebug>
#include <QRadioButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



bool MainWindow::verifID()
{
    if (ui->Id_cheval->text().contains(QRegExp("[^0-9 ]") ) || ui->Id_cheval->text().isEmpty())
    {
        ui->Id_cheval->clear();

        ui->Id_cheval->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool MainWindow::verifNomactivite()
{
    if (ui->Nom_activite->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->Nom_activite->text().isEmpty())
    {
        ui->Nom_activite->clear();
        ui->Nom_activite->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
 //PLANNING_CHEVAL

void MainWindow::on_ajouter_clicked()
{
        planningCheval p;
        int Id_cheval=ui->Id_cheval->text().toInt ();
        QString Nom_activite=ui->Nom_activite->text() ;
        QString date_activite=ui->date_activite->text () ;
        QString duree=ui->duree->text();
        int  Id_cavalier=ui->Id_cavalier->text().toUInt();
        planningCheval p(Id_cheval,Nom_activite,date_activite,duree,Id_cavalier);

        bool test=p.ajouter();
            if(verifID()&&verifNomactivite())
            {
                if(test)
                {
                    ui->tableView->setModel(tmp.afficher());//refresh
                    QMessageBox msgBox ;
                    QMessageBox::information(this,"information","planning ajouté");

                    ui->Id_cheval->setText("");
                    ui->Nom_activite->setText("");
                    ui->date_activite->setText("");
                    ui->duree->setText("");
                    ui->Id_cavalier->setText("");

                }

            }
            else
            {
                QMessageBox msgBox ;
                msgBox.setText("planning non ajouté ");
            }
}

void MainWindow::on_afficher_clicked()
{ planningCheval p ;
    ui->tab_planning->setModel(p.afficher()) ;

}

void MainWindow::on_modifier_clicked()
{
    int Id_cheval = ui->Id_cheval->text().toInt();
       QString Nom_activite= ui->Nom_activite->text();
       QString date_activite = ui->date_activite->text();
       QString duree= ui->duree->text();
       int Id_cavalier= ui->Id_cavalier->text().toInt();






       bool test=tmp.modifier(Id_cheval, Nom_activite, date_activite, duree, Id_cavalier);
       if (test)
       {
           ui->tableView->setModel(tmp.afficher());

       }
}

void MainWindow::on_supprimer_clicked()
{
    int Id_cheval = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toInt();
       bool test=tmp.supprimer(Id_cheval);
       if(test)
       {
           ui->tableView->setModel(tmp.afficher());//refresh
           QMessageBox msgBox ;
           QMessageBox::information(this,"information","planning supprimé");
       }

       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Supprimer un planning"),
                                 QObject::tr("Erreur !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
       }

}

void MainWindow::on_pushButton_Quitter_clicked()
{
    close();
}

//*******************************************************************************************************************************
//cheval
void MainWindow::on_ajouter_cheval_clicked()
{
    cheval c;
    int Id_cheval=ui->idChev->text().toInt ();
    QString Nom=ui->nomChev->text() ;
    QString genre=ui->genreChev->text () ;
    QString date_de_naiss =ui->dateChev->text();
   // QString  vaccins=ui->vaccinChev->text();
    QString date_limite_vacc =ui->dateLimiteVaccin ->text();
    int poids=ui->poidsChev->text().toInt ();
    QString race=ui->raceChev->text () ;
    QString nationnalite =ui->nationnaliteChev->text();
    int num_box=ui->num_box->text().toInt ();
    //QString type_act =ui->type_actChev->text();

    cheval c(Id_cheval,Nom,genre,date_de_naiss,/*vaccins*/,date_limite_vacc,poids,race,nationnalite,num_box,/*type_act*/);
    bool test=c.ajouter();
        //if(verifID()&&verifNomactivite())
        {
            if(test)
            {
                ui->tableView->setModel(tmp.afficher());//refresh
                QMessageBox msgBox ;
                QMessageBox::information(this,"information","cheval ajouté");

                ui->idChev->setText("");
                ui->nomChev->setText("");
                ui->genreChev->setText("");
                //ui->dateChev->setDate("");
                //ui->vaccins->setText("");
                //ui->dateLimiteVaccin->setDate("");
                ui->poidsChev->setText("");
                ui->raceChev->setText("");
                ui->nationnaliteChev->setText("");
                ui->num_box->setText("");
                //ui->type_act->setText("");
               }
                else
                {
                    QMessageBox msgBox ;
                    msgBox.setText("cheval non ajouté ");
                }


}


void MainWindow::on_afficher_cheval_clicked()
{
    cheval c ;
        ui->tabCheval->setModel(c.afficher()) ;
}

void MainWindow::on_modifier_cheval_clicked()
{
    cheval c;
    int Id_cheval=ui->idChev->text().toInt ();
    QString Nom=ui->nomChev->text() ;
    QString genre=ui->genreChev->text () ;
    QString date_de_naiss =ui->dateChev->text();
   // QString  vaccins=ui->vaccinChev->text();
    QString date_limite_vacc =ui->dateLimiteVaccin ->text();
    int poids=ui->poidsChev->text().toInt ();
    QString race=ui->raceChev->text () ;
    QString nationnalite =ui->nationnaliteChev->text();
    int num_box=ui->num_box->text().toInt ();
    //QString type_act =ui->type_actChev->text();

    cheval c(Id_cheval,Nom,genre,date_de_naiss,/*vaccins*/,date_limite_vacc,poids,race,nationnalite,num_box,/*type_act*/);
       if (test)
       {
           ui->tableView->setModel(tmp.afficher());

       }
}

void MainWindow::on_supprimer_cheval_clicked()
{
    int Id_cheval = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toInt();
       bool test=tmp.supprimer(Id_cheval);
       if(test)
       {
           ui->tableView->setModel(tmp.afficher());//refresh
           QMessageBox msgBox ;
           QMessageBox::information(this,"information","cheval supprimé");
       }

       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Supprimer un cheval"),
                                 QObject::tr("Erreur !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
       }
}

void MainWindow::on_QUITTER_1_clicked()
{
    close();
}

void MainWindow::on_QUITTER_2_clicked()
{
    close();
}

void MainWindow::on_QUITTER_3_clicked()
{
    close();
}

void MainWindow::on_QUITTER_4_clicked()
{
    close();
}
}
