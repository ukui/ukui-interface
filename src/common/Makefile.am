#Generata binary file 
lib_LTLIBRARIES  = libukui-print.la libukui-gsettings.la libukui-common.la

#gcc -wall: displays all the errors and warning information when compiling
#gcc -g: add the debugging code when compiling 
COMM_CFS = -Wall -g

#Add the dependent source file for libukui-common.la
libukui_common_la_SOURCES = kylin-common.c \
    kylin-ini.c \
	$(NULL)

#Additional C compiler flags
libukui_common_la_CFLAGS=  $(COMM_CFS) \
        $(NULL)

#Additional link objects
libukui_common_la_LDFLAGS= \
        $(NULL)

#Add the dependent source file for libukui-print.la
libukui_print_la_SOURCES = kylin-print.c \
	$(NULL)

#Add the dependent source file for libukui-gsettings.la
libukui_gsettings_la_SOURCES = kylin-gsettings-set.c \
	$(NULL)

#The header files that need to be installed
include_HEADERS= \
	kylin-common.h \
	kylin-print.h \
	kylin-gsettings-set.h \
	$(NULL)

#Additional C compiler flags
libukui_gsettings_la_CFLAGS=  $(COMM_CFS) \
        $(GLIB_2_CFLAGS) $(GIO_2_CFLAGS) $(GIO_UNIX_2_CFLAGS) \
        $(NULL)

#Additional link objects
libukui_gsettings_la_LDFLAGS= \
        $(GLIB_2_LIBS) $(GIO_2_LIBS) $(GIO_UNIX_2_LIBS) \
        $(NULL)
