TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../main.cpp \
    ../processora.cpp \
    ../ProcessorB.cpp \
    ../ProcessorC.cpp \
    ../Factory.cpp \
    ../filerw.cpp

HEADERS += \
    ../processora.h \
    ../ProcessorB.h \
    ../ProcessorC.h \
    ../Factory.h \
    ../filerw.h \
    ../IProcessor.h

