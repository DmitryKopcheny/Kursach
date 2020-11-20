#ifndef GENERALINFO_H
#define GENERALINFO_H

#include <QString>
#include <QStringList>
#include <QFile>

class GeneralInfo
{
public:
    GeneralInfo();
    QString getAboutAM();
    QString getForWhom();
    QString getPayments();
    QString getRequiredLang();
    QString getWhereToStart();
    QString getContacts();

    void readFromCsv(const QString language);
private:
    QString aboutAM;
    QString forWhom;
    QString Payments;
    QString requiredLanguage;
    QString whereToStart;
    QString Contacts;

};

#endif // GENERALINFO_H
