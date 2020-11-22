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
    QString getStatementOfPurpose();

    void readFromCsv(const QString language);
private:
    QString aboutAM;
    QString forWhom;
    QString Payments;
    QString requiredLanguage;
    QString whereToStart;
    QString Contacts;
    QString SOP; //мотивац лист

};

#endif // GENERALINFO_H
