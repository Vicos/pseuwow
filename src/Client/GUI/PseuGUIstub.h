#ifndef PSEUGUISTUB_H
#define PSEUGUISTUB_H

#include "Object.h"
#include "SceneData.h"

class Object;
class PseuGUI;
class PseuGUIRunnable;
class PseuInstance;

enum SceneState
{
    SCENESTATE_NULL,
    SCENESTATE_GUISTART,
    SCENESTATE_LOGINSCREEN,
    SCENESTATE_REALMSELECT,
    SCENESTATE_CHARSELECT,
    SCENESTATE_LOADING,
    SCENESTATE_WORLD,
    SCENESTATE_NOSCENE
};

class PseuGUIRunnable : public ZThread::Runnable
{
public:
    PseuGUIRunnable() {};
    void run(void) {};
    PseuGUI *GetGUI(void) {return 0;};
};


class PseuGUI
{
public:
    PseuGUI() {};

    void SetInstance(PseuInstance*) {};
    void SetDriver(uint8) {};
    void SetResolution(uint16 x, uint16 y, uint16 depth=32) {};
    void SetWindowed(bool) {};
    void SetVSync(bool) {};
    void UseShadows(bool) {};
    void Shutdown(void) {};
    inline bool IsInitialized(void) {return 0;};
    inline void SetUseSound(bool b) {};

    void NotifyObjectDeletion(uint64 guid) {};
    void NotifyObjectCreation(Object *o) {};
    void NotifyAllObjectsDeletion(void) {};

    void SetSceneState(SceneState) {};
    bool SetSceneData(uint32, uint32) {return 0;};
    uint32 GetSceneState(void) {return 0;};
    inline void UpdateScene(void) {};
};

#endif

