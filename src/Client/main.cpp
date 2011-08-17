#include <new>

#include "common.h"
#include "main.h"
#include "PseuWoW.h"
#include "MemoryDataHolder.h"
#include "InstanceList.h"


void _HookSignals(void)
{
	signal(SIGINT, _OnSignal);
    signal(SIGQUIT, _OnSignal);
    signal(SIGTERM, _OnSignal);
    signal(SIGABRT, _OnSignal);
    #ifdef _WIN32
    signal(SIGBREAK, _OnSignal);
    #endif
}

void _UnhookSignals(void)
{
    signal(SIGINT, 0);
    signal(SIGQUIT, 0);
    signal(SIGTERM, 0);
    signal(SIGABRT, 0);
    #ifdef _WIN32
    signal(SIGBREAK, 0);
    #endif
}

void _OnSignal(int s)
{
    switch (s)
    {
        case SIGINT:
        case SIGQUIT:
        case SIGTERM:
            InstanceList::get()->quitproc();
            break;
        case SIGABRT:
        #ifndef _DEBUG
        case SIGSEGV:
        #endif
        #ifdef _WIN32
        case SIGBREAK:
        #endif
            InstanceList::get()->abortproc();
            break;
    }
    signal(s, _OnSignal);
}

void _new_handler(void)
{
    logcritical("ERROR: Out of memory!");
    throw;
}

#if PLATFORM == PLATFORM_WIN32 && !defined(_CONSOLE)
int CALLBACK WinMain( IN HINSTANCE hInstance, IN HINSTANCE hPrevInstance, IN LPSTR lpCmdLine, IN int nShowCmd)
{
    main(0, NULL);
}
#endif

int main(int argc, char* argv[])
{
    try
    {
        std::set_new_handler(_new_handler);
        log_prepare("logfile.txt","a");
        logcustom(0,LGREEN,"+----------------------------------+");
        logcustom(0,LGREEN,"| (C) 2006-2010 Snowstorm Software |");
        logcustom(0,LGREEN,"|  http://www.mangosclient.org     |");
        logcustom(0,LGREEN,"+----------------------------------+");
        logcustom(0,GREEN,"Platform: %s",PLATFORM_NAME);
        logcustom(0,GREEN,"Compiler: %s ("COMPILER_VERSION_OUT")",COMPILER_NAME,COMPILER_VERSION);
        logcustom(0,GREEN,"Compiled: %s  %s",__DATE__,__TIME__);

        MemoryDataHolder::Init();
        _HookSignals();
		
        PseuInstanceRunnable *r=new PseuInstanceRunnable();
        ZThread::Thread t(r);
        InstanceList::get()->push(r);
        t.setPriority((ZThread::Priority)2);

        t.wait();

		_UnhookSignals();
        MemoryDataHolder::Shutdown();

        raise(SIGQUIT);
		log_close();
        return 0;
	} 
    catch (...)
    {
        printf("ERROR: Unhandled exception in main thread!\n"); 
        raise(SIGABRT);
        return 1;
    }
}
