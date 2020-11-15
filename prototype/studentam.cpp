#include "studentam.h"

StudentAM::StudentAM()
{

}
StudentAM::~StudentAM()
{

}
void StudentAM::addStudent(const Student& student)
{
    studentList.append(student);
}

QString StudentAM::getFullName(int index) const
{
    return studentList.at(index).fullName;
}

int StudentAM::getCourse(int index) const
{
    return studentList.at(index).course;
}

QString StudentAM::getGroup(int index) const
{
    return studentList.at(index).group;
}

QString StudentAM::getphoneNumber(int index) const
{
    return studentList.at(index).phoneNumber;
}

const Student &StudentAM::getStudent(int index) const
{
    return studentList.at(index);
}

int StudentAM::getSize() const
{
    return studentList.size();
}

void StudentAM::deleteAt(int index)
{
    studentList.removeAt(index);
}

void StudentAM::writeToXml()
{
    QDomDocument doc("AcademicMobility");
    QDomElement mainDomElement = doc.createElement("studentsAM");
    doc.appendChild(mainDomElement);
    for(int i = 0; i < studentList.size(); i++)
    {
        mainDomElement.appendChild(formDomElementNode(doc, studentList.at(i)));
    }

    QFile xmlFile("studentsAM.xml");
    if(xmlFile.open(QIODevice::WriteOnly))
        QTextStream(&xmlFile) << doc.toString();
    xmlFile.close();
}

QDomElement StudentAM::formDomElementNode(QDomDocument &domDoc, const Student& student)
{
    QDomElement studentNode = domDoc.createElement("student");

    QDomElement studentName = domDoc.createElement("Name");
    QDomText studentNameValue = domDoc.createTextNode(student.fullName);
    studentName.appendChild(studentNameValue);

    QDomElement studentGroup = domDoc.createElement("Group");
    QDomText studentGroupText = domDoc.createTextNode(student.group);
    studentGroup.appendChild(studentGroupText);

    QDomElement studentCourse = domDoc.createElement("Course");
    QDomText studentCourseText = domDoc.createTextNode(QString::number(student.course));
    studentCourse.appendChild(studentCourseText);

    QDomElement studentPhnNum = domDoc.createElement("PhoneNumber");
    QDomText studentPhnNumText = domDoc.createTextNode(student.phoneNumber);
    studentPhnNum.appendChild(studentPhnNumText);

    studentNode.appendChild(studentName);
    studentNode.appendChild(studentGroup);
    studentNode.appendChild(studentCourse);
    studentNode.appendChild(studentPhnNum);

    return studentNode;
}
