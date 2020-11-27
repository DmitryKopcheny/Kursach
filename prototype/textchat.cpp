#include "textchat.h"

TextChat::TextChat()
{
  langCode = UKRAINIAN;
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
  this->langCode = langCode;
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
  else
    {
      this->langCode = UKRAINIAN;
      language = "ukrainian";
    }
}
QString TextChat::getLang()
{
  return language;
}

int TextChat::getLangCode()
{
  return langCode;
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
  if (right - left == 0)
    {
      return;
    }
  int middle = (left + right)/2;
  int leftBorder = left;
  int rightBorder = right;
  int middleUnicode;
  int leftUnicode;
  int rightUnicode;
  int leftUnicodeLevel = 0;
  int rightUnicodeLevel = 0;
  int maxMiddleUnicodeLevel;
  int maxUnicodeLevel;
  bool skipRight;
  bool skipLeft;
  while (leftBorder < rightBorder)
    {
      skipRight = false;
      skipLeft = false;
      if (rightBorder == middle)
        {
          skipRight = true;
        }
      if (leftBorder == middle)
        {
          skipLeft = true;
        }
      if ((*studVector)[leftBorder].fullName.size()<(*studVector)[rightBorder].fullName.size())
        {
          maxUnicodeLevel = (*studVector)[leftBorder].fullName.size();
        }
      else
        {
          maxUnicodeLevel = (*studVector)[rightBorder].fullName.size();
        }
      maxMiddleUnicodeLevel  = (*studVector)[middle].fullName.size();
      if (maxUnicodeLevel > maxMiddleUnicodeLevel)
        {
          maxUnicodeLevel = maxMiddleUnicodeLevel;
        }
      middleUnicode = (int)(*studVector)[middle].fullName[leftUnicodeLevel].unicode();
      leftUnicode = (int)(*studVector)[leftBorder].fullName[leftUnicodeLevel].unicode();
      if (leftUnicode == middleUnicode && leftUnicodeLevel < maxUnicodeLevel && !skipLeft)
        {
          leftUnicodeLevel++;
          continue;
        }
      rightUnicode  = (int)(*studVector)[rightBorder].fullName[rightUnicodeLevel].unicode();
      middleUnicode = (int)(*studVector)[middle].fullName[rightUnicodeLevel].unicode();
      if (rightUnicode == middleUnicode && rightUnicodeLevel < maxUnicodeLevel && !skipRight)
        {
          rightUnicodeLevel++;
          continue;
        }

      if ((leftUnicode < middleUnicode) && !skipLeft)
        {
          leftBorder++;
          leftUnicodeLevel = 0;
          continue;
        }
      else
        {
          Student studTmp = (*studVector)[leftBorder];
          (*studVector)[leftBorder] = (*studVector)[middle];
          (*studVector)[middle] = studTmp;
          leftUnicodeLevel = 0;
        }

      if ((rightUnicode > middleUnicode) && !skipRight)
        {
          rightBorder--;
          rightUnicodeLevel = 0;
          continue;
        }
      else
        {
          Student studTmp = (*studVector)[rightBorder];
          (*studVector)[rightBorder] = (*studVector)[middle];
          (*studVector)[middle] = studTmp;
          rightUnicodeLevel = 0;
        }
    }
  quickSort(studVector, left, middle);
  quickSort(studVector, middle+1, right);
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
  QVector <Student> *studVector = new QVector <Student> ;
  for (int i = 0; i < getSizeOfStud(); i++)
    {
      studVector->push_back(getStudent(i));
    }
  clearStudentAM();
  quickSort(studVector, 0, studVector->size()-1);
  QVector<Student>* minCourse = new QVector<Student>;
  QVector<Student>* sameGroup = new QVector<Student>;
  while (studVector->size() != 0)
    {
      minCourse = sellectMinCourse(studVector);
      while (minCourse->size() != 0)
        {

          sameGroup = sellectSameGroup(minCourse);
          //quickSort(sameGroup, 0, sameGroup->size()-1);
          for (int i = 0; i<sameGroup->size(); i++)
            {
              addStudent((*sameGroup)[i]);
            }
        }
    }
}
