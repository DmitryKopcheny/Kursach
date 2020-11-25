#include "textchat.h"

TextChat::TextChat()
{
  language = "ukrainian";
  resetIterators();
  readFromXml(getLang());
  readFromCsv(getLang());
}
void TextChat::resetIterators()
{
  iteratorTime = 0;
  iteratorMessage = 0;
}
QString TextChat::getNextMessage()
{
  ++iteratorMessage;
  return messages[iteratorMessage-1];
}
QString TextChat::getNextTime()
{
  ++iteratorTime;
  return time[iteratorTime-1].time().toString();
}
bool TextChat::getIsUsersMessage()
{
  return isUsersMessage[iteratorMessage];
}
void TextChat::addNewMessage(const bool isUsers, const QString message)
{
  isUsersMessage.push_back(isUsers);
  messages.push_back(message);
  time.push_back(QDateTime::currentDateTime());
}
bool TextChat::isEnd()
{
  if (iteratorMessage < messages.size())
    {
      return false;
    }
  else
    {
      return true;
    }
}

void TextChat::setLang(const int langCode)
{
  if (langCode == UKRAINIAN)
    {
      language = "ukrainian";
    }
  if (langCode == ENGLISH)
    {
      language = "english";
    }
  if (langCode == GERMAN)
    {
      language = "german";
    }
  if (langCode == RUSSIAN)
    {
      language = "russian";
    }
  if (langCode == ARAB)
    {
      language = "arab";
    }
}
QString TextChat::getLang()
{
  return language;
}

bool TextChat::searchForTheSame(const Student &info)
{
  for (int i = 0; i<getSizeOfStud(); i++)
    {
      if (info.fullName == getFullName(i))
        {
          if (info.group == getGroup(i))
            {
              if (info.course == getCourse(i))
                {
                  return true;
                }
            }
        }
    }
  return false;
}
/*QVector<Student>**/void TextChat::sortByFullName(QVector <Student>* studVector)
{

}
QVector<Student>*  TextChat::sellectSameGroup(QVector <Student>* studVector)
{
  QVector <Student>* sameGroupVector = new QVector<Student>;
  if (studVector->size() == 0)
    {
      return sameGroupVector;
    }
  sameGroupVector->push_back(studVector->takeAt(0));
  for (int i = 0; i<studVector->size(); i++)
    {
      if ((*sameGroupVector)[0].group == (*studVector)[i].group)
        {
          sameGroupVector->push_back(studVector->takeAt(i));
        }
    }
  return sameGroupVector;
}
int TextChat::findMinCourse(QVector <Student>* studVector)
{
  if (studVector->size() == 0)
    {
      return -1;
    }
  int minCourse = (*studVector)[0].course;
  for (int i = 0; i < studVector->size(); i++)
    {
      if (minCourse > (*studVector)[i].course)
        {
          minCourse =(*studVector)[i].course;
        }
    }
  return minCourse;
}
QVector<Student>* TextChat::sellectMinCourse(QVector <Student>* studVector)
{
  QVector <Student>* minCourseVector = new QVector<Student>;
  int minCourse = findMinCourse(studVector);
  if (minCourse == -1)
    {
      return minCourseVector;
    }
  for (int i = 0; i<studVector->size(); i++)
    {
      if ((*studVector)[i].course == minCourse)
        {
          minCourseVector->push_back(studVector->takeAt(i));
        }
    }
  return minCourseVector;


}
void TextChat::sortStudents()
{
  QVector <Student> studVector;
  for (int i = 0; i < getSizeOfStud(); i++)
    {
      studVector.push_back(getStudent(i));
    }
  clearStudentAM();
  QVector<Student>* minCourse;
  QVector<Student>* sameGroup;
  while (studVector.size() != 0)
    {
      minCourse = sellectMinCourse(&studVector);
      while (minCourse->size() != 0)
        {

          sameGroup = sellectSameGroup(minCourse);
          sortByFullName(sameGroup);
          for (int i = 0; i<sameGroup->size(); i++)
            {
              addStudent((*sameGroup)[i]);
            }
        }
    }
}
