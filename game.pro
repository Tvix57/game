QT       += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 file_copies

COPIES += database

database.files = $$files(data/image_DB.sqlite3)
database.path = $$OUT_PWD
#win32 {


#CONFIG(debug, debug|release) {
#    TARGET = LPSEngined
#    TYPE = debug
#    database.path +=/debug/
#} else {
#    database.path +=/release/
#}
#}
#macx {
#    database.path = $$OUT_PWD
#}


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dbmanager.cpp \
    gamearea.cpp \
    main.cpp \
    gamewindow.cpp \
    namewindow.cpp \
    profilemanager.cpp \
    startwindow.cpp

HEADERS += \
    dbmanager.h \
    gamearea.h \
    gamewindow.h \
    namewindow.h \
    profilemanager.h \
    startwindow.h

FORMS += \
    gamewindow.ui \
    namewindow.ui \
    startwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img_res.qrc
