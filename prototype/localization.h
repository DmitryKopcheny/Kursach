#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <QString>
#include <QFile>

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
<<<<<<< Updated upstream
    QString getLclSend();
=======
    QString getLclSampleSOP(); //Приклад мотивацыйного листа
    QString getLclbtnSend(); //Кнопка отправить
    QString getLclbtnSave(); //кнопка Зберегти
    QString getLclInputFIO(); //Введите фамилию, имя, отчество
    QString getLclInputCourse(); // введите курс
    QString getLclInputGroup(); //введите группу
    QString getLclPhnNumber(); //введите номер телефона
    QString getLclErrorOcure(); //возникла ошибка при рег, вы уже зарег
    QString getLclSuccesReg(); //спасибо, регистр завершена

>>>>>>> Stashed changes

    void fillTheLclValue();
    void setLang(const int langCode);
    QString getLang();
    int getLangCode();
private:
    QString language;
    int langCode;
<<<<<<< Updated upstream
    QString chatBotlcl,
    settingslcl, helplcl, aboutProgramlcl,
    whatIsAMlcl, univPartnerslcl, nazadlcl,
    contactslcl, wantToJoinlcl, themelcl, themeDlcl,
    themeLlcl, langlcl, howToUselcl, rateApplcl,
    findBuglcl, moreInfolcl, dlyaKogolcl, koshtovnistlcl,
    dePochatylcl, sendlcl;
=======

    QStringList wordList;

//    QString chatBotlcl,
//    settingslcl, helplcl, aboutProgramlcl,
//    whatIsAMlcl, univPartnerslcl, nazadlcl,
//    contactslcl, wantToJoinlcl, themelcl, themeDlcl,
//    themeLlcl, langlcl, howToUselcl, rateApplcl,
//    findBuglcl, moreInfolcl, dlyaKogolcl, koshtovnistlcl,
//    dePochatylcl, sampleOfSoplcl, btnSendlcl, btnSavelcl, inputFiolcl, inputCourselcl, inputGrouplcl, inputPhnNumlcl, errorOcurelcl, succesReglcl;
>>>>>>> Stashed changes

};

#endif // LOCALIZATION_H
