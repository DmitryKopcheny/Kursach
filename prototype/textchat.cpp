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
    return messages[iteratorMessage++];
}
QString TextChat::getNextTime()
{
    return time[iteratorTime++].time().toString();
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

void TextChat::sortStudents()
{
    QList<Student> studList;
    QList<Student>  *minCourse;
    QList<Student> *sameGroup;
    for (int i = 0; i < getSizeOfStud(); i++)
    {
        studList.push_back(getStudent(i));
    }
    clearStudentAM();
    quickSort(&studList, 0, studList.size()-1);
    while (!studList.isEmpty())
    {
        minCourse = sellectMinCourse(&studList);
        while (!minCourse->isEmpty())
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

void TextChat::quickSort(QList <Student>* studList, const int left, const int right)
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
        if ((*studList)[leftBorder].fullName.size()<(*studList)[pivot].fullName.size())
        {
            maxUnicodeLevel = (*studList)[leftBorder].fullName.size();
        }
        else
        {
            maxUnicodeLevel = (*studList)[pivot].fullName.size();
        }
        pivotUnicode = (int)(*studList)[pivot].fullName[unicodeLevel].unicode();
        leftUnicode = (int)(*studList)[leftBorder].fullName[unicodeLevel].unicode();
        if (leftUnicode == pivotUnicode && unicodeLevel < maxUnicodeLevel && !skip)
        {
            unicodeLevel++;
            continue;
        }
        if (leftUnicode < pivotUnicode || (leftUnicode == pivotUnicode && (*studList)[leftBorder].fullName.size() == maxUnicodeLevel))
        {
            leftBorder++;
            unicodeLevel = 0;
            continue;
        }
        studList->insert(pivot, studList->takeAt(leftBorder));
        pivot--;
        unicodeLevel = 0;
    }
    quickSort(studList, left, pivot-1);
    quickSort(studList, pivot+1, right);
}

int TextChat::findMinCourse(QList <Student>* studList)
{
    if (studList->size() == 0)
    {
        return -1;
    }
    int minCourse = (*studList)[0].course;
    for (int i = 0; i < studList->size(); i++)
    {
        if (minCourse > (*studList)[i].course)
        {
            minCourse =(*studList)[i].course;
        }
    }
    return minCourse;
}

QList<Student>* TextChat::sellectMinCourse(QList <Student>* studList)
{
    QList <Student>* minCourseList = new QList<Student>;
    int minCourse = findMinCourse(studList);
    if (minCourse == -1)
    {
        return minCourseList;
    }
    for (int i = 0; i<studList->size(); i++)
    {
        if ((*studList)[i].course == minCourse)
        {
            minCourseList->push_back(studList->takeAt(i));
            i--;
        }
    }
    return minCourseList;
}

QList<Student>*  TextChat::sellectSameGroup(QList <Student>* studList)
{
    QList <Student>* sameGroupList = new QList<Student>;
    if (studList->size() == 0)
    {
        return sameGroupList;
    }
    sameGroupList->push_back(studList->takeAt(0));
    for (int i = 0; i<studList->size(); i++)
    {
        if ((*sameGroupList)[0].group == (*studList)[i].group)
        {
            sameGroupList->push_back(studList->takeAt(i));
            i--;
        }
    }
    return sameGroupList;
}
