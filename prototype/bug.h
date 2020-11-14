#ifndef BUG_H
#define BUG_H

#include <QMainWindow>

namespace Ui {
class bug;
}

class bug : public QMainWindow
{
    Q_OBJECT

public:
    explicit bug(QWidget *parent = nullptr);
    ~bug();

private:
    Ui::bug *ui;
};
//test
#endif // BUG_H
