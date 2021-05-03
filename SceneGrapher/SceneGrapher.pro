QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CircleGraph/circlegraph.cpp \
    CircleGraph/circlelocator.cpp \
    CircleGraph/circlenode.cpp \
    CircleGraph/edge.cpp \
    GraphWidget/statemachine.cpp \
    main.cpp \
    GraphWidget/graphwidget.cpp \
    mainwindow.cpp

HEADERS += \
    CircleGraph/circlegraph.h \
    CircleGraph/circlelocator.h \
    CircleGraph/circlenode.h \
    CircleGraph/edge.h \
    GraphWidget/graphwidget.h \
    GraphWidget/statemachine.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
