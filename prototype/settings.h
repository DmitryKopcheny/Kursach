#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>

namespace Ui {
class settings;
}

class settings : public QMainWindow
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);
    ~settings();

private slots:
    void on_btnlight_clicked();

    void on_btndark_clicked();

private:
    Ui::settings *ui;
};

#endif // SETTINGS_H
