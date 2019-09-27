COMM_PRINT= -L$(top_srcdir)/src/common -lprint
COMM_GSETTINGS= -L$(top_srcdir)/src/common -lgsettings

#generate the .c and .h file which used by client and server side by XML file
#$(top_srcdir) represents the top-level directory of the project
GENE_XML = $(top_srcdir)/data/cn.kylinos.xkbgeneral.xml
INTE_XML = $(top_srcdir)/data/cn.kylinos.interface.xml
KEY_XML = $(top_srcdir)/data/cn.kylinos.keyboard.xml

GENERATED_GENE = xkbgeneral-generated
GENERATED_INTE = interface-generated
GENERATED_KEY = keyboard-generated

xkbgeneral-generated.h xkbgeneral-generated.c: $(GENE_XML)
	gdbus-codegen --interface-prefix cn.kylinos --generate-c-code $(GENERATED_GENE) $(GENE_XML)

interface-generated.h interface-generated.c: $(INTE_XML)
	gdbus-codegen --interface-prefix cn.kylinos. --generate-c-code $(GENERATED_INTE) $(INTE_XML)

keyboard-generated.h keyboard-generated.c: $(KEY_XML)
	gdbus-codegen --interface-prefix cn.kylinos. --generate-c-code $(GENERATED_KEY) $(KEY_XML)


#Generata binary file 
lib_LTLIBRARIES  = libxkbgeneralclient.la libinterfaceclient.la libkeyboardclient.la

#gcc -wall: displays all the errors and warning information when compiling
#gcc -g: add the debugging code when compiling 
COMM_CFS = -Wall -g

#Add the dependent source file for libxkbgeneralclient.la
#xkbgeneral-generated.c must be front of kylin-xkbgeneral-interface.c
libxkbgeneralclient_la_SOURCES = xkbgeneral-generated.c kylin-xkbgeneral-interface.c \
	$(NULL)

#The header files that need to be installed
include_HEADERS= kylin-xkbgeneral-interface.h \
	kylin-interface-interface.h \
	kylin-keyboard-interface.h \
	$(NULL)

#Additional C compiler flags
libxkbgeneralclient_la_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
libxkbgeneralclient_la_LDFLAGS= $(COMM_PRINT) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

#Add the dependent source file for libinterfaceclient.la
#interface-generated.c must be front of kylin-interface-interface.c
libinterfaceclient_la_SOURCES = interface-generated.c kylin-interface-interface.c \
	$(NULL)

#Additional C compiler flags
libinterfaceclient_la_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
libinterfaceclient_la_LDFLAGS= $(COMM_PRINT) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

#Add the dependent source file for libkeyboardclient.la
#keyboard-generated.c must be front of kylin-keyboard-interface.c
libkeyboardclient_la_SOURCES = keyboard-generated.c kylin-keyboard-interface.c \
	$(NULL)

#Additional C compiler flags
libkeyboardclient_la_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
libkeyboardclient_la_LDFLAGS= $(COMM_PRINT) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

#Generata binary file
bin_PROGRAMS = xkbgeneralserver interfaceserver keyboardserver

#Add the dependent source file for xkbgeneralserver
xkbgeneralserver_SOURCES = \
	xkbgeneral-generated.h xkbgeneral-generated.c \
	kylin-xkbgeneral-server.c \
	$(NULL)

#Additional C compiler flags
xkbgeneralserver_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
xkbgeneralserver_LDFLAGS= $(COMM_PRINT) $(COMM_GSETTINGS) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

#Add the dependent source file for interfaceserver
interfaceserver_SOURCES = \
	interface-generated.h interface-generated.c \
	kylin-interface-server.c \
	$(NULL)

#Additional C compiler flags
interfaceserver_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
interfaceserver_LDFLAGS= $(COMM_PRINT) $(COMM_GSETTINGS) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

#Add the dependent source file for keyboardserver
keyboardserver_SOURCES = \
	keyboard-generated.h keyboard-generated.c \
	kylin-keyboard-server.c \
	$(NULL)

#Additional C compiler flags
keyboardserver_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
keyboardserver_LDFLAGS= $(COMM_PRINT) $(COMM_GSETTINGS) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)
