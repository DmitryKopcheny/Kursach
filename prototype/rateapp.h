#ifndef RATEAPP_H
#define RATEAPP_H

#include <QMainWindow>

namespace Ui {
class rateApp;
}
class Localization;
class rateApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit rateApp(Localization *Locale, QWidget *parent = nullptr);
    ~rateApp();

signals:
    void FeedbackSent(int feedback);
private slots:
    void on_rate1_clicked();

    void on_rate2_clicked();

    void on_rate3_clicked();

    void on_rate4_clicked();

    void on_rate5_clicked();
    void on_localizateWindows();
    void on_btn_Send_clicked();

private:
    Ui::rateApp *ui;
    Localization *Locale;
    int feedback;
};

#endif // RATEAPP_H
