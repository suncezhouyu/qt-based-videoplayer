#-------------------------------------------------
#
# Project created by QtCreator 2018-11-02T20:03:58
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VideoPlayer
TEMPLATE = app


SOURCES += main.cpp \
    videoplayer.cpp \
    playerslider.cpp

HEADERS  += \
    videoplayer.h \
    playerslider.h

FORMS    += \
    videoplayer.ui
