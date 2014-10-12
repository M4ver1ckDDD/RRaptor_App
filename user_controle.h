#ifndef USER_CONTROLE_H
#define USER_CONTROLE_H

#include <QDialog>

namespace Ui {
class user_controle;
}

class user_controle : public QDialog
{
    Q_OBJECT

public:
    explicit user_controle(QWidget *parent = 0);
    ~user_controle();

private:
    Ui::user_controle *ui;
};

#endif // USER_CONTROLE_H
