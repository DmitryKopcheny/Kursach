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

private:
    Ui::bug *ui;
};
//test
#endif // BUG_H
