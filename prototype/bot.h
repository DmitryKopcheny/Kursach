#ifndef BOT_H
#define BOT_H
#include <QDate>
#include "basic_user.h"

class bot : public basic_user
{
protected:
  void addToLog();
public:
  bot();
  ~bot();
  void send();
  void setLang();
  QString getLogName();

};

#endif // BOT_H
