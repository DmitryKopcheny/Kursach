#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "developer.h"  //інтерфейс
#include "rateapp.h"
#include "bug.h"
#include "manual.h"
#include "settings.h"

#include "textchat.h"   //алгоритми + данні
#include "localization.h" //локалізація
#include "exception.h" //помилки

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->layout_details->hide();
    ui->layout_letter->hide();
    ui->layout_patners->hide();
    ui->layout_enter->hide();

    ui->layout_details->move(0,400);
    ui->layout_letter->move(0,400);
    ui->layout_patners->move(0,400);
    ui->layout_enter->move(10,400);

    Locale = new Localization;
    Chat = new TextChat(Locale->getLang());

    studInfo = nullptr;
    bugForm = nullptr;
    developerForm = nullptr;
    manualForm = nullptr;
    rateAppForm = nullptr;
    settingsForm = nullptr;

    this->setWindowTitle(Locale->getLclChatbot());
    ui->menu->setTitle(Locale->getLclSettings());
    ui->menu_2->setTitle(Locale->getLclHelp());
    ui->menu_3->setTitle(Locale->getLclAboutprog());
    ui->action->setText(Locale->getLclHowtouse());
    ui->action_2->setText(Locale->getLclRateapp());
    ui->action_3->setText(Locale->getLclMoredetails());
    ui->action_4->setText(Locale->getLclSettings());
    ui->action_5->setText(Locale->getLclFindbug());
    ui->action_7->setText(Locale->getLclbtnSave());
    ui->btn1->setText(Locale->getLclWhatisAM());
    ui->btn2->setText(Locale->getLclUnivpartn());
    ui->btn3->setText(Locale->getLclWantjoin());
    ui->btn4->setText(Locale->getLclContacts());
    ui->btn1_1->setText(Locale->getLclDlyakogo());
    ui->btn1_2->setText(Locale->getLclLanguage());
    ui->btn1_3->setText(Locale->getLclKoshtovnist());
    ui->btn1_4->setText(Locale->getLclDepochaty());
    ui->btn1_4_1->setText(Locale->getLclSampleSOP());
    ui->btn1_back->setText(Locale->getLclNazad());
    ui->btn2_back->setText(Locale->getLclNazad());
    ui->btn1_4_back->setText(Locale->getLclNazad());
    ui->btn2_1->setText(Chat->getUnName(0));
    ui->btn2_2->setText(Chat->getUnName(1));
    ui->btn2_3->setText(Chat->getUnName(2));
    ui->btn2_4->setText(Chat->getUnName(3));
    ui->btn2_5->setText(Chat->getUnName(4));
    ui->btn2_6->setText(Chat->getUnName(5));
}

MainWindow::~MainWindow()
{
    delete Locale;
    delete Chat;
    delete ui;
}

void  MainWindow::on_LanguageChanged() //зміни тексту всіх лейблів, кнопок, і меню, а також повідомлень бота
{
    Chat->readFromXml(Locale->getLang());
    Chat->readFromCsv(Locale->getLang());
    Locale->fillTheLclValue();
    this->setWindowTitle(Locale->getLclChatbot());
    ui->menu->setTitle(Locale->getLclSettings());
    ui->menu_2->setTitle(Locale->getLclHelp());
    ui->menu_3->setTitle(Locale->getLclAboutprog());
    ui->action->setText(Locale->getLclHowtouse());
    ui->action_2->setText(Locale->getLclRateapp());
    ui->action_3->setText(Locale->getLclMoredetails());
    ui->action_4->setText(Locale->getLclSettings());
    ui->action_5->setText(Locale->getLclFindbug());
    ui->action_7->setText(Locale->getLclbtnSave());
    ui->btn1->setText(Locale->getLclWhatisAM());
    ui->btn2->setText(Locale->getLclUnivpartn());
    ui->btn3->setText(Locale->getLclWantjoin());
    ui->btn4->setText(Locale->getLclContacts());
    ui->btn1_1->setText(Locale->getLclDlyakogo());
    ui->btn1_2->setText(Locale->getLclLanguage());
    ui->btn1_3->setText(Locale->getLclKoshtovnist());
    ui->btn1_4->setText(Locale->getLclDepochaty());
    ui->btn1_4_1->setText(Locale->getLclSampleSOP());
    ui->btn1_back->setText(Locale->getLclNazad());
    ui->btn2_back->setText(Locale->getLclNazad());
    ui->btn1_4_back->setText(Locale->getLclNazad());
    ui->btn2_1->setText(Chat->getUnName(0));
    ui->btn2_2->setText(Chat->getUnName(1));
    ui->btn2_3->setText(Chat->getUnName(2));
    ui->btn2_4->setText(Chat->getUnName(3));
    ui->btn2_5->setText(Chat->getUnName(4));
    ui->btn2_6->setText(Chat->getUnName(5));
    emit localizateWindows();
}
void MainWindow::on_action_3_triggered()  //про програму
{
    if (developerForm == nullptr)
    {
        developerForm = new developer(Locale);
        connect(this, SIGNAL(localizateWindows()),developerForm, SLOT(on_localizateWindows()));
        emit localizateWindows();
    }
    developerForm->show();
    developerForm->activateWindow();
}

void MainWindow::on_action_2_triggered()  //оцінити додаток
{
    if (rateAppForm == nullptr)
    {
        rateAppForm = new rateApp(Locale);
        connect(this, SIGNAL(localizateWindows()),rateAppForm, SLOT(on_localizateWindows()));
        emit localizateWindows();
    }
    rateAppForm->show();
    rateAppForm->activateWindow();
}

void MainWindow::on_action_4_triggered()  //налаштування
{
    if (settingsForm == nullptr)
    {
        settingsForm = new settings(Locale);
        connect(this, SIGNAL(localizateWindows()),settingsForm, SLOT(on_localizateWindows()));
        connect(settingsForm, SIGNAL(LanguageChanged()),this, SLOT(on_LanguageChanged()));
        emit localizateWindows();
    }
    settingsForm->show();
    settingsForm->activateWindow();
}

void MainWindow::on_action_triggered()  //як користуватися
{
    if (manualForm == nullptr)
    {
        manualForm = new manual(Locale);
        connect(this, SIGNAL(localizateWindows()),manualForm, SLOT(on_localizateWindows()));
        emit localizateWindows();
    }
    manualForm->show();
    manualForm->activateWindow();
}

void MainWindow::on_action_5_triggered()  //повідомлення про баг
{
    if (bugForm == nullptr)
    {
        bugForm = new bug(Locale);
        connect(this, SIGNAL(localizateWindows()),bugForm, SLOT(on_localizateWindows()));
        emit localizateWindows();
    }
    bugForm->show();
    bugForm->activateWindow();
}

void MainWindow::on_action_7_triggered()  //зберегти
{
    Chat->sortStudents();
    Chat->writeToXml();
}

void MainWindow::on_btn1_clicked()//що таке АМ
{
    ui->layout_details->show();
    ui->layout_main->hide();
    ui->layout_enter->hide();

    Chat->addNewMessage(true, ui->btn1->text());
    Chat->addNewMessage(false, Chat->getAboutAM());
    displayChat();
}

void MainWindow::on_btn2_clicked()//університети
{
        ui->layout_patners->show();
        ui->layout_main->hide();
        ui->layout_enter->hide();

        QString partners;
        for (int i = 0; i<Chat->getSizeOfUniv(); i++)
        {
            partners += Chat->getUnName(i);
            partners += "\n";
        }
        Chat->addNewMessage(true, ui->btn2->text());
        Chat->addNewMessage(false, partners);   
    displayChat();
}

void MainWindow::on_btn3_clicked()//реєстація
{
    ui->layout_enter->show();
    ui->layout_main->hide();
    Chat->addNewMessage(true, ui->btn3->text());
    Chat->addNewMessage(false, Locale->getLclInputFIO());
    studInfo = new Student;
    displayChat();
}

void MainWindow::on_btn_enter_clicked() //кнопка enter
{
    QString usersInput;
    QString message;
    QString rxeng, rxukr, rxrus;
    Validate str;
    usersInput = ui->lineEdit->text();
    try {
        if (studInfo->fullName.isEmpty())
        {
            if (!str.validates(usersInput,Locale->getRegExprName()))
            {
                throw RegisterException(1);
            }
            studInfo->fullName = usersInput.toUpper(); //toUpper для того чтобы легче было сортировать
            message = Locale->getLclInputGroup();
        }

        else if (studInfo->group.isEmpty())
        {
            if (!str.validates(usersInput,Locale->getRegExprGroup()))
            {
                throw RegisterException(2);
            }

            studInfo->group = usersInput.toUpper(); //toUpper для того чтобы легче было сортировать
            message = Locale->getLclInputCourse();
        }

        else if (studInfo->course == 0)
        {
            if (!str.validates(usersInput,Locale->getRegExprCourse()))
            {
                throw RegisterException(3);
            }

            studInfo->course = usersInput.toInt();
            message = Locale->getLclPhnNumber();

        }

        else if (studInfo->phoneNumber.isEmpty())
        {
            if (!str.validates(usersInput,Locale->getRegExprPhone()))
            {
                throw RegisterException(4);
            }
            studInfo->phoneNumber = usersInput;
        }

        if (studInfo->isComplete())
        {
            message = Locale->getLclErrorOcure();
            if (!Chat->searchForTheSame(*studInfo))
            {
                Chat->addStudent(*studInfo);
                message = Locale->getLclSuccesReg();
            }
            delete studInfo;
            studInfo = nullptr;
            ui->layout_main->show();
            ui->layout_enter->hide();
        }
        Chat->addNewMessage(true, usersInput);
        Chat->addNewMessage(false, message);
        displayChat();
        ui->lineEdit->clear();
    }

    catch(RegisterException& ex)
    {
        ex.what();
    }
}

void MainWindow::on_btn4_clicked()//контакти
{
    Chat->addNewMessage(true, ui->btn4->text());
    Chat->addNewMessage(false, Chat->getContacts());
    displayChat();
}

void MainWindow::on_btn1_1_clicked()//для кого це
{
    Chat->addNewMessage(true, ui->btn1_1->text());
    Chat->addNewMessage(false, Chat->getForWhom());
    displayChat();
}

void MainWindow::on_btn1_2_clicked()//мова
{
    Chat->addNewMessage(true, ui->btn1_2->text());
    Chat->addNewMessage(false, Chat->getRequiredLang());
    displayChat();
}

void MainWindow::on_btn1_3_clicked()//коштoвність
{
    Chat->addNewMessage(true, ui->btn1_3->text());
    Chat->addNewMessage(false, Chat->getPayments());
    displayChat();
}

void MainWindow::on_btn1_4_clicked()//з чого почати
{
    ui->layout_letter->show();
    ui->layout_details->hide();

    Chat->addNewMessage(true, ui->btn1_4->text());
    Chat->addNewMessage(false, Chat->getWhereToStart());
    displayChat();
}

void MainWindow::on_btn1_4_1_clicked()//приклад мотиваційного листа
{
    Chat->addNewMessage(true, ui->btn1_4_1->text());
    Chat->addNewMessage(false, Chat->getStatementOfPurpose());
    displayChat();
}

void MainWindow::on_btn2_1_clicked()//унівеситет 1
{
    QString university;

    university += Chat->getUnName(0);
    university += "\n";
    university += Chat->getMainInfo(0);

    Chat->addNewMessage(true, ui->btn2_1->text());
    Chat->addNewMessage(false, university);
    displayChat();
}

void MainWindow::on_btn2_2_clicked()//унівеситет 2
{
    QString university;

    university += Chat->getUnName(1);
    university += "\n";
    university += Chat->getMainInfo(1);

    Chat->addNewMessage(true, ui->btn2_2->text());
    Chat->addNewMessage(false, university);
    displayChat();
}

void MainWindow::on_btn2_3_clicked()//унівеситет 3
{
    QString university;
    university += Chat->getUnName(2);
    university += "\n";
    university += Chat->getMainInfo(2);
    Chat->addNewMessage(true, ui->btn2_3->text());
    Chat->addNewMessage(false, university);
    displayChat();
}

void MainWindow::on_btn2_4_clicked()//унівеситет 4
{
    QString university;
    university += Chat->getUnName(3);
    university += "\n";
    university += Chat->getMainInfo(3);
    Chat->addNewMessage(true, ui->btn2_4->text());
    Chat->addNewMessage(false, university);
    displayChat();
}

void MainWindow::on_btn2_5_clicked()//унівеситет 5
{
    QString university;
    university += Chat->getUnName(4);
    university += "\n";
    university += Chat->getMainInfo(4);
    Chat->addNewMessage(true, ui->btn2_5->text());
    Chat->addNewMessage(false, university);
    displayChat();
}

void MainWindow::on_btn2_6_clicked()//унівеситет 6
{
    QString university;
    university += Chat->getUnName(5);
    university += "\n";
    university += Chat->getMainInfo(5);
    Chat->addNewMessage(true, ui->btn2_6->text());
    Chat->addNewMessage(false, university);
    displayChat();
}

void MainWindow::on_btn1_back_clicked()//назад
{
    ui->layout_main->show();
    ui->layout_details->hide();
}

void MainWindow::on_btn2_back_clicked()//назад
{
    ui->layout_main->show();
    ui->layout_patners->hide();
}

void MainWindow::on_btn1_4_back_clicked()//назад
{
    ui->layout_details->show();
    ui->layout_letter->hide();
}

void MainWindow::displayChat()  //отображение текста в чате
{
    ui->textBrowser->clear();
    Chat->resetIterators();
    while (!Chat->isEnd())
    {

        if (Chat->getIsUsersMessage())  //если сообщение отправлено пользователем
        {
            QString nameAndDate;
            ui->textBrowser->setAlignment(Qt::AlignRight);
            nameAndDate.append(Chat->getNextTime()).append(" USER:");
            ui->textBrowser->append(nameAndDate);
            ui->textBrowser->append(Chat->getNextMessage()+="\n");
        }
        else                            //если сообщение отправлено ботом
        {
            QString nameAndDate;
            ui->textBrowser->setAlignment(Qt::AlignLeft);
            nameAndDate.append(Chat->getNextTime()).append(" BOT:");
            ui->textBrowser->append(nameAndDate);
            ui->textBrowser->append(Chat->getNextMessage()+="\n");
        }
    }

}


