#include "exception.h"
#include "QMessageBox"
#include "QString"

void Exception::what()
{
    QMessageBox msg;
    msg.setWindowTitle("Error information");
    msg.setText(error);
    msg.exec();
}

Exception::Exception()
{

}

Exception::~Exception()
{
 error = "";
}

FileException::FileException(QString Error)
{
    error = "Error opening file:  ";
    error += Error;
}

FileException::~FileException()
{
    exit(0);
}

EmptyFileException::EmptyFileException(QString Error)
{
   error = "File is empty or it doesn't have enough data to run:  ";
   error += Error;
}

EmptyFileException::~EmptyFileException()
{
    exit(0);
}

ReadingDataException::ReadingDataException(QString Error)
{
    error = "Error the required data is empty, from file:  ";
    error += Error;
}

QString ReadingDataException::what() {
    QMessageBox msg;
    msg.setWindowTitle("Error information");
    msg.setText(error);
    msg.exec();
    error = "No data available";
    return error;
}

RegisterException::RegisterException(int Error)
{
    error = "You did not enter the data, or you entered it incorrectly. Correctly entered data are as follows: ";
    switch (Error)
    {
    case 1:
        error += "Last name First name Middle name";
        break;
    case 2:
        error += "KNT-229";
        break;
    case 3:
        error += "number from 2 to 6";
        break;
    case 4:
        error += "+38(056)1234567";
    }
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

FormException::FormException(int Error)
{
  switch (Error)
  {
  case 1:
      error = "Please rate before leaving, this is important for us. Thank you!";
      break;
  case 2:
      error = "Before sending your message, please fill in the field";
  }
}
