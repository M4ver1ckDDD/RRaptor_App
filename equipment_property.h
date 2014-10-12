#ifndef EQUIPMENT_PROPERTY_H
#define EQUIPMENT_PROPERTY_H

#include <QDialog>

namespace Ui {
class equipment_property;
}

class equipment_property : public QDialog
{
    Q_OBJECT

public:
    explicit equipment_property(QWidget *parent = 0);
    ~equipment_property();

private:
    Ui::equipment_property *ui;
};

#endif // EQUIPMENT_PROPERTY_H
