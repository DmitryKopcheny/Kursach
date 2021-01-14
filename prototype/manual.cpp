#include "manual.h"
#include "ui_manual.h"
#include "localization.h" //локализация
manual::manual(Localization *Locale, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manual)
{
    ui->setupUi(this);
    this->Locale = Locale;
}

manual::~manual()
{
    delete ui;
}

void manual::on_localizateWindows()
{
    this->setWindowTitle(Locale->getLclText(HOW_TO_USE));
    ui->label->setText(Locale->getLclText(GUIDE_LABLE));
    ui->label_2->setText(Locale->getLclText(GUIDE_TEXT));
}
