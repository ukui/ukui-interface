#Generata binary file 
lib_LTLIBRARIES  = libusersetting.la

#gcc -wall: displays all the errors and warning information when compiling
#gcc -g: add the debugging code when compiling 
COMM_CFS = -Wall -g

#Add the dependent source file for libusersetting.la
libusersetting_la_SOURCES = kylin-user-interface.c \
	$(NULL)

#The header files that need to be installed
include_HEADERS= kylin-user-interface.h \
	$(NULL)

#Additional C compiler flags
libusersetting_la_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
libusersetting_la_LDFLAGS= -lcrypt \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

