#include "bug.h"
#include "ui_bug.h"
#include "localization.h"
bug::bug(Localization *Locale, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bug)
{
    ui->setupUi(this);
    this->Locale = Locale;
}


bug::~bug()
{
    delete ui;
}

void bug::on_btn_Send_clicked()
{
    ui->textEdit->clear();
}
void bug::on_localizateWindows()
{
  this->setWindowTitle(Locale->getLclFindbug());
  ui->label_2->setText(Locale->getLclBugReportLable());
  ui->btn_Send->setText(Locale->getLclbtnSend());
}
