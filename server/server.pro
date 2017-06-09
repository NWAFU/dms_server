TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/main.cpp \
    src/file_dao.cpp \
    src/log_dao.cpp \
    src/oracle_dao.cpp
    

HEADERS += header/server_exception.h \
    header/Server.h \
    header/ServerSocket.h \
    header/StoreThread.h \
    header/log_dao.h \
    header/file_dao.h \
    header/oracle_dao.h

