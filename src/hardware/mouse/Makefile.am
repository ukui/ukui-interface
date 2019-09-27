COMM_PRINT= -L$(top_srcdir)/src/common -lprint
COMM_GSETTINGS= -L$(top_srcdir)/src/common -lgsettings

#generate the .c and .h file which used by client and server side by XML file
#$(top_srcdir) represents the top-level directory of the project
DESC_XML = $(top_srcdir)/data/cn.kylinos.mouse.xml
GENERATED_CH = mouse-generated

mouse-generated.h mouse-generated.c: $(DESC_XML)
	gdbus-codegen --interface-prefix cn.kylinos. --generate-c-code $(GENERATED_CH) $(DESC_XML)

#Generata binary file 
lib_LTLIBRARIES  = libmouseclient.la

#gcc -wall: displays all the errors and warning information when compiling
#gcc -g: add the debugging code when compiling 
COMM_CFS = -Wall -g

#Add the dependent source file for libmouseclient.la
#mouse-generated.c must be front of kylin-mouse-interface.c
libmouseclient_la_SOURCES = mouse-generated.c kylin-mouse-interface.c \
	$(NULL)

#The header files that need to be installed
include_HEADERS= kylin-mouse-interface.h \
	$(NULL)

#Additional C compiler flags
libmouseclient_la_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
libmouseclient_la_LDFLAGS= $(COMM_PRINT) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

#Generata binary file
bin_PROGRAMS = mouseserver

#Add the dependent source file for mouseserver
mouseserver_SOURCES = \
	mouse-generated.h mouse-generated.c \
	kylin-mouse-server.c \
	$(NULL)

#Additional C compiler flags
mouseserver_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
mouseserver_LDFLAGS= $(COMM_PRINT) $(COMM_GSETTINGS) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)
