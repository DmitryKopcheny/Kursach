#ifndef TEXTCHAT_H
#define TEXTCHAT_H
#include <QDateTime>
#include <QList>
#include <QString>

class ChatBot;
class ChatUser;
class TextChat
{
  QList<QDateTime> time;
  QList<QString> messages;
  QList<bool> isUsersMessage;
  int iteratorTime;
  int iteratorMessage;
  ChatBot *Bot;
  ChatUser *User;
public:
  TextChat();
  void addNewMessage(bool isUsers, QString message);
  void resetIterators();
  QString getNextMessage();
  QString getNextTime();
  bool getIsUsersMessage();
};

#endif // TEXTCHAT_H
