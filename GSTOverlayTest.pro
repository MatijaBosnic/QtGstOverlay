#-------------------------------------------------
#
# Project created by QtCreator 2017-08-31T10:54:47
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GSTOverlayTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gstplayer.cpp

HEADERS  += mainwindow.h \
    gstplayer.h

FORMS    += mainwindow.ui

LIBS += -lQt5GStreamer-1.0 -lQt5GStreamerUi-1.0 -lQt5GStreamerUtils-1.0 -lQt5GLib-2.0

RESOURCES += \
    resource.qrc
