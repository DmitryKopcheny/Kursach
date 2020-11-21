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
