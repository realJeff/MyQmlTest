TEMPLATE = app

QT += qml quick widgets
QT += sql

SOURCES += main.cpp \
    mycppclass.cpp \
    mysqlmodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)


DISTFILES += \
    main.qml \
    MainForm.ui.qml \
    Tab01.qml

HEADERS += \
    mycppclass.h \
    mysqlmodel.h
