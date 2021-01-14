#include "developer.h"
#include "ui_developer.h"
#include "localization.h" //локализация

developer::developer(Localization *Locale, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::developer)
{
    ui->setupUi(this);
    this->Locale = Locale;
}

developer::~developer()
{
    delete ui;
}

void developer::on_localizateWindows()
{
    this->setWindowTitle(Locale->getLclText(MORE_DETAILS));
    ui->label->setText(Locale->getLclText(FREE_CHATBOT));
    ui->label_2->setText(Locale->getLclText(VERSION));
    ui->label_3->setText(Locale->getLclText(DEVEL_LABLE));
    ui->label_4->setText(Locale->getLclText(DEVEL_TEXT));

    ui->label_8->setText(Locale->getLclText(OLEG_NAME));
    ui->label_9->setText(Locale->getLclText(DIMA_NAME));
    ui->label_10->setText(Locale->getLclText(VLAD_NAME));
    ui->label_11->setText(Locale->getLclText(MIKE_NAME));

}

