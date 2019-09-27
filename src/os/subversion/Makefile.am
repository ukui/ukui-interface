lib_LTLIBRARIES  = libsubversion.la

COMM_CFS = -Wall -g -fPIC

libsubversion_la_SOURCES = kylin-version-interface.cpp \
	$(NULL)

include_HEADERS= \
	kylin-version-interface.h \
	$(NULL)

libsubversion_la_CPPFLAGS= $(COMM_CFS) \
	$(QT5CORE_CFLAGS) \
	$(NULL)

libsubversion_la_LDFLAGS= \
	$(QT5CORE_LIBS) \
	$(NULL)
