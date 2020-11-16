#ifndef BASIC_BOT_H
#define BASIC_BOT_H
#include <QString>

class basic_bot
{
public:
  QString userName;
  QString message;
  QString lang;
  QString logName;
  //virtual void addToLog() = 0;
  //basic_bot(){}
  //~basic_bot(){}
  //virtual void send() = 0;
  virtual void setLang(QString)=0;


};

#endif // BASIC_BOT_H
