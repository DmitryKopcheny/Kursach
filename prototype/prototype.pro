QT       += core gui
QT += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bug.cpp \
    chatbot.cpp \
    chatuser.cpp \
    developer.cpp \
    generalinfo.cpp \
    main.cpp \
    mainwindow.cpp \
    manual.cpp \
    rateapp.cpp \
    settings.cpp \
    studentam.cpp \
    textchat.cpp \
    universityam.cpp

HEADERS += \
    basic_user.h \
    bug.h \
    chatbot.h \
    chatuser.h \
    developer.h \
    generalinfo.h \
    mainwindow.h \
    manual.h \
    rateapp.h \
    settings.h \
    studentam.h \
    textchat.h \
    universityam.h

FORMS += \
    bug.ui \
    developer.ui \
    mainwindow.ui \
    manual.ui \
    rateapp.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=
