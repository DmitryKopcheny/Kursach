#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "exception"
#include "QString"


using namespace std;


class Exception: public exception
{
public:
    Exception() {}
    virtual ~Exception() {}
    virtual void what() {}
};

class FileException : public Exception
{
public:
    FileException(QString error);
    ~FileException();
    void what() override;
private:
    QString error;
};

class RegisterException : public Exception
{
public:
    RegisterException();
    RegisterException(QString error);
    ~RegisterException();
    void what() override;
private:
    QString error;
};



#endif // EXCEPTION_H
