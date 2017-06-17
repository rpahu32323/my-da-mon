# source groupings
RPAHU_DOCKAPPS			=	src/rpahu/dockapps/apps/MyDAMon.h		src/rpahu/dockapps/apps/MyDAMon.cpp

RPAHU_DOCKAPPS_WIDGETS	=	src/rpahu/dockapps/widgets/Widget.h		src/rpahu/dockapps/widgets/Widget.cpp \
							src/rpahu/dockapps/widgets/Label.h		src/rpahu/dockapps/widgets/Label.cpp
							
RPAHU_DOCKAPPS_MONITORS	=	src/rpahu/dockapps/monitors/Monitor.h	src/rpahu/dockapps/monitors/Monitor.cpp \
							src/rpahu/dockapps/monitors/Group.h		src/rpahu/dockapps/monitors/Group.cpp

RPAHU_UTILS				=	src/rpahu/utils/Base.h					src/rpahu/utils/Base.cpp

# binaries to compile
bin_PROGRAMS = bin/my-da-mon

# hellow world sources
bin_my_da_mon_SOURCES	=	src/Main.cpp \
							$(RPAHU_DOCKAPPS) \
							$(RPAHU_DOCKAPPS_WIDGETS) \
							$(RPAHU_DOCKAPPS_MONITORS) \
							$(RPAHU_UTILS)
							
# compiler flags
bin_my_da_mon_CPPFLAGS	=	$(GTKMM_CFLAGS)
bin_my_da_mon_LDADD		=	$(GTKMM_LIBS)
							