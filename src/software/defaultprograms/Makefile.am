#Generata binary file 
lib_LTLIBRARIES  = libukui-defaultprograms.la

#gcc -wall: displays all the errors and warning information when compiling
#gcc -g: add the debugging code when compiling 
COMM_CFS = -Wall -g

#Add the dependent source file for libdefaultprograms.la
libukui_defaultprograms_la_SOURCES = kylin-defaultprograms-interface.c \
	$(NULL)

#The header files that need to be installed
include_HEADERS= kylin-defaultprograms-interface.h \
	$(NULL)

#Additional C compiler flags
libukui_defaultprograms_la_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
libukui_defaultprograms_la_LDFLAGS= \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)
