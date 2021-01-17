#include "localization.h"
#include "exception.h"
Localization::Localization()
{
    setLang(UKRAINIAN);
    fillTheLclValue();
}
void Localization::setLang(int langCode)
{
    this->langCode = langCode;
    if (langCode == UKRAINIAN)
    {
        language = "ukrainian";
        regularExpressionName = "[А-я,і,І,Ї,ї,є,Є]{2,20}\\s[А-я,і,І,Ї,ї,є,Є]{2,20}\\s[А-я,і,І,Ї,ї,є,Є]{2,20}";
        regularExpressionGroup = "[А-я,і,І,Ї,ї,є,Є]{1,3}\\-\\d{1,3}";
    }
    else if (langCode == ENGLISH)
    {
        language = "english";
        regularExpressionName = "[A-z]{2,20}\\s[A-z]{2,20}\\s[A-z]{2,20}";
        regularExpressionGroup = "[A-z]{1,3}\\-\\d{1,3}";
    }
    else if (langCode == GERMAN)
    {
        language = "german";
        regularExpressionName = "[A-z,Ä,ä,Ö,ö,Ü,ü]{2,20}\\s[A-z,Ä,ä,Ö,ö,Ü,ü]{2,20}\\s[A-z,Ä,ä,Ö,ö,Ü,ü]{2,20}";
        regularExpressionGroup = "[A-z,Ä,ä,Ö,ö,Ü,ü]{1,3}\\-\\d{1,3}";
    }
    else if (langCode == RUSSIAN)
    {
        language = "russian";
        regularExpressionName = "[А-я]{2,20}\\s[А-я]{2,20}\\s[А-я]{2,20}";
        regularExpressionGroup = "[А-я]{1,3}\\-\\d{1,3}";
    }
    else
    {
        this->langCode = UKRAINIAN;
        language = "ukrainian";
        regularExpressionName = "[А-я,і,І,Ї,ї,є,Є]{2,20}\\s[А-я,і,І,Ї,ї,є,Є]{2,20}\\s[А-я,і,І,Ї,ї,є,Є]{2,20}";
        regularExpressionGroup = "[А-я,і,І,Ї,ї,є,Є]{1,3}\\-\\d{1,3}";
    }
}
QString Localization::getLang() const
{
    return language;
}

int Localization::getLangCode() const
{
    return langCode;
}

QString Localization::getRegExprName() const
{
    return regularExpressionName;
}

QString Localization::getRegExprGroup() const
{
    return regularExpressionGroup;
}
QString Localization::getRegExprCourse() const
{
    return regularExpressionCourse;
}

QString Localization::getRegExprPhone() const
{
    return regularExpressionPhone;
}

void Localization::fillTheLclValue()
{
    QFile file("localization.csv");
    try {
        file.open(QIODevice::ReadOnly);
        if(!file.isOpen())
        {
            throw FileException("localization.csv");
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
            wordList.clear();
            for(int i = 1; i < 41; i ++)
            {
                QString temp;
                try
                    {
                        if(langLine.split(';').at(i) == "")
                            {
                                throw ReadingDataException("localization.csv");
                            }
                        temp = langLine.split(';').at(i);
                        wordList.clear();
                        for(int i = 1; i < 41; i ++)
                        {
                            wordList.append(langLine.split(';').at(i));

                        }
                    }
               catch(ReadingDataException& ex)
                    {
                        temp = ex.what();
                    }
                wordList.append(temp);
            }
            break;
        }
    }
    file.close();
}

QString Localization::getLclText(const int textCode) const
{
    return wordList.at(textCode);
}
