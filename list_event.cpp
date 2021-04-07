#include "list_event.h"
#include "ui_participant.h"

participant::participant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::participant)
{
    ui->setupUi(this);
}

participant::~participant()
{
    delete ui;
}
