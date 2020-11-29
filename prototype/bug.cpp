#include "bug.h"
#include "ui_bug.h"
#include "localization.h" //локализация
bug::bug(Localization *Locale, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bug)
{
    ui->setupUi(this);
}

bug::~bug()
{
    delete ui;
}
