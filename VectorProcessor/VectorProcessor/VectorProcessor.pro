#-------------------------------------------------
#
# Project created by QtCreator 2017-10-16T12:33:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VectorProcessor
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    alu.cpp \
    decoder_execute_register.cpp \
    decoder.cpp \
    execute.cpp \
    fetch_decoder_register.cpp \
    fetch.cpp \
    imageManager.cpp \
    memory.cpp \
    parser.cpp \
    register_exe_mem.cpp \
    register_mem_wb.cpp \
    vectorProcessor.cpp \
    write_back.cpp \
    main.cpp

HEADERS  += mainwindow.h \
    alu.h \
    decoder_execute_register.h \
    decoder.h \
    execute.h \
    fetch_decoder_register.h \
    fetch.h \
    imageManager.h \
    memory.h \
    parser.h \
    register_exe_mem.h \
    register_mem_wb.h \
    vectorProcessor.h \
    write_back.h

FORMS    += mainwindow.ui

DISTFILES += \
    main \
    VectorProcessor.pro.user \
    cat.png \
    cat.data
