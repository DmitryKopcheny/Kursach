#include "bot.h"

bot::bot()
{
  userName = "BOT";
  lang = "ua";
  logName = QDate::currentDate().toString();
  logName.append(".txt");//logs
}
bot::~bot()
{

}
void bot::send()
{

}
void bot::setLang(const QString langCode)
{
  lang = langCode;
}
void bot::addToLog()
{

}
QString bot::getLogName()
{
  return logName;
}
