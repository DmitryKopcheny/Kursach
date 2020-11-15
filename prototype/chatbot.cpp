#include "chatbot.h"

ChatBot::ChatBot()
{
  userName = "BOT";
  lang = "ua";
  logName = QDate::currentDate().toString();
  logName.append(".txt");//logs
}
ChatBot::~ChatBot()
{

}

void ChatBot::setLang(const QString langCode)
{
  lang = langCode;
}

QString ChatBot::getLogName()
{
  return logName;
}
