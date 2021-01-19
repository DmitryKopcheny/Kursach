#ifndef MANUAL_H
#define MANUAL_H

#include <QMainWindow>

namespace Ui {
class manual;
}
class Localization;
class manual : public QMainWindow
{
    Q_OBJECT

public:
    explicit manual(Localization *Locale, QWidget *parent = nullptr);
    ~manual();
private slots:
    void on_localizateWindows();
private:
    Ui::manual *ui;
    Localization *Locale;
};

#endif // MANUAL_H
