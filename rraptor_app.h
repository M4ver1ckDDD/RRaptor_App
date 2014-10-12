#ifndef RRAPTOR_APP_H
#define RRAPTOR_APP_H

#include <QMainWindow>
#include "user_controle.h"

namespace Ui {
class rraptor_app;
}

class rraptor_app : public QMainWindow
{
    Q_OBJECT

public:
    explicit rraptor_app(QWidget *parent = 0);
    ~rraptor_app();
public slots:

    void on_open_file_clicked();



private:
    Ui::rraptor_app *ui;
};

#endif // RRAPTOR_APP_H
