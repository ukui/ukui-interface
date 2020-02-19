#Generata binary file 
lib_LTLIBRARIES  = libukui-datesetting.la

#gcc -wall: displays all the errors and warning information when compiling
#gcc -g: add the debugging code when compiling 
COMM_CFS = -Wall -g

#Add the dependent source file for libukui-datesetting.la
libukui_datesetting_la_SOURCES = kylin-date-interface.c \
	$(NULL)

#The header files that need to be installed
include_HEADERS= kylin-date-interface.h \
	$(NULL)

#Additional C compiler flags
libukui_datesetting_la_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
libukui_datesetting_la_LDFLAGS= \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

