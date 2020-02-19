lib_LTLIBRARIES  = libukui-subversion.la

COMM_CFS = -Wall -g -fPIC

libukui_subversion_la_SOURCES = kylin-version-interface.cpp \
	$(NULL)

include_HEADERS= \
	kylin-version-interface.h \
	$(NULL)

libukui_subversion_la_CPPFLAGS= $(COMM_CFS) \
	$(QT5CORE_CFLAGS) \
	$(NULL)

libukui_subversion_la_LDFLAGS= \
	$(QT5CORE_LIBS) \
	$(NULL)
