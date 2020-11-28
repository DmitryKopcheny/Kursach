#include "testwin.h"
#include "ui_testwin.h"

testwin::testwin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testwin)
{
    ui->setupUi(this);
}

testwin::~testwin()
{
    delete ui;
}
