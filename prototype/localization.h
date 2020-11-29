#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <QString>
//#include <QFile>
class Localization
{
public:
    Localization(const QString language);
    QString getLclChatbot();
    QString getLclSettings();
    QString getLclHelp();
    QString getLclAboutprog();
    QString getLclWhatisAM();
    QString getLclUnivpartn();
    QString getLclPartn1();
    QString getLclPartn2();
    QString getLclPartn3();
    QString getLclPartn4();
    QString getLclPartn5();
    QString getLclPartn6();
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

    void fillTheLclValue(const QString language);
private:
//    QStringList strList;
    QString chatBotlcl,
    settingslcl, helplcl, aboutProgramlcl,
    whatIsAMlcl, univPartnerslcl, partn1lcl, partn2lcl,
    partn3lcl, partn4lcl, partn5lcl, partn6lcl, nazadlcl,
    contactslcl, wantToJoinlcl, themelcl, themeDlcl,
    themeLlcl, langlcl, howToUselcl, rateApplcl,
    findBuglcl, moreInfolcl, dlyaKogolcl, koshtovnistlcl,
    dePochatylcl;

};

#endif // LOCALIZATION_H
