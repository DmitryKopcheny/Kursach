#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
}

settings::~settings()
{
    delete ui;
}

void settings::on_btnlight_clicked()
{

}

void settings::on_btndark_clicked()
{

}
