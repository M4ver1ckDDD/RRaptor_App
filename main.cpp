#include "rraptor_app.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rraptor_app w;
    w.show();

    user_controle u_c_win;
    u_c_win.show();

    return a.exec();
}
