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
QVector<Student>* TextChat::sortByFullName(QVector <Student>* studVector)
{

}
QVector<Student>*  TextChat::sellectSameGroup(QVector <Student>* studVector)
{

}
int TextChat::findMinCourse(QVector <Student>* studVector)
{
  if (studVector->size == 0)
    {
      return -1;
    }
  int minCourse = (*studVector)[0].course;
  for (int i = 0; i < studVector->size(); i++)
    {
      if (minCourse < (*studVector))
    }
}
QVector<Student>* TextChat::sellectMinCourse(QVector <Student>* studVector)
{
  QVector <Student>* minCourse = new QVector<Student>;
  if (studVector->size == 0)
    {
      return minCourse;
    }


}
void TextChat::sortStudents()
{
  /*const Student& getStudent(int index) const;
    int getSizeOfStud() const;*/
  QVector <Student> studVector;
  for (int i = 0; i < getSizeOfStud(); i++)
    {
      \studVector.push_back(getStudent(i));
    }

}
