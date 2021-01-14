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
    emit BugReported(ui->textEdit->toPlainText());
    ui->textEdit->clear();
    this->close();
}
void bug::on_localizateWindows()
{
    this->setWindowTitle(Locale->getLclText(FOUND_BUG));
    ui->label_2->setText(Locale->getLclText(BUG_REPORT_LABLE));
    ui->btn_Send->setText(Locale->getLclText(SEND));
}
