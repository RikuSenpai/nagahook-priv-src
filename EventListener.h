#include "main.h"
#include "Hacks/hitmarker.h"
#include "Hacks/eventlog.hpp"
#include "Hacks/resolver.h"
class EventListener : public IGameEventListener2
{
public:
    EventListener(std::vector<const char*> events)
    {
        for (auto& it : events)
            pGameEventManager->AddListener(this, it, false);
    }
    
    ~EventListener()
    {
        pGameEventManager->RemoveListener(this);
    }
    
    void FireGameEvent(IGameEvent* event)
    {
        Hitmarkers::FireGameEvent(event);
        Eventlog::FireGameEvent(event);
        BulletTracers::FireGameEvent(event);
    }
    
    int GetEventDebugID() override
    {
        return EVENT_DEBUG_ID_INIT;
    }
};
