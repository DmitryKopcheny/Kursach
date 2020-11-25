#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <QString>
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
    QString getLclMova();
    QString getLclKoshtovnist();
    QString getLclDepochaty();

    void fillTheLclValue(const QString language);
private:
    QString chatBotlcl,
    settingslcl, helplcl, aboutProgramlcl,
    whatIsAMlcl, univPartnerslcl, partn1lcl, partn2lcl, partn3lcl,
    partn4lcl, partn5lcl, partn6lcl, nazadlcl, contactslcl,
    wantToJoinlcl, themelcl, themeDarklcl, themeLightlcl,
    langlcl, howToUselcl, rateApplcl, findBuglcl,
    moreDetailslcl, dlyaKogolcl, movalcl, koshtovnistlcl,
    dePochatylcl;

};

#endif // LOCALIZATION_H