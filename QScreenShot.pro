QT+= core gui network
QT+=quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

#win32{
#    LIBS +=User32.LIB
#}

linux-g++*{
    LIBS+=-lX11
}


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    source/displayWidget.cpp \
    source/tabWidget.cpp \
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
    source/AntLine.cpp\

HEADERS += \
    include/displayWidget.h \
    include/tabWidget.h \
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
    include/AntLine.h\

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

DISTFILES += \
    ui/about.qml

RESOURCES += \
    resource/resource.qrc

RC_ICONS=resource/images/cut.ico

#指定ui头文件生成的位置
UI_DIR=../include/ui/
