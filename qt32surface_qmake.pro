QT       += core gui

QT += widgets
QT += datavisualization

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

#FOLDER = /home/joe/Qt5.12.12/5.12.12/gcc_64
#LIBS += -L$$FOLDER/lib -lQt5DataVisualization
#INCLUDEPATH += $$FOLDER/include

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

message(isi $$OUT_PWD - $$PWD)
