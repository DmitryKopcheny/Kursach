#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <studentam.h>
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
    void on_btn1_1_clicked();
    void on_btn1_2_clicked();
    void on_btn1_3_clicked();
    void on_btn1_4_1_clicked();
    void on_btn2_1_clicked();
    void on_btn2_2_clicked();
    void on_btn2_3_clicked();
    void on_btn2_4_clicked();
    void on_btn2_5_clicked();
    void on_btn2_6_clicked();
    void on_btn4_clicked();
    void on_LanguageChanged(int);
    void on_btn_enter_clicked();

private:
    Ui::MainWindow *ui;
    Student *studInfo;
    TextChat *Chat;
};
#endif // MAINWINDOW_H
