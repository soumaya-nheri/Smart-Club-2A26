#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <QDialog>

namespace Ui {
class participant;
}

class participant : public QDialog
{
    Q_OBJECT

public:
    explicit participant(QWidget *parent = nullptr);
    ~participant();

private:
    Ui::participant *ui;
};

#endif // PARTICIPANT_H
