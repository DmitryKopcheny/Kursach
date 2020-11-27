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
  int langCode;
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
  int getLangCode();

  bool searchForTheSame(const Student &info);

  void quickSort(QVector <Student>* studVector, int left, int right);
  int findMinCourse(QVector <Student>* studVector);
  //void sortByFullName(QVector <Student>* studVector);
  QVector<Student>*  sellectSameGroup(QVector <Student>* studVector);
  QVector<Student>* sellectMinCourse(QVector <Student>* studVector);
  void sortStudents();
};

#endif // TEXTCHAT_H
