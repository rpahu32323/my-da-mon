# init autoconf
AC_INIT( [my-da-mon], [0.1] )

# init automake
#		foreign - do not require standard files
#		subdir-objs - put the .o files in the subdirectories
AM_INIT_AUTOMAKE( [foreign subdir-objects] )

# search for local macaros (needed for c++14)
AC_CONFIG_MACRO_DIRS([macros])

# check for c++ compiler
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_14

# check for libary functions
AC_CHECK_FUNCS( [localtime_r strerror] )

# check for gtkmm
PKG_CHECK_MODULES( [GTKMM], [gtkmm-3.0 >= 3.8.0] )

# make the make file
AC_CONFIG_FILES( [Makefile] )

# create the files
AC_OUTPUT