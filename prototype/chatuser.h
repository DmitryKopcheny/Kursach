#ifndef CHATUSER_H
#define CHATUSER_H
#include "basic_bot.h"
#include "studentam.h"

class ChatUser : public basic_user
{
public:
  ChatUser();
  ~ChatUser();
  void setLang(QString);
};

#endif // CHATUSER_H
