QT       += core gui multimedia multimediawidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    View/Components/pushbutton.cpp \
    View/SubView/ailearningwidget.cpp \
    View/SubView/coursecenterwidget.cpp \
    View/SubView/distancelearningwidget.cpp \
    View/interactiveteachingwidget.cpp \
    View/learningresourceswidget.cpp \
    View/menubarwidget.cpp \
    View/onlinetestwidget.cpp \
    View/simulationexperimentwidget.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    View/Components/pushbutton.h \
    View/SubView/ailearningwidget.h \
    View/SubView/coursecenterwidget.h \
    View/SubView/distancelearningwidget.h \
    View/interactiveteachingwidget.h \
    View/learningresourceswidget.h \
    View/menubarwidget.h \
    View/onlinetestwidget.h \
    View/simulationexperimentwidget.h \
    headerfile.h \
    mainwindow.h \

FORMS += \
#    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
