#include "textchat.h"

TextChat::TextChat()
{
  language = "ukrainian";
  resetIterators();
  readFromXml(getLang());
  readFromCsv(getLang());
}
void TextChat::resetIterators()
{
  iteratorTime = 0;
  iteratorMessage = 0;
}
QString TextChat::getNextMessage()
{
  ++iteratorMessage;
  return messages[iteratorMessage-1];
}
QString TextChat::getNextTime()
{
  ++iteratorTime;
  return time[iteratorTime-1].time().toString();
}
bool TextChat::getIsUsersMessage()
{
  return isUsersMessage[iteratorMessage];
}
void TextChat::addNewMessage(bool isUsers, QString message)
{
  isUsersMessage.push_back(isUsers);
  messages.push_back(message);
  time.push_back(QDateTime::currentDateTime());
}
bool TextChat::isEnd()
{
  if (iteratorMessage < messages.size())
    {
      return false;
    }
  else
    {
      return true;
    }
}

void TextChat::setLang(int langCode)
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
QString TextChat::getLang()
{
  return language;
}
