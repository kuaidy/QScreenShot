QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    editwindow.cpp \
    fixedsizeform.cpp \
    formtimer.cpp \
    main.cpp \
    mainwindow.cpp \
    screenview.cpp

HEADERS += \
    editwindow.h \
    fixedsizeform.h \
    formtimer.h \
    mainwindow.h \
    screenview.h

FORMS += \
    editwindow.ui \
    fixedsizeform.ui \
    formtimer.ui \
    mainwindow.ui \
    screenview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resource.qrc
