AM_CPPFLAGS = -Wall -Werror $(gtk_CFLAGS) -I/usr/include/libnotify
bin_PROGRAMS = countdown
countdown_LDADD = $(gtk_LIBS) $(libnotify_LIBS)
countdown_SOURCES = main.c countdown.c countdown.h
