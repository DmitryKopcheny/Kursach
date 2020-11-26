#include "settings.h"
#include "ui_settings.h"
#include <QFile>

settings::settings(int LangCode, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(LangCode);
}

settings::~settings()
{
    delete ui;
}

void settings::on_btnlight_clicked()
{
    styleF.setFileName(":/new/lightstyle.css");
    styleF.open(QFile::ReadOnly);
    QString cssStr = styleF.readAll();

    qApp->setStyleSheet(cssStr);
}


void settings::on_btndark_clicked()
{
    styleF.setFileName(":/new/darkstyle.css");
    styleF.open(QFile::ReadOnly);
    QString cssStr = styleF.readAll();

    qApp->setStyleSheet(cssStr);
}

void settings::on_comboBox_currentIndexChanged(int index)
{
    emit LanguageChanged(index);
}
