#-------------------------------------------------
#
# Project created by QtCreator 2017-05-10T16:15:06
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    mainscene.cpp \
    start_btn.cpp \
    attack_btn.cpp \
    repair_btn.cpp \
    factory_btn.cpp \
    change_btn.cpp \
    supply_btn.cpp \
    group_btn.cpp \
    select_btn.cpp \
    backtomain_btn.cpp \
    smallchange_btn.cpp \
    smallrepair_btn.cpp \
    smallfactory_btn.cpp \
    smallsupply_btn.cpp \
    cardsetting.cpp \
    confirmusername.cpp \
    right_btn.cpp \
    left_btn.cpp

HEADERS  += mainwindow.h \
    mainscene.h \
    start_btn.h \
    attack_btn.h \
    repair_btn.h \
    factory_btn.h \
    change_btn.h \
    supply_btn.h \
    group_btn.h \
    select_btn.h \
    backtomain_btn.h \
    smallchange_btn.h \
    smallrepair_btn.h \
    smallfactory_btn.h \
    smallsupply_btn.h \
    cardsetting.h \
    confirmusername.h \
    right_btn.h \
    left_btn.h

FORMS    += mainwindow.ui

RESOURCES +=
