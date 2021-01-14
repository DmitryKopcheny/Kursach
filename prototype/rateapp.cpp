#include "rateapp.h"
#include "ui_rateapp.h"
#include "localization.h" //локализация
rateApp::rateApp(Localization *Locale, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rateApp)
{
    ui->setupUi(this);
    ui->label_2->hide();
    this->Locale = Locale;
    feedback = 0;
}

rateApp::~rateApp()
{
    delete ui;
}

void rateApp::on_rate1_clicked()
{
    ui->label_2->move(95,150);
    ui->label_2->show();
    feedback = 1;

}

void rateApp::on_rate2_clicked()
{
    ui->label_2->move(155,150);
    ui->label_2->show();
    feedback = 2;
}

void rateApp::on_rate3_clicked()
{
    ui->label_2->move(215,150);
    ui->label_2->show();
    feedback = 3;
}

void rateApp::on_rate4_clicked()
{
    ui->label_2->move(275,150);
    ui->label_2->show();
    feedback = 4;
}

void rateApp::on_rate5_clicked()
{
    ui->label_2->move(335,150);
    ui->label_2->show();
    feedback = 5;
}

void rateApp::on_localizateWindows()
{
    this->setWindowTitle(Locale->getLclText(RATE_APP));
    ui->label->setText(Locale->getLclText(RATE_APP));
    ui->btn_Send->setText(Locale->getLclText(SEND));
}

void rateApp::on_btn_Send_clicked()
{
    ui->label_2->hide();
    emit FeedbackSent(feedback);
    this->close();
}
