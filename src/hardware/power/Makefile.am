COMM_PRINT= -L$(top_srcdir)/src/common -lukui-print
COMM_GSETTINGS= -L$(top_srcdir)/src/common -lukui-gsettings

#generate the .c and .h file which used by client and server side by XML file
#$(top_srcdir) represents the top-level directory of the project
POWER_XML = $(top_srcdir)/data/cn.kylinos.power.xml
GENERATED_POW = power-generated

SCREEN_XML = $(top_srcdir)/data/cn.kylinos.screensaver.xml
GENERATED_SCREEN = screensaver-generated

SESS_XML = $(top_srcdir)/data/cn.kylinos.session.xml
GENERATED_SESS = session-generated

power-generated.h power-generated.c: $(POWER_XML)
	gdbus-codegen --interface-prefix cn.kylinos. --generate-c-code $(GENERATED_POW) $(POWER_XML)

screensaver-generated.h screensaver-generated.c: $(SCREEN_XML)
	gdbus-codegen --interface-prefix cn.kylinos. --generate-c-code $(GENERATED_SCREEN) $(SCREEN_XML)

session-generated.h session-generated.c: $(SESS_XML)
	gdbus-codegen --interface-prefix cn.kylinos. --generate-c-code $(GENERATED_SESS) $(SESS_XML)

#Generata binary file 
lib_LTLIBRARIES  = libukui-powerclient.la libukui-screensaverclient.la libukui-sessionclient.la

#gcc -wall: displays all the errors and warning information when compiling
#gcc -g: add the debugging code when compiling 
COMM_CFS = -Wall -g

#Add the dependent source file for libpowerclient.la
#power-generated.c must be front of kylin-power-interface.c
libukui_powerclient_la_SOURCES = power-generated.c kylin-power-interface.c \
	$(NULL)

#The header files that need to be installed
include_HEADERS= kylin-power-interface.h \
	kylin-screensaver-interface.h \
	kylin-session-interface.h \
	$(NULL)

#Additional C compiler flags
libukui_powerclient_la_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
libukui_powerclient_la_LDFLAGS= $(COMM_PRINT) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

#Add the dependent source file for libscreensaverclient.la
#screensaver-generated.c must be front of kylin-screensaver-interface.c
libukui_screensaverclient_la_SOURCES = screensaver-generated.c kylin-screensaver-interface.c \
	$(NULL)

#Additional C compiler flags
libukui_screensaverclient_la_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
libukui_screensaverclient_la_LDFLAGS= $(COMM_PRINT) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

#Add the dependent source file for libsessionclient.la
#session-generated.c must be front of kylin-session-interface.c
libukui_sessionclient_la_SOURCES = session-generated.c kylin-session-interface.c \
	$(NULL)

#Additional C compiler flags
libukui_sessionclient_la_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
libukui_sessionclient_la_LDFLAGS= $(COMM_PRINT) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

#Generata binary file
bin_PROGRAMS = ukui-powerserver ukui-screensaverserver ukui-sessionserver

#Add the dependent source file for powerserver
ukui_powerserver_SOURCES = \
	power-generated.h power-generated.c \
	kylin-power-server.c \
	$(NULL)

#Additional C compiler flags
ukui_powerserver_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
ukui_powerserver_LDFLAGS= $(COMM_PRINT) $(COMM_GSETTINGS) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

#Add the dependent source file for screensaverserver
ukui_screensaverserver_SOURCES = \
	screensaver-generated.h screensaver-generated.c \
	kylin-screensaver-server.c \
	$(NULL)

#Additional C compiler flags
ukui_screensaverserver_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
ukui_screensaverserver_LDFLAGS= $(COMM_PRINT) $(COMM_GSETTINGS) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)

#Add the dependent source file for sessionserver
ukui_sessionserver_SOURCES = \
	session-generated.h session-generated.c \
	kylin-session-server.c \
	$(NULL)

#Additional C compiler flags
ukui_sessionserver_CFLAGS=  $(COMM_CFS) \
	$(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
	$(NULL)

#Additional link objects
ukui_sessionserver_LDFLAGS= $(COMM_PRINT) $(COMM_GSETTINGS) \
	$(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
	$(NULL)
