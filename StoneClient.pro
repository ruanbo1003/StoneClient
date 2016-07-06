#-------------------------------------------------
#
# Project created by QtCreator 2016-07-04T16:02:54
#
#-------------------------------------------------

QT       += core gui
QT       += network
RC_ICONS += stone.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StoneClient
TEMPLATE = app


SOURCES += main.cpp\
        stone.cpp \
    rubotcp.cpp \
    msgs/msg.cpp

HEADERS  += stone.hpp \
    rubotcp.hpp \
    log.hpp \
    msgs/msg.hpp

FORMS    += stone.ui

RESOURCES += \
    stone.qrc

CONFIG += console
