#include "universityam.h"
#include "exception.h"

UniversityAM::UniversityAM()
{

}

const University& UniversityAM::getUniversity(int index)
{
    return universityList.at(index);
}

QString UniversityAM::getUnName(int index) const
{
    return universityList.at(index).univName;
}

QString UniversityAM::getMainInfo(int index) const
{
    return universityList.at(index).mainInfo;
}

int UniversityAM::getSizeOfUniv() const
{
    return universityList.size();
}

void UniversityAM::readFromXml(const QString language)
{
    universityList.clear();
    QDomDocument domDoc;
    QFile file("universitiesAM.xml");
    try {
            file.open(QIODevice::ReadOnly);
            if(!file.isOpen())
                {
                    throw FileException("universitiesAM.xml");
                }
        }

    catch(FileException& ex)
        {
            ex.what();
        }

    if(file.exists())
    {
        if(domDoc.setContent(&file))
        {
            QDomElement root = domDoc.documentElement();
            QDomNode langNode = root.firstChild();

            while(!langNode.isNull())
            {
                if(langNode.toElement().attribute("lang","") == language)//настройка языка
                {
                    QDomNode univXml = langNode.firstChild();
                    while(!univXml.isNull())
                    {
                        universityList.append(formUnivFromXml(univXml));
                        univXml = univXml.nextSibling();
                    }
                    break;
                }
                langNode = langNode.nextSibling();
            }

        }
        file.close();
    }
}

University &UniversityAM::formUnivFromXml(const QDomNode& univXml)
{
    University *temp = new University;
    QDomElement univElement = univXml.toElement();
    QDomNode traverseNode = univXml.firstChild();
        if(univElement.tagName() == "university")
        {

                QDomElement univName = traverseNode.toElement();

                temp->univName = univName.text();

                traverseNode = traverseNode.nextSibling();

                QDomElement univMainInfo = traverseNode.toElement();

                temp->mainInfo = univMainInfo.text();

        }

            return *temp;
}


QString University::getName()
{  
        return univName;
}

QString University::getMainInfo()
{
        return mainInfo;
}
