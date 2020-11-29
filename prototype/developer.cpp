#include "developer.h"
#include "ui_developer.h"
#include "localization.h" //локализация

developer::developer(Localization *Locale, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::developer)
{
    ui->setupUi(this);

}

developer::~developer()
{
    delete ui;
}
