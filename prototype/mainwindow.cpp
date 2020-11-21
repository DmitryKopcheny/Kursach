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
    ui->layout_enter->move(10,400);
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
    connect(esf, SIGNAL(LanguageChanged(int)),this, SLOT(on_LanguageChanged(int)));
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


void MainWindow::on_btn1_clicked()//що таке АМ
{
  ui->layout_details->show();
  ui->layout_main->hide();
  ui->layout_enter->hide();

  Chat->addNewMessage(true, ui->btn1->text());
  Chat->addNewMessage(false, Chat->getAboutAM());
  displayChat();
}
void MainWindow::on_btn2_clicked()//університети
{
  ui->layout_patners->show();
  ui->layout_main->hide();
  ui->layout_enter->hide();

  QString partners;
  for (int i = 0; i<Chat->getSizeOfUniv(); i++)
    {
      partners += Chat->getUnName(i);
      partners += "\n";
    }
  Chat->addNewMessage(true, ui->btn2->text());
  Chat->addNewMessage(false, partners);
  displayChat();
}
void MainWindow::on_btn3_clicked()//реєстація
{
  ui->layout_enter->show();
  ui->layout_main->hide();
  Chat->addNewMessage(true, ui->btn3->text());
  //Chat->addNewMessage(false, "Файл відсутній");         //метод відсутній //введите fullName
  displayChat();
}

void MainWindow::on_btn_enter_clicked()
{
  if (studInfo == 0)
    {
      studInfo = new Student;
    }
  if (studInfo->fullName.isEmpty())
    {
      Chat->addNewMessage(true, ui->lineEdit->text());
      studInfo->fullName = ui->lineEdit->text();
      Chat->addNewMessage(false, "Файл відсутній");         //метод відсутній

    }
  if (studInfo->group.isEmpty())
    {
      Chat->addNewMessage(false, "Файл відсутній");         //метод відсутній

    }
  if (studInfo->phoneNumber.isEmpty())
    {
      Chat->addNewMessage(false, "Файл відсутній");         //метод відсутній

    }
  if (studInfo->phoneNumber.isEmpty())
    {
      Chat->addNewMessage(false, "Файл відсутній");         //метод відсутній

    }

  ui->layout_main->show();
  ui->layout_enter->hide();
}

void MainWindow::on_btn4_clicked()//контакти
{
  Chat->addNewMessage(true, ui->btn4->text());
  Chat->addNewMessage(false, Chat->getContacts());
  displayChat();
}


void MainWindow::on_btn1_1_clicked()//для кого це
{
  Chat->addNewMessage(true, ui->btn1_1->text());
  Chat->addNewMessage(false, Chat->getForWhom());
  displayChat();
}

void MainWindow::on_btn1_2_clicked()//мова
{
  Chat->addNewMessage(true, ui->btn1_2->text());
  Chat->addNewMessage(false, Chat->getRequiredLang());
  displayChat();
}

void MainWindow::on_btn1_3_clicked()//коштoвність
{
  Chat->addNewMessage(true, ui->btn1_3->text());
  Chat->addNewMessage(false, Chat->getPayments());
  displayChat();
}

void MainWindow::on_btn1_4_clicked()//з чого почати
{
  ui->layout_letter->show();
  ui->layout_details->hide();

  Chat->addNewMessage(true, ui->btn4->text());
  Chat->addNewMessage(false, Chat->getWhereToStart());
  displayChat();
}

void MainWindow::on_btn1_4_1_clicked()//приклад мотиваційного листа
{
  Chat->addNewMessage(true, ui->btn1_4_1->text());
  Chat->addNewMessage(false, "Файл Відсутній");             //метод відсутній
  displayChat();
}

void MainWindow::on_btn2_1_clicked()//унівеситет 1
{
  QString university;
  university += Chat->getUnName(0);
  university += "\n";
  university += Chat->getMainInfo(0);
  Chat->addNewMessage(true, ui->btn2_1->text());
  Chat->addNewMessage(false, university);
  displayChat();
}

void MainWindow::on_btn2_2_clicked()//унівеситет 2
{
  QString university;
  university += Chat->getUnName(1);
  university += "\n";
  university += Chat->getMainInfo(1);
  Chat->addNewMessage(true, ui->btn2_2->text());
  Chat->addNewMessage(false, university);
  displayChat();
}

void MainWindow::on_btn2_3_clicked()//унівеситет 3
{
  QString university;
  university += Chat->getUnName(2);
  university += "\n";
  university += Chat->getMainInfo(2);
  Chat->addNewMessage(true, ui->btn2_3->text());
  Chat->addNewMessage(false, university);
  displayChat();
}

void MainWindow::on_btn2_4_clicked()//унівеситет 4
{
  QString university;
  university += Chat->getUnName(3);
  university += "\n";
  university += Chat->getMainInfo(3);
  Chat->addNewMessage(true, ui->btn2_4->text());
  Chat->addNewMessage(false, university);
  displayChat();
}

void MainWindow::on_btn2_5_clicked()//унівеситет 5
{
  QString university;
  university += Chat->getUnName(4);
  university += "\n";
  university += Chat->getMainInfo(4);
  Chat->addNewMessage(true, ui->btn2_5->text());
  Chat->addNewMessage(false, university);
  displayChat();
}

void MainWindow::on_btn2_6_clicked()//унівеситет 6
{
  QString university;
  university += Chat->getUnName(5);
  university += "\n";
  university += Chat->getMainInfo(5);
  Chat->addNewMessage(true, ui->btn2_6->text());
  Chat->addNewMessage(false, university);
  displayChat();
}

void MainWindow::on_btn1_back_clicked()//назад
{
  ui->layout_main->show();
  ui->layout_details->hide();
}
void MainWindow::on_btn2_back_clicked()//назад
{
  ui->layout_main->show();
  ui->layout_patners->hide();
}

void MainWindow::on_btn1_4_back_clicked()//назад
{
  ui->layout_details->show();
  ui->layout_letter->hide();
}
void  MainWindow::on_LanguageChanged(int index) //больше изменение языка интерфейса
{
  Chat->setLang(index);
  Chat->readFromXml(Chat->getLang());
  Chat->readFromCsv(Chat->getLang());
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
  ui->textBrowser->clear();
  Chat->resetIterators();
  while (!Chat->isEnd())
    {

      if (Chat->getIsUsersMessage())
        {
          QString nameAndDate;
          ui->textBrowser->setAlignment(Qt::AlignRight);
          nameAndDate.append(Chat->getNextTime()).append(" USER:");
          ui->textBrowser->append(nameAndDate);
          ui->textBrowser->append(Chat->getNextMessage()+="\n");
        }
      else
        {
          QString nameAndDate;
          ui->textBrowser->setAlignment(Qt::AlignLeft);
          nameAndDate.append(Chat->getNextTime()).append(" BOT:");
          ui->textBrowser->append(nameAndDate);
          ui->textBrowser->append(Chat->getNextMessage()+="\n");
        }
    }

}


