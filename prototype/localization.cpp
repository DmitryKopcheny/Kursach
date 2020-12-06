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
        regularExpressionName = "[А-я,і,І,Ї,ї,є,Є]{3,20}\\s[А-я,і,І,Ї,ї,є,Є]{3,20}\\s[А-я,і,І,Ї,ї,є,Є]{3,20}";
        regularExpressionGroup = "[А-я,і,І,Ї,ї,є,Є]{3}\\-\\d{3}";
    }
    else if (langCode == ENGLISH)
    {
        language = "english";
        regularExpressionName = "[A-z]{3,20}\\s[A-z]{3,20}\\s[A-z]{3,20}";
        regularExpressionGroup = "[A-z]{3}\\-\\d{3}";
    }
    else if (langCode == GERMAN)
    {
        language = "german";
        regularExpressionName = "[A-z,Ä,ä,Ö,ö,Ü,ü]{3,20}\\s[A-z,Ä,ä,Ö,ö,Ü,ü]{3,20}\\s[A-z,Ä,ä,Ö,ö,Ü,ü]{3,20}";
        regularExpressionGroup = "[A-z,Ä,ä,Ö,ö,Ü,ü]{3}\\-\\d{3}";
    }
    else if (langCode == RUSSIAN)
    {
        language = "russian";
        regularExpressionName = "[А-я]{3,20}\\s[А-я]{3,20}\\s[А-я]{3,20}";
        regularExpressionGroup = "[А-Я]{3}\\-\\d{3}";
    }
    else
    {
        this->langCode = UKRAINIAN;
        language = "ukrainian";
        regularExpressionName = "[А-я,і,І,Ї,ї,є,Є]{3,20}\\s[А-я,і,І,Ї,ї,є,Є]{3,20}\\s[А-я,і,І,Ї,ї,є,Є]{3,20}";
        regularExpressionGroup = "[А-Я,І,Ї,-]\\d";
    }
}
QString Localization::getLang()
{
    return language;
}

int Localization::getLangCode()
{
    return langCode;
}

QString Localization::getRegExprName()
{
    return regularExpressionName;
}

QString Localization::getRegExprGroup()
{
    return regularExpressionGroup;
}
QString Localization::getRegExprCourse()
{
    return regularExpressionCourse;
}

QString Localization::getRegExprPhone()
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
                    }

               catch(ReadingDataException& ex)
                    {
                        temp = ex.whats();
                    }
                wordList.append(temp);
            }
            break;
        }
    }
    file.close();
}
QString Localization::getLclAboutprog() //Про программу
{
    return wordList.at(0);
}

QString Localization::getLclChatbot() // верхняя строка, надпись Чат-бот
{
    return wordList.at(1);
}

QString Localization::getLclContacts() // чатбот -> контакты
{
    return wordList.at(2);
}
QString Localization::getLclDepochaty() // чатбот -> з чого почати
{
    return wordList.at(3);
}

QString Localization::getLclDlyakogo()  // чатбот -> для кого
{
    return wordList.at(4);
}

QString Localization::getLclFindbug() //Нашли баг?
{
    return wordList.at(5);
}

QString Localization::getLclHelp() // Помощь
{
    return wordList.at(6);
}

QString Localization::getLclHowtouse() // Как пользоваться
{
    return wordList.at(7);
}

QString Localization::getLclKoshtovnist() // чатбот -> коштовныстть
{
    return wordList.at(8);
}

QString Localization::getLclLanguage()  // чатбот -> мова
{
    return wordList.at(9);
}

QString Localization::getLclMoredetails() // чатбот -> для кого это
{
    return wordList.at(10);
}

QString Localization::getLclNazad() // чатбот -> назад
{
    return wordList.at(11);
}

QString Localization::getLclRateapp() //Оцените приложение
{
    return wordList.at(12);
}

QString Localization::getLclSettings() //Настройки
{
    return wordList.at(13);
}

QString Localization::getLclTheme() //настройки -> Тема
{
    return wordList.at(16);
}

QString Localization::getLclThemedark() //настройки -> Темная
{
    return wordList.at(14);
}

QString Localization::getLclThemelight()//настройки -> Светлая
{
    return wordList.at(15);
}

QString Localization::getLclUnivpartn() // чатбот -> университети
{
    return wordList.at(17);
}

QString Localization::getLclWantjoin()  // чатбот -> бажаете приэднатися
{
    return wordList.at(18);
}

QString Localization::getLclWhatisAM()  // чатбот -> що таке АМ

{
    return wordList.at(19);
}

QString Localization::getLclbtnSend() //кнопка Отправить
{
    return wordList.at(20);
}

QString Localization::getLclbtnSave() //Кнопка Сохранить
{
    return wordList.at(21);
}

QString Localization::getLclSampleSOP() //приклад мотив листа
{
    return wordList.at(22);
}

QString Localization::getLclInputFIO() // строка Введите имя, фам, отчество
{
    return wordList.at(23);
}

QString Localization::getLclInputGroup() // строка регистрации Введите группу
{
    return wordList.at(24);
}

QString Localization::getLclInputCourse() // строка Введите курс
{
    return wordList.at(25);
}


QString Localization::getLclPhnNumber()// строка регистр введите номер тел
{
    return wordList.at(26);
}

QString Localization::getLclErrorOcure() //строка рег, возникла ошибка, вы уже зареганы
{
    return wordList.at(27);
}

QString Localization::getLclSuccesReg() //строка рег, успех регистрации
{
    return wordList.at(28);
}

QString Localization::getLclGuideLable() // лейбл руков пользователя
{
    return wordList.at(29);
}

QString Localization::getLclGuideText() // текст руков пользователя
{
    return wordList.at(30);
}

QString Localization::getLclFreeChatBot() // бесплатный чат-бот, предназ
{
    return wordList.at(31);
}

QString Localization::getLclVersin() // Версия
{
    return wordList.at(32);
}

QString Localization::getLclDevelLabel() // лейбл разрабы
{
    return wordList.at(33);
}

QString Localization::getLclDevelText() //текст разрабы
{
    return wordList.at(34);
}

QString Localization::getLclDevOlegName()
{
    return wordList.at(35);
}

QString Localization::getLclDevDimaName()
{
    return wordList.at(36);
}

QString Localization::getLclDevMikeName()
{
    return wordList.at(37);
}

QString Localization::getLclDevVladName()
{
    return wordList.at(38);
}

QString Localization::getLclBugReportLable()
{
    return wordList.at(39);
}
