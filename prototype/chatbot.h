#ifndef CHATBOT_H
#define CHATBOT_H
#include <QDate>
#include "basic_user.h"
#include "universityam.h"
#include "generalinfo.h"
class ChatBot : public basic_user, public UniversityAM, public GeneralInfo
{

public:
  ChatBot();
  ~ChatBot();
  //void addToLog();
  void setLang(QString);
  QString getLogName();

};

#endif // CHATBOT_H
