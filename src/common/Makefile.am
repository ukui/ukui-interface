#Generata binary file 
lib_LTLIBRARIES  = libprint.la libgsettings.la

#gcc -wall: displays all the errors and warning information when compiling
#gcc -g: add the debugging code when compiling 
COMM_CFS = -Wall -g

#Add the dependent source file for libprint.la
libprint_la_SOURCES = kylin-print.c \
	$(NULL)

#Add the dependent source file for libgsettings.la
libgsettings_la_SOURCES = kylin-gsettings-set.c \
	$(NULL)

#The header files that need to be installed
include_HEADERS= \
	kylin-print.h \
	kylin-gsettings-set.h \
	$(NULL)

#Additional C compiler flags
libgsettings_la_CFLAGS=  $(COMM_CFS) \
        $(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
        $(NULL)

#Additional link objects
libgsettings_la_LDFLAGS= \
        $(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
        $(NULL)
