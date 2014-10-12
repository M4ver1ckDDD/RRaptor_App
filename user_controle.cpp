#include "user_controle.h"
#include "ui_user_controle.h"

user_controle::user_controle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_controle)
{
    ui->setupUi(this);
}

user_controle::~user_controle()
{
    delete ui;
}
