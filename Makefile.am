# binaries to compile
bin_PROGRAMS = bin/my-da-mon

# source groupings
RPAHU_DOCKAPPS			=	src/rpahu/dockapps/apps/MyDAMon.h		src/rpahu/dockapps/apps/MyDAMon.cpp

RPAHU_UTILS				=	src/rpahu/utils/Base.h					src/rpahu/utils/Base.cpp

# hellow world sources
bin_my_da_mon_SOURCES	=	src/Main.cpp \
							$(RPAHU_DOCKAPPS) \
							$(RPAHU_UTILS)
							
# compiler flags
bin_my_da_mon_CPPFLAGS	=	$(GTKMM_CFLAGS)
bin_my_da_mon_LDADD		=	$(GTKMM_LIBS)
							