TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Factory.cpp \
    filerw.cpp \
    processora.cpp \
    ProcessorB.cpp \
    ProcessorC.cpp

DISTFILES += \
    KaminTestQT.pro.user \
    CMakeLists.txt



HEADERS += \
    Factory.h \
    filerw.h \
    IProcessor.h \
    processora.h \
    ProcessorB.h \
    ProcessorC.h

