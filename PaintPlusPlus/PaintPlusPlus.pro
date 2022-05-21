QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

LIBS += -pthread

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CanvasDialog/createcanvasdialog.cpp \
    DataStructures/bfs.cpp \
    DataStructures/queue.cpp \
    Tools/bmp.cpp \
    Tools/circle.cpp \
    Tools/paintfill.cpp \
    Tools/pen.cpp \
    Tools/pencil.cpp \
    Tools/square.cpp \
    Tools/colorpicker.cpp \
    main.cpp \
    canvasimage.cpp \
    mainwindow.cpp \
    pixel.cpp \
    DataStructures/linkedlist.cpp \
    DataStructures/node.cpp \
    tools.cpp

HEADERS += \
    CanvasDialog/createcanvasdialog.h \
    DataStructures/bfs.h \
    DataStructures/queue.h \
    Tools/bmp.h \
    Tools/circle.h \
    Tools/paintfill.h \
    Tools/pen.h \
    Tools/pencil.h \
    Tools/square.h \
    Tools/colorpicker.h \
    mainwindow.h \
    canvasimage.h \
    pixel.h \
    DataStructures/linkedlist.h \
    DataStructures/node.h \
    tools.h

FORMS += \
    CanvasDialog/createcanvasdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
