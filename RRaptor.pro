#-------------------------------------------------
#
# Project created by QtCreator 2014-04-28T16:22:32
#
#-------------------------------------------------

QT       += core gui
QT       += core gui opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RRaptor
TEMPLATE = app


SOURCES += main.cpp\
        rraptor_app.cpp \
    openGL_Widget.cpp \
    user_controle.cpp

HEADERS  += rraptor_app.h \
    openGL_Widget.h \
    user_controle.h

FORMS    += rraptor_app.ui \
    user_controle.ui
