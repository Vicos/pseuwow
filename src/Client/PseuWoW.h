
#ifndef _PSEUWOW_H
#define _PSEUWOW_H

#include "common.h"
#include "HelperDefs.h"
#include "log.h"
#include "Auth/BigNumber.h"
#include "DefScript/LuaPackage.h"
#include "DefScript/VarSet.h"
#include "Network/SocketHandler.h"
#include "SCPDatabase.h"
#include "GUI/PseuGUI.h"

class RealmSession;
class WorldSession;
class Sockethandler;
class PseuInstanceRunnable;
class CliRunnable;
class RemoteController;

// possible conditions threads can wait for. used for thread synchronisation. extend if needed.
enum InstanceConditions
{
    COND_GUI_INITIALIZED,
    COND_GUI_SCENE_CHANGED,
    COND_GUI_CLOSED,
    COND_MAP_LOADED,

    COND_MAX
};


class PseuInstanceConf
{
    public:

    PseuInstanceConf();
    ~PseuInstanceConf();
    void ApplyFromVarSet(VarSet &v);


    uint8 debug;
    std::string realmlist;
    std::string accname;
    std::string accpass;
    bool exitonerror;
    uint32 reconnect;
    uint16 realmport;
    uint16 worldport;
    uint8 clientversion[3];
    std::string clientversion_string;
    uint16 clientbuild;
    std::string clientlang;
    std::string realmname;
    std::string charname;
    std::string worldhost;
    uint16 networksleeptime;
    uint8 showopcodes;
    bool hidefreqopcodes;
    bool hideDisabledOpcodes;
    bool allowgamecmd;
    bool enablecli;
    bool notifyping;
    bool showmyopcodes;
    bool disablespellcheck;
    uint32 rmcontrolport;
    std::string rmcontrolhost;
    std::string rmcontrolpass;
    bool useMaps;
    bool skipaddonchat;
    uint8 dumpPackets;
    bool softquit;
    uint8 dataLoaderThreads;
    bool useMPQ;
    
    // gui related
    bool enablegui;
    uint32 terrainsectors;
    uint32 terrainrendersize;
    uint32 terrainupdatestep;
    float farclip;
    float fogfar;
    float fognear;
    float fov;

    // sound related
    float masterSoundVolume;


};


class PseuInstance
{
public:

    PseuInstance(PseuInstanceRunnable *run);
    ~PseuInstance();


    WorldSession *GetWSession(void) { return _wsession; }
    RealmSession *GetRSession(void) { return _rsession; }
    PseuInstanceConf *GetConf(void) { return _conf; }
    LuaPackage *GetScript(void) { return _script; }
    PseuInstanceRunnable *GetRunnable(void) { return _runnable; }
    PseuGUI *GetGUI(void) { return _gui; }
    void DeleteGUI(void);
    bool ConnectToRealm(void);

    inline void SetConfDir(std::string dir) { _confdir = dir; }
    inline std::string GetConfDir(void) { return _confdir; }
    inline void SetSessionKey(BigNumber key) { _sessionkey = key; }
    inline BigNumber *GetSessionKey(void) { return &_sessionkey; }
    inline void SetError(void) { _error = true; }
    SCPDatabaseMgr dbmgr;

    bool Init(void);
    bool InitGUI(void);
    void SaveAllCache(void);
    void Stop(void) { _stop = true; }
    bool Stopped(void) { return _stop; }
    void SetFastQuit(bool q=true) { _fastquit=true; }
    void Run(void);
    void Update(void);
    void Sleep(uint32 msecs);

    inline void CreateWorldSession(void) { _createws = true; }
    inline void CreateRealmSession(void) { _creaters = true; }

    void ProcessCliQueue(void);
    void AddCliCommand(std::string);

    void WaitForCondition(InstanceConditions c, uint32 timeout = 0);
    inline ZThread::Condition *GetCondition(InstanceConditions c) { return _condition[c]; }

private:

    PseuInstanceRunnable *_runnable;
    RealmSession *_rsession;
    WorldSession *_wsession;
    PseuInstanceConf *_conf;
    LuaPackage *_script;
    std::string _confdir;
    bool _initialized;
    bool _stop,_fastquit;
    bool _startrealm;
    bool _error;
    bool _createws, _creaters; // must create world/realm session?
    BigNumber _sessionkey;
    const char *_ver,*_ver_short;
    SocketHandler _sh;
    CliRunnable *_cli;
    ZThread::Thread _clithread;
    RemoteController *_rmcontrol;
    ZThread::LockedQueue<std::string,ZThread::FastMutex> _cliQueue;
    PseuGUI *_gui;
    ZThread::Thread *_guithread;
    ZThread::Condition *_condition[COND_MAX];
    ZThread::FastRecursiveMutex _mutex;

};

class PseuInstanceRunnable : public ZThread::Runnable
{
public:
    PseuInstanceRunnable();
    void run(void);
    void sleep(uint32);
    inline PseuInstance *GetInstance(void) { return _i; }

private:
    PseuInstance *_i;
};


#endif
