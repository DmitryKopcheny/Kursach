#ifndef UNIVERSITYAM_H
#define UNIVERSITYAM_H

#include <QtXml/QtXml>
#include <QList>

struct University
{
    QString univName;
    QString mainInfo;
    QString getName();
    QString getMainInfo();

};

class UniversityAM
{
public:
    UniversityAM();
    const University& getUniversity(int index);
    QString getUnName(int index) const;
    QString getMainInfo(int index) const;
    int getSizeOfUniv() const;

    void readFromXml(QString language);

private:
    QList<University> universityList;
    University& formUnivFromXml(const QDomNode& node);

};

#endif // UNIVERSITYAM_H
