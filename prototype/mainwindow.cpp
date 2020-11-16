#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "developer.h"
#include "rateapp.h"
#include "bug.h"
#include "manual.h"
#include "settings.h"
#include "textchat.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->layout_details->hide();
    ui->layout_letter->hide();
    ui->layout_patners->hide();
    ui->layout_enter->hide();

    ui->layout_details->move(0,400);
    ui->layout_letter->move(0,400);
    ui->layout_patners->move(0,400);

    Chat = new TextChat;

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
 ui->layout_enter->hide();
}
void MainWindow::on_btn2_clicked()
{
 ui->layout_patners->show();
 ui->layout_main->hide();
 ui->layout_enter->hide();
}
void MainWindow::on_btn3_clicked()
{
 ui->layout_enter->show();
displayChat();
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
void MainWindow::displayChat()
{
  /*
  void addNewMessage(bool isUsers, QString message);
  //void sendMessage(QString code);
  void resetIterators();
  QString getNextMessage();
  QString getNextTime();
  bool getIsUsersMessage();*/
  /*QList<QDateTime> time;
  QList<QString> messages;
  QList<bool> isUsersMessage;*/
  Chat->addNewMessage(true, "Cyyyyka blyaaat nahui daaa");
  Chat->addNewMessage(false, "Cyyyyka blyaaat nahui daaa");
  Chat->addNewMessage(true, "Cyyyyka blyaaat nahui daaa");
  Chat->addNewMessage(false, "Cyyyyka blyaaat nahui daaa");
  Chat->addNewMessage(true, "Cyyyyka blyaaat nahui daaa");
  Chat->resetIterators();
  while (!Chat->isEnd())
    {

      if (Chat->getIsUsersMessage())
        {
          QString nameAndDate;
          ui->textBrowser->setStyleSheet("QTextBrowser{text-align:left}");
          nameAndDate.append(Chat->getNextTime()).append(" BOT:");
          ui->textBrowser->append(nameAndDate);
          ui->textBrowser->append(Chat->getNextMessage()+="\n");
        }
      else
        {
          QString nameAndDate;
          ui->textBrowser->setStyleSheet("p align=right");
          nameAndDate.append(Chat->getNextTime()).append(" USER:");
          ui->textBrowser->append(nameAndDate);
          ui->textBrowser->append(Chat->getNextMessage()+="\n");
        }
      //ui->textEdit->append(Chat->getNextTime());
      //ui->textEdit->append("\n");
        //ui->textBrowser->append(Chat->getNextMessage()+="\n");
      //ui->textEdit->append("\n");
    }

}
