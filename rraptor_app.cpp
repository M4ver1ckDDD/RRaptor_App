#include "rraptor_app.h"
#include "ui_rraptor_app.h"
#include "coordinate_property.h"
#include<QFileDialog>

rraptor_app::rraptor_app(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rraptor_app)
{
    ui->setupUi(this);

    connect(ui->open_file,SIGNAL(triggered()),this,SLOT(on_open_file_clicked()));


}

rraptor_app::~rraptor_app()
{
    delete ui;
}

void rraptor_app::on_open_file_clicked(){
    ui->widget->f= QFileDialog::getOpenFileName(this,QString("Открыть файл"),QString(),QString(" Stl файлы (*.stl);; Все файлы(*.*)"));
}




