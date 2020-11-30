#include "localization.h"
#include <QFile>
#include <QTextStream>
Localization::Localization()
{
  langCode = UKRAINIAN;
  language = "ukrainian";
  fillTheLclValue();
}
void Localization::setLang(int langCode)
{
  this->langCode = langCode;
  if (langCode == UKRAINIAN)
    {
      language = "ukrainian";
    }
  else if (langCode == ENGLISH)
    {
      language = "english";
    }
  else if (langCode == GERMAN)
    {
      language = "german";
    }
  else if (langCode == RUSSIAN)
    {
      language = "russian";
    }
  else if (langCode == ARAB)
    {
      language = "arab";
    }
  else
    {
      this->langCode = UKRAINIAN;
      language = "ukrainian";
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
void Localization::fillTheLclValue()
{
    QFile file("localization.csv");
    file.open(QIODevice::ReadOnly); //для Влада
QTextStream in(&file);
    while(!file.atEnd())
    {


        QString langLine = in.readLine();
        if(language == langLine.split(',').at(0)) //проверка первого елем, отделенного ';' на соот языку
        {
                langLine.resize(langLine.size() - 2);
//                QStringList strList;
//                for(int i = 1; i< 27; i++)
//                {
//                    strList.append(langLine.split(';').at(i));
//                }

                this->aboutProgramlcl = langLine.split(',').at(1);
                this->chatBotlcl = langLine.split(',').at(2);
                this->contactslcl = langLine.split(',').at(3);
                this->dePochatylcl = langLine.split(',').at(4);
                this->dlyaKogolcl = langLine.split(',').at(5);
                this->findBuglcl = langLine.split(',').at(6);
                this->helplcl = langLine.split(',').at(7);
                this->howToUselcl= langLine.split(',').at(8);
                this->koshtovnistlcl = langLine.split(',').at(9);
                this->langlcl = langLine.split(',').at(10);
                this->moreInfolcl = langLine.split(',').at(11);
                this->nazadlcl = langLine.split(',').at(12);
                this->rateApplcl = langLine.split(',').at(13);
                this->settingslcl = langLine.split(',').at(14);
                this->themeDlcl = langLine.split(',').at(15);
                this->themeLlcl = langLine.split(',').at(16);
                this->themelcl= langLine.split(',').at(17);
                this->univPartnerslcl = langLine.split(',').at(18);
                this->wantToJoinlcl = langLine.split(',').at(19);
                this->whatIsAMlcl = langLine.split(',').at(20);

                break;
        }
    }
    file.close();
}
QString Localization::getLclChatbot() // верхняя строка, надпись Чат-бот
{
    return this->chatBotlcl;
}

QString Localization::getLclAboutprog() //Про программу
{
    return this->aboutProgramlcl;
}
QString Localization::getLclContacts() // чатбот -> контакты
{
    return this->contactslcl;
}
QString Localization::getLclDepochaty() // чатбот -> з чого почати
{
    return this->dePochatylcl;
}
QString Localization::getLclDlyakogo()  // чатбот -> для кого
{
    return this->dlyaKogolcl;
}
QString Localization::getLclFindbug() //Нашли баг?
{
    return this->findBuglcl;
}
QString Localization::getLclHelp() // Помощь
{
    return this->helplcl;
}
QString Localization::getLclHowtouse() // Как пользоваться
{
    return this->howToUselcl;
}
QString Localization::getLclKoshtovnist() // чатбот -> коштовныстть
{
    return this->koshtovnistlcl;
}
QString Localization::getLclLanguage()  // чатбот -> мова
{
    return this->langlcl;
}
QString Localization::getLclMoredetails() // чатбот -> для кого это
{
    return this->moreInfolcl;
}
QString Localization::getLclNazad() // чатбот -> назад
{
    return this->nazadlcl;
}
QString Localization::getLclPartn1()  // чатбот -> универ1
{
    return this->partn1lcl;
}
QString Localization::getLclPartn2()  // чатбот -> универ2
{
    return this->partn2lcl;
}
QString Localization::getLclPartn3()  // чатбот -> универ3
{
    return this->partn3lcl;
}
QString Localization::getLclPartn4()  // чатбот -> универ4
{
    return this->partn4lcl;
}
QString Localization::getLclPartn5()  // чатбот -> универ5
{
    return this->partn5lcl;
}
QString Localization::getLclPartn6()  // чатбот -> универ6
{
    return this->partn6lcl;
}
QString Localization::getLclRateapp() //Оцените приложение
{
    return this->rateApplcl;
}
QString Localization::getLclSettings() //Настройки
{
    return this->settingslcl;
}
QString Localization::getLclTheme() //настройки -> Тема
{
    return this->themelcl;
}
QString Localization::getLclThemedark() //настройки -> Темная
{
    return this->themeDlcl;
}
QString Localization::getLclThemelight()//настройки -> Светлая
{
    return this->themeLlcl;
}
QString Localization::getLclUnivpartn() // чатбот -> университети
{
    return this->univPartnerslcl;
}
QString Localization::getLclWantjoin()  // чатбот -> бажаете приэднатися
{
    return this->wantToJoinlcl;
}

QString Localization::getLclWhatisAM()  // чатбот -> що таке АМ
{
    return this->whatIsAMlcl;
}
