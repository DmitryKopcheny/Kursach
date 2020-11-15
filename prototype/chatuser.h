#ifndef CHATUSER_H
#define CHATUSER_H
#include "basic_user.h"
#include "studentam.h"

class ChatUser : public basic_user, public StudentAM
{
public:
  ChatUser();
  ~ChatUser();
};

#endif // CHATUSER_H
