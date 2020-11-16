#ifndef CHATBOT_H
#define CHATBOT_H
#include <QDate>
#include "basic_bot.h"
#include "universityam.h"
#include "generalinfo.h"
#include "studentam.h"
class ChatBot : public basic_bot, public UniversityAM, public GeneralInfo, public StudentAM
{

public:
  ChatBot();
  ~ChatBot();
  void setLang(int);
  QString getLang();
};

#endif // CHATBOT_H
