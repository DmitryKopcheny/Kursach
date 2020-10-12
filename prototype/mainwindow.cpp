#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "developer.h"
#include "rateapp.h"
#include "bug.h"
#include "manual.h"
#include "settings.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->layout_details->hide();
    ui->layout_letter->hide();
    ui->layout_patners->hide();
    ui->layout_enter->hide();

}
void MainWindow::on_action_3_triggered()
{
    developer *esf = new developer();
    esf->show();
}

void MainWindow::on_action_2_triggered()
{
    rateApp *esf = new rateApp();
    esf->show();
}

void MainWindow::on_action_4_triggered()
{
    settings *esf = new settings();
    esf->show();
}

void MainWindow::on_action_triggered()
{
    manual *esf = new manual();
    esf->show();
}

void MainWindow::on_action_5_triggered()
{
    bug *esf = new bug();
    esf->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn1_clicked()
{
 ui->layout_details->show();
 ui->layout_main->hide();
}
void MainWindow::on_btn2_clicked()
{
 ui->layout_patners->show();
 ui->layout_main->hide();
}
void MainWindow::on_btn3_clicked()
{
 ui->layout_enter->show();
 //ui->layout_main->hide();
}
void MainWindow::on_btn1_4_clicked()
{
 ui->layout_letter->show();
 ui->layout_details->hide();
}

void MainWindow::on_btn1_back_clicked()
{
 ui->layout_main->show();
 ui->layout_details->hide();
}
void MainWindow::on_btn2_back_clicked()
{
 ui->layout_main->show();
 ui->layout_patners->hide();
}

void MainWindow::on_btn1_4_back_clicked()
{
 ui->layout_details->show();
 ui->layout_letter->hide();
}

