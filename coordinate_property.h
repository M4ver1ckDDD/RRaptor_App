#ifndef COORDINATE_PROPERTY_H
#define COORDINATE_PROPERTY_H

#include <QDialog>

namespace Ui {
class coordinate_property;
}

class coordinate_property : public QDialog
{
    Q_OBJECT

public:
    explicit coordinate_property(QWidget *parent = 0);
    ~coordinate_property();

private:
    Ui::coordinate_property *ui;

};

#endif // COORDINATE_PROPERTY_H
