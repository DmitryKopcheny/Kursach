#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "exception"
#include "QString"
#include <QRegExp>
#include <QRegExpValidator>

using namespace std;


class Exception: public exception
{
public:
    Exception() {}
    virtual ~Exception() {}
    virtual void what();
};

class FileException : public Exception
{
public:
    FileException(QString error);
    ~FileException() override;
    void what() override;
private:
    QString error;
};

class EmptyFileException : public Exception
{
public:
    EmptyFileException(QString error);
    ~EmptyFileException() override;
    void what() override;
private:
    QString error;
};

class  ReadingDataException : public Exception
{
public:
    ReadingDataException(QString error);
    ~ReadingDataException() override;
    void what() override;
private:
    QString error;
};

class RegisterException : public Exception
{
public:
    RegisterException(int error);
    ~RegisterException() override;
    void what() override;
private:
    QString error;
};


class Validate
{
public:
    Validate() {}
    ~Validate() {}
    bool validates(QString str, QString regexp);
};


#endif // EXCEPTION_H
