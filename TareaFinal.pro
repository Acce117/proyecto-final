TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    Logica/initialData.c \
    Logica/Logica.c \
    Interfaz/Interfaz.c \
    Interfaz/EnterData.c \
    lib/fort.c

HEADERS += \
    Interfaz/Interfaz.h \
    Logica/header.h \
    lib/fort.h

