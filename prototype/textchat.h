#ifndef TEXTCHAT_H
#define TEXTCHAT_H
#include <QDateTime>
#include <QList>
#include <QString>
#include "chatbot.h"
#include "chatuser.h"
/*class ChatBot;
class ChatUser;*/
class TextChat : public ChatBot, public ChatUser
{
  QList<QDateTime> time;
  QList<QString> messages;
  QList<bool> isUsersMessage;
  int iteratorTime;
  int iteratorMessage;
  ChatBot Bot;
  ChatUser User;
public:
  TextChat();
  void addNewMessage(bool isUsers, QString message);
  //void sendMessage(QString code);
  void resetIterators();
  QString getNextMessage();
  QString getNextTime();
  bool getIsUsersMessage();
  bool isEnd();
};

#endif // TEXTCHAT_H
