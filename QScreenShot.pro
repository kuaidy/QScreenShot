QT       += core gui network webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

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
    source/api/BaiduDiskApi.cpp \
    source/api//HttpHelper.cpp \
    source/api//wordpressapi.cpp \
    source/common/GlobalVariable.cpp \
    source/UserTokenInfo.cpp \
    source/colorvalue.cpp \
    source/editwindow.cpp \
    source/fixedsizeform.cpp \
    source/formtimer.cpp \
    source/main.cpp \
    source/mainwindow.cpp \
    source/plabel.cpp \
    source/screenview.cpp \
    source/setting.cpp \
    source/shotcommon.cpp\

HEADERS += \
    include/api/BaiduDiskApi.h \
    include/api/HttpHelper.h \
    include/api/wordpressapi.h \
    include/Common/GlobalVariable.h \
    include/UserTokenInfo.h \
    include/colorvalue.h \
    include/editwindow.h \
    include/fixedsizeform.h \
    include/formtimer.h \
    include/mainwindow.h \
    include/plabel.h \
    include/screenview.h \
    include/setting.h \
    include/shotcommon.h\

FORMS += \
    ui/colorvalue.ui \
    ui/editwindow.ui \
    ui/fixedsizeform.ui \
    ui/formtimer.ui \
    ui/mainwindow.ui \
    ui/screenview.ui \
    ui/setting.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resource/resource.qrc

#RC_ICONS=resource/cut.ico
