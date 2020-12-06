#ifndef BUG_H
#define BUG_H

#include <QMainWindow>

namespace Ui {
class bug;
}
class Localization;
class bug : public QMainWindow
{
    Q_OBJECT

public:
    explicit bug(Localization *Locale, QWidget *parent = nullptr);
    ~bug();

private slots:
    void on_btn_Send_clicked();
    void on_localizateWindows();

private:
    Ui::bug *ui;
    Localization *Locale;
};
//test
#endif // BUG_H
