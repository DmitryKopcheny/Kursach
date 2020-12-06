#include "exception.h"
#include "QMessageBox"
#include "QString"

void Exception::what()
{

}

FileException::FileException(QString error)
{
    this->error = "Error opening file:  ";
    this->error += error;
}

void FileException::what() {
    QMessageBox msg;
    msg.setWindowTitle("Error information");
    msg.setText(error);
    msg.exec();
}

FileException::~FileException()
{
    exit(0);
}

EmptyFileException::EmptyFileException(QString error)
{
    this->error = "File is empty or it doesn't have enough data to run:  ";
    this->error += error;
}

void EmptyFileException::what() {
    QMessageBox msg;
    msg.setWindowTitle("Error information");
    msg.setText(error);
    msg.exec();
}

EmptyFileException::~EmptyFileException()
{
    exit(0);
}

ReadingDataException::ReadingDataException(QString error)
{
    this->error = "Error the required data is empty, from file:  ";
    this->error += error;
}

void ReadingDataException::what() {
    QMessageBox msg;
    msg.setWindowTitle("Error information");
    msg.setText(error);
    msg.exec();
}

ReadingDataException::~ReadingDataException()
{
    exit(0);
}

RegisterException::RegisterException(int error)
{
    this->error = "You did not enter the data, or you entered it incorrectly. Correctly entered data are as follows: ";
    switch (error)
    {
    case 1:
        this->error += "Last name First name Middle name";
        break;
    case 2:
        this->error += "KNT-229";
        break;
    case 3:
        this->error += "number from 2 to 6";
        break;
    case 4:
        this->error += "+38(056)1234567";
    }
}

void RegisterException::what()
{
    QMessageBox msg;
    msg.setWindowTitle("Error information");
    msg.setText(error);
    msg.exec();
}

RegisterException::~RegisterException()
{
    error = "";
}


bool Validate::validates(QString str, QString regexp)
{
    QRegExp rx;
    QRegExpValidator valid;
    rx.setPattern(regexp);
    valid.setRegExp(rx);
    int pos = 0;
    if (valid.validate(str, pos) == QValidator::Acceptable)
    {
        return true;
    }
    else
    {
        return false;
    }
}

