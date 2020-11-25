#ifndef TEXTCHAT_H
#define TEXTCHAT_H
#include <QDateTime>
#include <QList>
#include <QString>
#include <QVector>
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
  void addNewMessage(const bool isUsers, const QString message);
  void resetIterators();
  QString getNextMessage();
  QString getNextTime();
  bool getIsUsersMessage();
  bool isEnd();

  void setLang(const int langCode);
  QString getLang();

  bool searchForTheSame(const Student &info);

  QVector<Student>* TextChat::sortByFullName(QVector <Student>* studVector);
  QVector<Student>*  TextChat::sellectSameGroup(QVector <Student>* studVector);
  QVector<Student>* TextChat::sellectMinCourse(QVector <Student>* studVector);
  void sortStudents();
};

#endif // TEXTCHAT_H
