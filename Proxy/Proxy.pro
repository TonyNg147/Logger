TEMPLATE = lib
QT+=dbus core
TARGET=Proxy
DESTDIR= $$OUT_PWD/../../Delivery/libraries
INCLUDEPATH += $$PWD/../Logger/LogStreamer
LIBS+= -L$$OUT_PWD/../../Delivery/libraries -lLogger
SOURCES+= \
        ServiceInterface.cpp \
        ServiceAdapter.cpp \
        Init.cpp
HEADERS+=\
        ServiceInterface.h \
        ServiceAdapter.h \
        Data.h \
        Init.h