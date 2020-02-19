COMM_PRINT= -L$(top_srcdir)/src/common -lukui-print
COMM_GSETTINGS= -L$(top_srcdir)/src/common -lukui-gsettings

#generate the .c and .h file which used by client and server side by XML file
#$(top_srcdir) represents the top-level directory of the project
DESC_XML = $(top_srcdir)/data/cn.kylinos.desktop.xml
GENERATED_CH = desktop-generated

desktop-generated.h desktop-generated.c: $(DESC_XML)
	gdbus-codegen --interface-prefix cn.kylinos. --generate-c-code $(GENERATED_CH) $(DESC_XML)

#Generata binary file 
lib_LTLIBRARIES  = libukui-desktopclient.la

#gcc -wall: displays all the errors and warning information when compiling
#gcc -g: add the debugging code when compiling 
COMM_CFS = -Wall -g

#Add the dependent source file for libdesktopclient.la
#desktop-generated.c must be front of kylin-desktop-interface.c
libukui_desktopclient_la_SOURCES = desktop-generated.c kylin-desktop-interface.c \
	$(NULL)

#The header files that need to be installed
include_HEADERS= kylin-desktop-interface.h \
	$(NULL)

#Additional C compiler flags
libukui_desktopclient_la_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
libukui_desktopclient_la_LDFLAGS= $(COMM_PRINT) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

#Generata binary file
bin_PROGRAMS = ukui-desktopserver

#Add the dependent source file for desktopserver
ukui_desktopserver_SOURCES = \
	desktop-generated.h desktop-generated.c \
	kylin-desktop-server.c \
	$(NULL)

#Additional C compiler flags
ukui_desktopserver_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
ukui_desktopserver_LDFLAGS= $(COMM_PRINT) $(COMM_GSETTINGS) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)
