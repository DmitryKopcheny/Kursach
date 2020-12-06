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
    this->setWindowTitle(Locale->getLclMoredetails());
    ui->label->setText(Locale->getLclFreeChatBot());
    ui->label_2->setText(Locale->getLclVersin());
    ui->label_3->setText(Locale->getLclDevelLabel());
    ui->label_4->setText(Locale->getLclDevelText());

    ui->label_8->setText(Locale->getLclDevOlegName());
    ui->label_9->setText(Locale->getLclDevDimaName());
    ui->label_10->setText(Locale->getLclDevVladName());
    ui->label_11->setText(Locale->getLclDevMikeName());

}
