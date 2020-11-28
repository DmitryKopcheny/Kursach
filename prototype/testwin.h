#ifndef TESTWIN_H
#define TESTWIN_H

#include <QDialog>

namespace Ui {
class testwin;
}

class testwin : public QDialog
{
    Q_OBJECT

public:
    explicit testwin(QWidget *parent = nullptr);
    ~testwin();

private:
    Ui::testwin *ui;
};

#endif // TESTWIN_H
