COMM_PRINT= -L$(top_srcdir)/src/common -lprint
COMM_GSETTINGS= -L$(top_srcdir)/src/common -lgsettings

#generate the .c and .h file which used by client and server side by XML file
#$(top_srcdir) represents the top-level directory of the project
DESC_XML = $(top_srcdir)/data/cn.kylinos.font.xml
GENERATED_CH = font-generated

font-generated.h font-generated.c: $(DESC_XML)
	gdbus-codegen --interface-prefix cn.kylinos. --generate-c-code $(GENERATED_CH) $(DESC_XML)

#Generata binary file 
lib_LTLIBRARIES  = libfontclient.la

#gcc -wall: displays all the errors and warning information when compiling
#gcc -g: add the debugging code when compiling 
COMM_CFS = -Wall -g

#Add the dependent source file for libfontclient.la
#font-generated.c must be front of kylin-font-interface.c
libfontclient_la_SOURCES = \
	font-generated.c kylin-font-interface.c \
	$(NULL)

#The header files that need to be installed
include_HEADERS= kylin-font-interface.h \
	$(NULL)

#Additional C compiler flags
libfontclient_la_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
libfontclient_la_LDFLAGS= $(COMM_PRINT) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

#Generata binary file
bin_PROGRAMS = fontserver

#Add the dependent source file for fontserver
fontserver_SOURCES = \
	font-generated.h font-generated.c \
	kylin-font-server.c \
	$(NULL)

#Additional C compiler flags
fontserver_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
fontserver_LDFLAGS= $(COMM_PRINT) $(COMM_GSETTINGS) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)
