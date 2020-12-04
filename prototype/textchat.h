#ifndef TEXTCHAT_H
#define TEXTCHAT_H
#include <QDateTime>
#include <QList>
#include <QString>
#include "universityam.h"
#include "generalinfo.h"
#include "studentam.h"



class TextChat : public UniversityAM, public GeneralInfo, public StudentAM
{
  QList<QDateTime> time;
  QList<QString> messages;
  QList<bool> isUsersMessage;
  int iteratorTime;
  int iteratorMessage;

public:
  TextChat(const QString language);
  void addNewMessage(const bool isUsers, const QString message);
  void resetIterators();
  QString getNextMessage();
  QString getNextTime();
  bool getIsUsersMessage();
  bool isEnd();



  bool searchForTheSame(const Student &info);

  void quickSort(QList <Student>* studList, int left, int right);
  int findMinCourse(QList <Student>* studList);
  QList<Student>*  sellectSameGroup(QList <Student>* studList);
  QList<Student>* sellectMinCourse(QList <Student>* studList);
  void sortStudents();
};

#endif // TEXTCHAT_H
