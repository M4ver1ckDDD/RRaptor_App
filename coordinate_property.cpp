#include "coordinate_property.h"
#include "ui_coordinate_property.h"
#include "ui_rraptor_app.h"

coordinate_property::coordinate_property(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::coordinate_property)
{
    ui->setupUi(this);
}

coordinate_property::~coordinate_property()
{
    delete ui;
}
