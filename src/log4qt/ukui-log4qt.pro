QT -= gui

TEMPLATE = lib
DEFINES += LIBUKUILOG4QT_LIBRARY

CONFIG += link_pkgconfig \
            c++11

PKGCONFIG += gsettings-qt

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#log4qt
include($$PWD/log4qt/log4qt.pri)

SOURCES += \
    ukui-logconfigurator.cpp \
    ukui-logrolling.cpp \
    ukui-log4qt.cpp

HEADERS += \
    ukui-logmacros.h \
    ukui-logconfigurator.h \
    ukui-logrolling.h \
    ukui-log4qt.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

schemes.files += org.ukui.log4qt.gschema.xml
schemes.path = /usr/share/glib-2.0/schemas/

headers_main.path = /usr/include
headers_main.files += ukui-log4qt.h

INSTALLS += schemes \
            headers_main

DISTFILES += \
    log4qt.conf
