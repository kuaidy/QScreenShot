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
    source/common/gaussianblur.cpp \
    source/common/globalsetting.cpp \
    source/displaywidget.cpp \
    source/imagelabel.cpp \
    source/tabwidget.cpp \
    source/api/baidudiskApi.cpp \
    source/api//httphelper.cpp \
    source/api//wordpressapi.cpp \
    source/common/globalvariable.cpp \
    source/usertokeninfo.cpp \
    source/colorvalue.cpp \
    source/editwindow.cpp \
    source/fixedsizeform.cpp \
    source/formtimer.cpp \
    source/main.cpp \
    source/mainwindow.cpp \
    source/screenview.cpp \
    source/setting.cpp \
    source/shotcommon.cpp\
    source/antline.cpp\

HEADERS += \
    include/common/gaussianblur.h \
    include/common/globalsetting.h \
    include/displaywidget.h \
    include/imagelabel.h \
    include/tabwidget.h \
    include/api/baidudiskApi.h \
    include/api/httphelper.h \
    include/api/wordpressapi.h \
    include/common/globalvariable.h \
    include/usertokeninfo.h \
    include/colorvalue.h \
    include/editwindow.h \
    include/fixedsizeform.h \
    include/formtimer.h \
    include/mainwindow.h \
    include/screenview.h \
    include/setting.h \
    include/shotcommon.h\
    include/antline.h\

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
UI_DIR=../QScreenShot/include/ui/
