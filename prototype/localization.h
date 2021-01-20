#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <QString>
#include <QFile>

enum languages{UKRAINIAN, ENGLISH, GERMAN, RUSSIAN};
enum textCodes
{
    ABOUT_PROG, CHATBOT, CONTACTS, HOW_TO_START, FOR_WHO,
    FOUND_BUG, HELP, HOW_TO_USE, PRICE, LANGUAGE,
    MORE_DETAILS, BACK, RATE_APP, SETTINGS,
    THEME_DARK, THEME_LIGHT, THEME, UNIV_PARTN, WANT_JOIN, WHAT_IS_AM,
    SEND, SAVE, SAMPLE_SOP, INPUT_FULLNAME, INPUT_GROUP,
    INPUT_COURSE, INPUT_PHONE_NUM, ERROR_OCURE, SUCCES_REG, GUIDE_LABLE,
    GUIDE_TEXT, FREE_CHATBOT, VERSION, DEVEL_LABLE, DEVEL_TEXT,
    OLEG_NAME, DIMA_NAME, MIKE_NAME, VLAD_NAME, BUG_REPORT_LABLE

};

class Localization
{
public:
    Localization();
    QString getLclText(const int textCode) const;
    void fillTheLclValue();
    void setLang(const int langCode);
    QString getLang() const;
    QString getRegExprName() const;
    QString getRegExprGroup() const;
    QString getRegExprCourse() const;
    QString getRegExprPhone() const;
    int getLangCode() const;
private:
    QString language;
    int langCode;
    QString regularExpressionName;
    QString regularExpressionGroup;
    const QString regularExpressionCourse = "[2-6]";
    const QString regularExpressionPhone = "^\\+\\d{1,2}\\(\\d{3,5}\\)\\d{6,7}$";
    QStringList wordList;

};

#endif // LOCALIZATION_H
