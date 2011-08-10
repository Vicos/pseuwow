## Process this file with automake to produce Makefile.in
SUBDIRS = DefScript Realm World

if IMPLEMENT_GUI
SUBDIRS += GUI
endif

AM_CPPFLAGS =   -I$(top_builddir)/src/Client \
                -I$(top_builddir)/src/shared \
                -I$(top_builddir)/src/Client/DefScript \
                -I$(top_builddir)/src/Client/World \
                -I$(top_builddir)/src/Client/Realm \
                -I$(top_builddir)/src/dep/include \
                -Wall

## Build pseuwow
bin_PROGRAMS = pseuwow
pseuwow_SOURCES = 	DefScriptInterface.cpp\
			        MemoryDataHolder.cpp\
			        RemoteController.cpp\
			        ControlSocket.cpp\
			        main.cpp\
			        PseuWoW.cpp\
			        SCPDatabase.cpp\
			        Realm/RealmSession.cpp\
			        Realm/RealmSocket.cpp\
			        World/WorldSocket.cpp\
			        World/UpdateData.cpp\
			        World/MapMgr.cpp

pseuwow_LDADD =     ../shared/libshared.a \
				    ../shared/Auth/libauth.a \
				    ../shared/Network/libnetwork.a \
				    DefScript/libdefscript.a \
				    World/libworld.a \
				    ../dep/src/zlib/libzlib.a \
				    ../dep/src/zthread/libZThread.a \
				    ../dep/src/StormLib/libstormlib.a \
				    -lbz2

if HAVE_READLINE
pseuwow_LDADD 	+=	-lreadline
pseuwow_SOURCES +=	Cli_readline.cpp
else
pseuwow_SOURCES +=	Cli.cpp
endif

if IMPLEMENT_GUI
pseuwow_LDADD +=    GUI/libgui.a \
				    $(IRRKLANG_LIB) \
				    ../dep/lib/linux-gcc/libIrrlicht.a
endif

pseuwow_LDFLAGS =-pthread 