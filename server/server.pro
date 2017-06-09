TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
SOURCES += main.cpp \
    ../file_dao.cpp \
    ../log_dao.cpp \
    ../oracle_dao.cpp
HEADERS += exception/server_exception.h \
    ../Server.h \
    ../ServerSocket.h \
    ../StoreThread.h \
    ../log_dao.h \
    ../file_dao.h \
    ../oracle_dao.h
OTHER_FILES += 
