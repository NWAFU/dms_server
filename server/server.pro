TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
SOURCES += src/main.cpp \
    src/file_dao.cpp \
    src/log_dao.cpp \
    src/oracle_dao.cpp \
    src/server_socket.cpp \
    src/store_thread.cpp   \
    src/oracle_dao.cpp

HEADERS += header/log_dao.h \
    header/file_dao.h \
    header/oracle_dao.h \
    header/store_thread.h \
    header/server_socket.h \
    header/server.h
    header/server_exception.h
