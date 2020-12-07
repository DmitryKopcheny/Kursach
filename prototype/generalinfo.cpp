#include "generalinfo.h"
#include "exception.h"

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

QString GeneralInfo::getStatementOfPurpose()
{
    return this->SOP;
}

void GeneralInfo::writeToTxtFile()
{
    QFile file("FILENAME.txt");
    file.open(QFile::Append);
    file.write(this->feedBackOrBug.toUtf8());
    file.write("\n");
    file.close();
}

void GeneralInfo::readFromCsv(const QString language)
{
    QFile file("generalInfo.csv");
    try {
        file.open(QIODevice::ReadOnly);
        if(!file.isOpen())
        {
            throw FileException("generalInfo.csv");
        }
    }

    catch(FileException& ex)
    {
        ex.what();
    }

    while(!file.atEnd())
    {
        QString langLine = file.readLine();
        if(language == langLine.split(';').at(0)) //проверка первого елем, отделенного ';' на соот языку
        {
            try {
                for(int i = 1; i < 8; i ++)
                {
                if(langLine.split(';').at(i)=="")
                {
                    throw EmptyFileException("generalInfo.csv");
                }
                }
            langLine.resize(langLine.size() - 2);
            this->aboutAM = langLine.split(';').at(1);
            this->forWhom = langLine.split(';').at(2);
            this->Payments = langLine.split(';').at(3);
            this->requiredLanguage = langLine.split(';').at(4);
            this->whereToStart = langLine.split(';').at(5);
            this->Contacts = langLine.split(';').at(6);
            this->SOP = langLine.split(';').at(7);
            break;
            }
            catch(EmptyFileException& ex)
            {
                ex.what();
            }
        }
    }
    file.close();
    }
