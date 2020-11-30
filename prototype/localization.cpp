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

    while(!file.atEnd()) //in.atEnd
    {

        QString langLine = file.readLine();
        if(language == langLine.split(';').at(0)) //проверка первого елем, отделенного ';' на соот языку
        {
<<<<<<< Updated upstream
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
                this->sendlcl = langLine.split(',').at(21);
=======

                //langLine.resize(langLine.size() - 2);// !ЕСЛИ В КОНЦЕ КАКОГО-ЛИБО СЛОВА БУДУТ ЗНАКИ ПЕРЕНОСА СТРОКИ - раскоментить

                    wordList.clear();
                    for(int i = 1; i < 30; i ++)
                    {
                        wordList.append(langLine.split(';').at(i));
                    }

//                this->aboutProgramlcl = langLine.split(';').at(1);
//                this->chatBotlcl = langLine.split(';').at(2);
//                this->contactslcl = langLine.split(';').at(3);
//                this->dePochatylcl = langLine.split(';').at(4);
//                this->dlyaKogolcl = langLine.split(';').at(5);
//                this->findBuglcl = langLine.split(';').at(6);
//                this->helplcl = langLine.split(';').at(7);
//                this->howToUselcl= langLine.split(';').at(8);
//                this->koshtovnistlcl = langLine.split(';').at(9);
//                this->langlcl = langLine.split(';').at(10);
//                this->moreInfolcl = langLine.split(';').at(11);
//                this->nazadlcl = langLine.split(';').at(12);
//                this->rateApplcl = langLine.split(';').at(13);
//                this->settingslcl = langLine.split(';').at(14);
//                this->themeDlcl = langLine.split(';').at(15);
//                this->themeLlcl = langLine.split(';').at(16);
//                this->themelcl= langLine.split(';').at(17);
//                this->univPartnerslcl = langLine.split(';').at(18);
//                this->wantToJoinlcl = langLine.split(';').at(19);
//                this->whatIsAMlcl = langLine.split(';').at(20);
//                this->btnSendlcl = langLine.split(';').at(21);
//                this->btnSavelcl = langLine.split(';').at(22);
//                this->sampleOfSoplcl = langLine.split(';').at(23);
//                this->inputFiolcl = langLine.split(';').at(24);
//                this->inputGrouplcl = langLine.split(';').at(25);
//                this->inputCourselcl = langLine.split(';').at(26);
//                this->inputPhnNumlcl = langLine.split(';').at(27);
//                this->errorOcurelcl = langLine.split(';').at(28);
//                this->succesReglcl = langLine.split(';').at(29);



>>>>>>> Stashed changes

                break;
        }
    }
    file.close();
}
QString Localization::getLclChatbot() // верхняя строка, надпись Чат-бот
{
    return wordList.at(1);
}

QString Localization::getLclAboutprog() //Про программу
{
    return wordList.at(0);
}
QString Localization::getLclContacts() // чатбот -> контакты
{
    return wordList.at(2);
}
QString Localization::getLclDepochaty() // чатбот -> з чого почати
{
        return wordList.at(3);
}

QString Localization::getLclSampleSOP() //приклад мотив листа
{
        return wordList.at(22);
}

QString Localization::getLclbtnSend() //кнопка Отправить
{
        return wordList.at(20);
}

QString Localization::getLclbtnSave() //Кнопка Сохранить
{
        return wordList.at(21);
}

QString Localization::getLclInputFIO() // строка Введите имя, фам, отчество
{
        return wordList.at(23);
}

QString Localization::getLclInputCourse() // строка Введите курс
{
        return wordList.at(25);
}

QString Localization::getLclInputGroup() // строка регистрации Введите группу
{
        return wordList.at(24);
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
QString Localization::getLclSend()
{
    return this->sendlcl;
}
