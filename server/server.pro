TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
SOURCES += src/main.cpp \
    src/file_dao.cpp \
    src/oracle_dao.cpp \
    src/server_socket.cpp \
    src/store_thread.cpp \
    src/db_exception.cpp \
    src/server_exception.cpp \
    src/socket_exception.cpp \
    src/thread_exception.cpp \
    src/log_queue.cpp \
    src/data.cpp \
    src/log_dao.cpp \
    src/server.cpp \
    src/client_thread.cpp \
    src/base_thread.cpp

HEADERS += header/log_dao.h \
    header/file_dao.h \
    header/oracle_dao.h \
    header/store_thread.h \
    header/server_socket.h \
    header/server.h \
    header/socket_exception.h \
    header/thread_exception.h \
    header/db_exception.h \
    header/data.h \
    header/server_exception.h \
    header/log_queue.h \
    header/client_thread.h \
    header/base_thread.h

PTHREAD_LIB = /usr/lib/x86_64-linux-gnu

LIBS += \
     -L$$PTHREAD_LIB \
     -lpthread

INCLUDEPATH += \
    /usr/include/
