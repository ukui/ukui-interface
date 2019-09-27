COMM_PRINT= -L$(top_srcdir)/src/common -lprint
COMM_GSETTINGS= -L$(top_srcdir)/src/common -lgsettings

#generate the .c and .h file which used by client and server side by XML file
#$(top_srcdir) represents the top-level directory of the project
DESC_XML = $(top_srcdir)/data/cn.kylinos.marcogeneral.xml
GENERATED_CH = marcogeneral-generated

marcogeneral-generated.h marcogeneral-generated.c: $(DESC_XML)
	gdbus-codegen --interface-prefix cn.kylinos. --generate-c-code $(GENERATED_CH) $(DESC_XML)

#Generata binary file 
lib_LTLIBRARIES  = libmarcogeneralclient.la

#gcc -wall: displays all the errors and warning information when compiling
#gcc -g: add the debugging code when compiling 
COMM_CFS = -Wall -g

#Add the dependent source file for libmarcogeneralclient.la
#marcogeneral-generated.c must be front of kylin-marcogeneral-interface.c
libmarcogeneralclient_la_SOURCES = marcogeneral-generated.c kylin-marcogeneral-interface.c \
	$(NULL)

#The header files that need to be installed
include_HEADERS= kylin-marcogeneral-interface.h \
	$(NULL)

#Additional C compiler flags
libmarcogeneralclient_la_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
libmarcogeneralclient_la_LDFLAGS= $(COMM_PRINT) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

#Generata binary file
bin_PROGRAMS = marcogeneralserver

#Add the dependent source file for marcogeneralserver
marcogeneralserver_SOURCES = \
	marcogeneral-generated.h marcogeneral-generated.c \
	kylin-marcogeneral-server.c \
	$(NULL)

#Additional C compiler flags
marcogeneralserver_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
marcogeneralserver_LDFLAGS= $(COMM_PRINT) $(COMM_GSETTINGS) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)
