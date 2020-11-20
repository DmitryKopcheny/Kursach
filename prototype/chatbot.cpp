#include "chatbot.h"

ChatBot::ChatBot()
{
  language = "ukrainian";
  logName = QDate::currentDate().toString();
  logName.append(".txt");//logs
}
ChatBot::~ChatBot()
{

}

void ChatBot::setLang(int langCode)
{
  if (langCode == UKRAINIAN)
    {
      language = "ukrainian";
    }
  if (langCode == 1)
    {
      language = "english";
    }
}
QString ChatBot::getLang()
{
  return language;
}
