#include "textchat.h"

TextChat::TextChat(const QString language)
{
  resetIterators();
  readFromXml(language);
  readFromCsv(language);
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

void TextChat::quickSort(QVector <Student>* studVector, int left, int right)
{
  if (right - left <= 0)
    {
      return;
    }
  int pivot = right;
  int leftBorder = left;
  int pivotUnicode;
  int leftUnicode;
  int unicodeLevel = 0;
  int maxUnicodeLevel;
  bool skip = false;
  while (leftBorder < pivot)
    {
      skip = false;
      if (leftBorder == pivot)
        {
          skip = true;
        }
      if ((*studVector)[leftBorder].fullName.size()<(*studVector)[pivot].fullName.size())
        {
          maxUnicodeLevel = (*studVector)[leftBorder].fullName.size();
        }
      else
        {
          maxUnicodeLevel = (*studVector)[pivot].fullName.size();
        }
      pivotUnicode = (int)(*studVector)[pivot].fullName[unicodeLevel].unicode();
      leftUnicode = (int)(*studVector)[leftBorder].fullName[unicodeLevel].unicode();
      if (leftUnicode == pivotUnicode && unicodeLevel < maxUnicodeLevel && !skip)
        {
          unicodeLevel++;
          continue;
        }
      if (leftUnicode < pivotUnicode || (leftUnicode == pivotUnicode && (*studVector)[leftBorder].fullName.size() == maxUnicodeLevel))
        {
          leftBorder++;
          unicodeLevel = 0;
          continue;
        }
      studVector->insert(pivot, studVector->takeAt(leftBorder));
      pivot--;
      unicodeLevel = 0;
    }
    quickSort(studVector, left, pivot-1);
    quickSort(studVector, pivot+1, right);
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
          i--;
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
          i--;
        }
    }
  return minCourseVector;
}

void TextChat::sortStudents()
{
  QVector<Student> studVector;
  QVector<Student>  *minCourse;
  QVector<Student> *sameGroup;
  for (int i = 0; i < getSizeOfStud(); i++)
    {
      studVector.push_back(getStudent(i));
    }
  clearStudentAM();
  quickSort(&studVector, 0, studVector.size()-1);
  while (studVector.size() != 0)
    {
      minCourse = sellectMinCourse(&studVector);
      while (minCourse->size() != 0)
        {

          sameGroup = sellectSameGroup(minCourse);
          for (int i = 0; i<sameGroup->size(); i++)
            {
              addStudent((*sameGroup)[i]);
            }
          delete sameGroup;
        }
      delete minCourse;
    }
}
