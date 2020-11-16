#ifndef BASIC_BOT_H
#define BASIC_BOT_H
#include <QString>
enum langeages{UKRAINIAN, ENGLISH, DEUTSCH, RUSSIAN, ARAB};
class basic_bot
{
public:
  //QString userName;
  //QString message;
  QString language;
  QString logName;
  //virtual void addToLog() = 0;
  //basic_bot(){}
  //~basic_bot(){}
  //virtual void send() = 0;
  virtual void setLang(int)=0;
  virtual QString getLang()=0;


};

#endif // BASIC_BOT_H
