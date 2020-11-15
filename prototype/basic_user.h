#ifndef BASIC_USER_H
#define BASIC_USER_H
#include <QString>

class basic_user
{
public:
  QString userName;
  QString message;
  QString lang;
  QString logName;
  //virtual void addToLog() = 0;
  basic_user(){}
  ~basic_user(){}
  //virtual void send() = 0;
  //virtual void setLang() = 0;


};

#endif // BASIC_USER_H
