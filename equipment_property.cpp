#include "equipment_property.h"
#include "ui_equipment_property.h"

equipment_property::equipment_property(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::equipment_property)
{
    ui->setupUi(this);
}

equipment_property::~equipment_property()
{
    delete ui;
}
