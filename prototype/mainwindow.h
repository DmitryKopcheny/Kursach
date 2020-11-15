#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class TextChat;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void displayChat();
    ~MainWindow();

private slots:
    void on_action_3_triggered();
    void on_action_2_triggered();
    void on_action_4_triggered();
    void on_action_triggered();
    void on_action_5_triggered();

    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn1_4_clicked();

    void on_btn1_back_clicked();
    void on_btn2_back_clicked();
    void on_btn1_4_back_clicked();


private:
    Ui::MainWindow *ui;
    TextChat *Chat;
};
#endif // MAINWINDOW_H
