#ifndef TEXTCHAT_H
#define TEXTCHAT_H
#include <QDateTime>
#include <QList>
#include <QString>
#include "universityam.h"
#include "generalinfo.h"
#include "studentam.h"

enum langeages{UKRAINIAN, ENGLISH, GERMAN, RUSSIAN, ARAB};

class TextChat : public UniversityAM, public GeneralInfo, public StudentAM
{
  QList<QDateTime> time;
  QList<QString> messages;
  QList<bool> isUsersMessage;
  int iteratorTime;
  int iteratorMessage;
  QString language;
public:
  TextChat();
  void addNewMessage(bool isUsers, QString message);
  void resetIterators();
  QString getNextMessage();
  QString getNextTime();
  bool getIsUsersMessage();
  bool isEnd();
  void setLang(int);
  QString getLang();
};

#endif // TEXTCHAT_H
