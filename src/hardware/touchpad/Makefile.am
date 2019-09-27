COMM_PRINT= -L$(top_srcdir)/src/common -lprint
COMM_GSETTINGS= -L$(top_srcdir)/src/common -lgsettings

#generate the .c and .h file which used by client and server side by XML file
#$(top_srcdir) represents the top-level directory of the project
DESC_XML = $(top_srcdir)/data/cn.kylinos.touchpad.xml
GENERATED_CH = touchpad-generated

touchpad-generated.h touchpad-generated.c: $(DESC_XML)
	gdbus-codegen --interface-prefix cn.kylinos. --generate-c-code $(GENERATED_CH) $(DESC_XML)

#Generata binary file 
lib_LTLIBRARIES  = libtouchpadclient.la

#gcc -wall: displays all the errors and warning information when compiling
#gcc -g: add the debugging code when compiling 
COMM_CFS = -Wall -g

#Add the dependent source file for libtouchpadclient.la
#touchpad-generated.c must be front of kylin-touchpad-interface.c
libtouchpadclient_la_SOURCES = touchpad-generated.c kylin-touchpad-interface.c \
	$(NULL)

#The header files that need to be installed
include_HEADERS= kylin-touchpad-interface.h \
	$(NULL)

#Additional C compiler flags
libtouchpadclient_la_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
libtouchpadclient_la_LDFLAGS= $(COMM_PRINT) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

#Generata binary file
bin_PROGRAMS = touchpadserver

#Add the dependent source file for touchpadserver
touchpadserver_SOURCES = \
	touchpad-generated.h touchpad-generated.c \
	kylin-touchpad-server.c \
	$(NULL)

#Additional C compiler flags
touchpadserver_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
touchpadserver_LDFLAGS= $(COMM_PRINT) $(COMM_GSETTINGS) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)
