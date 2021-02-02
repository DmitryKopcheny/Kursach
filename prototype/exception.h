#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "QString"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

using namespace std;


class Exception
{
public:
    Exception();
    virtual ~Exception();
    void what();
protected:
    QString error;
};

class FileException : public Exception
{
public:
    FileException(QString error);
    ~FileException() override;
};

class EmptyFileException : public Exception
{
public:
    EmptyFileException(QString error);
    ~EmptyFileException() override;    
};

class  ReadingDataException : public Exception
{
public:
    ReadingDataException(QString error);
    QString what();
};

class RegisterException : public Exception
{
public:
    RegisterException(int error);
};


class Validate
{
public:
    bool validates(QString str, QString regexp);
};

class FormException : public Exception
{
public:
    FormException(int error);
};
#endif // EXCEPTION_H
