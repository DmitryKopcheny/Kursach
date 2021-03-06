#ifndef STUDENPTAM_H
#define STUDENTAM_H

#include <QtXml/QtXml>
#include <QList>

struct Student
{
    QString fullName;
    QString group;
    int course;
    QString phoneNumber;
    Student();
    bool isComplete();
};

class StudentAM
{
public:
    StudentAM();
    ~StudentAM();
    void addStudent(const Student& student);
    void deleteAt(int index);
    QString getFullName(int index) const;
    int getCourse(int index) const;
    QString getGroup(int index) const;
    QString getPhoneNumber(int index) const;
    const Student& getStudent(int index) const;
    int getSizeOfStud() const;
    void clearStudentAM();

    void writeToXml();
private:
    QList<Student> studentList;
    QDomElement formDomElementNode(QDomDocument &domDoc, const Student& student);
};

#endif // STUDENTAM_H
