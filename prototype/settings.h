#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include <QFile>
namespace Ui {
class settings;
}
class Localization;
class settings : public QMainWindow
{
    Q_OBJECT

public:
    explicit settings(Localization *Locale, QWidget *parent = nullptr);
    ~settings();
signals:
    void LanguageChanged();
private slots:
    void on_btnlight_clicked();
    void on_btndark_clicked();

    void on_comboBox_currentIndexChanged(int index);
    void on_localizateWindows();

private:
    Ui::settings *ui;
    Localization *Locale;
    QFile styleF;
};

#endif // SETTINGS_H
