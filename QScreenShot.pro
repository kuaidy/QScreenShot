QT       += core gui network webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

win32{
LIBS +=User32.LIB
}

linux-g++*{
    LIBS+=-lX11
}


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Api/BaiduDiskApi.cpp \
    Api/HttpHelper.cpp \
    Api/wordpressapi.cpp \
    Models/UserTokenInfo.cpp \
    colorvalue.cpp \
    editwindow.cpp \
    fixedsizeform.cpp \
    formtimer.cpp \
    main.cpp \
    mainwindow.cpp \
    screenview.cpp \
    setting.cpp \
    shotcommon.cpp\

HEADERS += \
    Api/BaiduDiskApi.h \
    Api/HttpHelper.h \
    Api/wordpressapi.h \
    Models/UserTokenInfo.h \
    colorvalue.h \
    editwindow.h \
    fixedsizeform.h \
    formtimer.h \
    mainwindow.h \
    screenview.h \
    setting.h \
    shotcommon.h\

FORMS += \
    colorvalue.ui \
    editwindow.ui \
    fixedsizeform.ui \
    formtimer.ui \
    mainwindow.ui \
    screenview.ui \
    setting.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resource.qrc
