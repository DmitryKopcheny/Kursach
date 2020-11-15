#include "textchat.h"

TextChat::TextChat()
{
  iteratorTime = 0;
  iteratorMessage = 0;
}
void TextChat::resetIterators()
{
  iteratorTime = 0;
  iteratorMessage = 0;
}
QString TextChat::getNextMessage()
{
  iteratorMessage++;
  return messages[iteratorMessage];
}
QString TextChat::getNextTime()
{
  iteratorTime++;
  return time[iteratorTime].toString();
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
