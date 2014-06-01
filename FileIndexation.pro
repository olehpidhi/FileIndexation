#-------------------------------------------------
#
# Project created by QtCreator 2014-05-11T00:37:52
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FileIndexation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    FileInfo.cpp \
    threading.cpp \
    indexation.cpp \
    filestablemodel.cpp

HEADERS  += mainwindow.h \
    FileInfo.h \
    Serializer.h \
    threading.h \
    indexation.h \
    filestablemodel.h

FORMS    += mainwindow.ui
