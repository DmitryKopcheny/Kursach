#include "settings.h"
#include "ui_settings.h"
#include <QFile>
#include "localization.h" //локализация
settings::settings(Localization *Locale, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    this->Locale = Locale;
    ui->comboBox->setCurrentIndex(Locale->getLangCode());
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
  Locale->setLang(index);
    emit LanguageChanged();
}

void settings::on_localizateWindows()
{
  this->setWindowTitle(Locale->getLclSettings());
  ui->label_2->setText(Locale->getLclTheme());
  ui->label->setText(Locale->getLclLanguage());
  ui->btndark->setText(Locale->getLclThemedark());
  ui->btnlight->setText(Locale->getLclThemelight());
}
