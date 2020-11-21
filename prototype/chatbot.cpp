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
  if (langCode == ENGLISH)
    {
      language = "english";
    }
  if (langCode == GERMAN)
    {
      language = "german";
    }
  if (langCode == RUSSIAN)
    {
      language = "russian";
    }
  if (langCode == ARAB)
    {
      language = "arab";
    }
}
QString ChatBot::getLang()
{
  return language;
}
