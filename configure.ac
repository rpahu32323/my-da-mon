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
AC_PROG_CC
AX_CXX_COMPILE_STDCXX_14

# make the make file
AC_CONFIG_FILES( [Makefile] )

# create the files
AC_OUTPUT