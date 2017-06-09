TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
SOURCES += src/main.cpp \
    src/file_dao.cpp \
    src/log_dao.cpp \
    src/oracle_dao.cpp \
    src/server_exception.cpp \
    src/socket_exception.cpp \
    src/thread_exception.cpp \
    src/db_exception.cpp
HEADERS += header/server_exception.h \
    header/log_dao.h \
    header/file_dao.h \
    header/oracle_dao.h \
    header/store_thread.h \
    header/server_socket.h \
    header/server.h \
    header/socket_exception.h \
    header/thread_exception.h \
    header/db_exception.h
