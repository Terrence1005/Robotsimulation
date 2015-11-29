#-------------------------------------------------
#
# Project created by QtCreator 2015-11-18T14:31:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RobotGui
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        robotgui.cpp \
    robot.cc \
    datalayer.cc

HEADERS  += robotgui.h \
    robot.hh \
    datalayer.hh

FORMS    += robotgui.ui
