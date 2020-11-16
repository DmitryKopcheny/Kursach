#ifndef TEXTCHAT_H
#define TEXTCHAT_H
#include <QDateTime>
#include <QList>
#include <QString>
#include "chatbot.h"

class TextChat : public ChatBot
{
  QList<QDateTime> time;
  QList<QString> messages;
  QList<bool> isUsersMessage;
  int iteratorTime;
  int iteratorMessage;
  ChatBot Bot;
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
