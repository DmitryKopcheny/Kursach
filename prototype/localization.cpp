#include "localization.h"
#include <QFile>
Localization::Localization(const QString language)
{
  fillTheLclValue(language);
}
void Localization::fillTheLclValue(const QString language)
{
    QFile file("localization.csv");
    file.open(QIODevice::ReadOnly); //для Влада

    QStringList wordList;
    while(!file.atEnd())
    {
        QByteArray langLine = file.readLine();
        if(language == langLine.split(';').at(0)) //проверка первого елем, отделенного ';' на соот языку
        {
                langLine.resize(langLine.size() - 2);
                this->aboutProgramlcl = langLine.split(';').at(1);
                this->chatBotlcl = langLine.split(';').at(2);
                this->contactslcl = langLine.split(';').at(3);
                this->dePochatylcl = langLine.split(';').at(4);
                this->dlyaKogolcl = langLine.split(';').at(5);
                this->findBuglcl = langLine.split(';').at(6);
                this->helplcl = langLine.split(';').at(7);
                this->howToUselcl= langLine.split(';').at(8);
                this->koshtovnistlcl = langLine.split(';').at(9);
                this->langlcl = langLine.split(';').at(10);
                this->moreInfolcl = langLine.split(';').at(11);
                this->nazadlcl = langLine.split(';').at(12);
                this->partn1lcl = langLine.split(';').at(13);
                this->partn2lcl = langLine.split(';').at(14);
                this->partn3lcl = langLine.split(';').at(15);
                this->partn4lcl = langLine.split(';').at(16);
                this->partn5lcl = langLine.split(';').at(17);
                this->partn6lcl = langLine.split(';').at(18);
                this->rateApplcl = langLine.split(';').at(19);
                this->settingslcl = langLine.split(';').at(20);
                this->themeDlcl = langLine.split(';').at(21);
                this->themeLlcl = langLine.split(';').at(22);
                this->themelcl= langLine.split(';').at(23);
                this->univPartnerslcl = langLine.split(';').at(24);
                this->wantToJoinlcl = langLine.split(';').at(25);
                this->whatIsAMlcl = langLine.split(';').at(26);

                break;
        }
    }
    file.close();
}
QString Localization::getLclChatbot()
{
    return this->chatBotlcl;
}

QString Localization::getLclAboutprog()
{
    return this->aboutProgramlcl;
}
QString Localization::getLclContacts() // чатбот -> контакты
{
    return this->contactslcl;
}
QString Localization::getLclDepochaty() // чатбот -> контакты
{
    return this->dePochatylcl;
}
QString Localization::getLclDlyakogo()  // чатбот -> контакты
{
    return this->dlyaKogolcl;
}
QString Localization::getLclFindbug()
{
    return this->findBuglcl;
}
QString Localization::getLclHelp()
{
    return this->helplcl;
}
QString Localization::getLclHowtouse()
{
    return this->howToUselcl;
}
QString Localization::getLclKoshtovnist() // чатбот -> контакты
{
    return this->koshtovnistlcl;
}
QString Localization::getLclLanguage()  // чатбот -> контакты
{
    return this->langlcl;
}
QString Localization::getLclMoredetails() // чатбот -> контакты
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
QString Localization::getLclRateapp()
{
    return this->rateApplcl;
}
QString Localization::getLclSettings()
{
    return this->settingslcl;
}
QString Localization::getLclTheme()
{
    return this->themelcl;
}
QString Localization::getLclThemedark()
{
    return this->themeDlcl;
}
QString Localization::getLclThemelight()
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
