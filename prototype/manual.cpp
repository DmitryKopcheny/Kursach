#include "manual.h"
#include "ui_manual.h"
#include "localization.h" //локализация
manual::manual(Localization *Locale, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manual)
{
    ui->setupUi(this);
}

manual::~manual()
{
    delete ui;
}
