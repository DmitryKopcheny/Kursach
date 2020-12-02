#include "exception.h"
#include "QMessageBox"
#include "QString"

FileException::FileException(QString error)
{
    this->error = "Error opening file:  ";
    this->error += error;
}

FileException::~FileException()
{
    error = "";
}

void FileException::what() {
    QMessageBox msg;
    msg.setWindowTitle("Error information");
    msg.setText(error);
    msg.exec();
}

RegisterException::RegisterException()
{
    this->error = "Ви не ввели дані";
}

RegisterException::RegisterException(QString error)
{
    this->error = error;
}

RegisterException::~RegisterException()
{
    error = "";
}

void RegisterException::what() {
    QMessageBox msg;
    msg.setWindowTitle("Error information");
    msg.setText(error);
    msg.exec();
    exit(0);//завершение приложения при отсутсувии файла
}

