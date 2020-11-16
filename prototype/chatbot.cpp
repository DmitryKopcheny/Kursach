#include "chatbot.h"

ChatBot::ChatBot()
{
  userName = "BOT";
  lang = UKRAINIAN;
  logName = QDate::currentDate().toString();
  logName.append(".txt");//logs
}
ChatBot::~ChatBot()
{

}

void ChatBot::setLang(int langCode)
{
  lang = langCode;
}
