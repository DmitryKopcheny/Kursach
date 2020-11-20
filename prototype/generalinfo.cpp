#include "generalinfo.h"

GeneralInfo::GeneralInfo()
{

}

QString GeneralInfo::getAboutAM()
{
    return this->aboutAM;
}

QString GeneralInfo::getForWhom()
{
    return this->forWhom;
}

QString GeneralInfo::getPayments()
{
    return this->Payments;
}

QString GeneralInfo::getRequiredLang()
{
    return this->requiredLanguage;
}

QString GeneralInfo::getWhereToStart()
{
    return this->whereToStart;
}

QString GeneralInfo::getContacts()
{
    return this->Contacts;
}

void GeneralInfo::readFromCsv(const QString language)
{
    QFile file("buttonsCSV.csv");
    file.open(QIODevice::ReadOnly); //для Влада

    QStringList wordList;
    while(!file.atEnd())
    {
        QByteArray langLine = file.readLine();
        if(language == langLine.split(';').at(0)) //проверка первого елем, отделенного ';' на соот языку
        {
                this->aboutAM = langLine.split(';').at(1);
                this->forWhom = langLine.split(';').at(2);
                this->Payments = langLine.split(';').at(3);
                this->requiredLanguage= langLine.split(';').at(4);
                this->whereToStart = langLine.split(';').at(5);
                this->Contacts = langLine.split(';').at(6);
                break;
        }
    }
}
