#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <QMainWindow>

namespace Ui {
class developer;
}
class Localization;
class developer : public QMainWindow
{
    Q_OBJECT

public:
    explicit developer(Localization *Locale, QWidget *parent = nullptr);
    ~developer();

private slots:
    void on_localizateWindows();

private:
    Ui::developer *ui;
    Localization *Locale;
};

#endif // DEVELOPER_H
