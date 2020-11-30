#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <QString>
//#include <QFile>

enum langeages{UKRAINIAN, ENGLISH, GERMAN, RUSSIAN};

class Localization
{
public:
    Localization();
    QString getLclChatbot();
    QString getLclSettings();
    QString getLclHelp();
    QString getLclAboutprog();
    QString getLclWhatisAM();
    QString getLclUnivpartn();
    QString getLclNazad();
    QString getLclContacts();
    QString getLclWantjoin();
    QString getLclTheme();
    QString getLclThemedark();
    QString getLclThemelight();
    QString getLclLanguage();
    QString getLclHowtouse();
    QString getLclRateapp();
    QString getLclFindbug();
    QString getLclMoredetails();
    QString getLclDlyakogo();
    QString getLclKoshtovnist();
    QString getLclDepochaty();

    void fillTheLclValue();
    void setLang(const int langCode);
    QString getLang();
    int getLangCode();
private:
    QString language;
    int langCode;
    QString chatBotlcl,
    settingslcl, helplcl, aboutProgramlcl,
    whatIsAMlcl, univPartnerslcl, nazadlcl,
    contactslcl, wantToJoinlcl, themelcl, themeDlcl,
    themeLlcl, langlcl, howToUselcl, rateApplcl,
    findBuglcl, moreInfolcl, dlyaKogolcl, koshtovnistlcl,
    dePochatylcl;

};

#endif // LOCALIZATION_H
