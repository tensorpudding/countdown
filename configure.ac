AC_INIT([countdown], [0.1], [tensorpuddin@devio.us])
AM_INIT_AUTOMAKE([-Wall -Werror])
AC_PROG_CC
AC_CONFIG_HEADERS([config.h])
LT_INIT
PKG_CHECK_MODULES([gtk], [gtk+-3.0 >= 3.0.0])
PKG_CHECK_MODULES([libnotify], [libnotify])
AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
