#include "MessageDispatcher.h"
#include "EntityManager.h"
#include "GameClock.h"


MessageDispatcher* MessageDispatcher::Instance()
{
    static MessageDispatcher singleton;
    return &singleton;
}

void MessageDispatcher::Discharge(BaseEntity *pReceiver, const Telegram& msg)
{
    pReceiver->HandleMessage(msg);
}

void MessageDispatcher::DispatchMessage(double delay,
        int sender,
        int receiver,
        int msg,
        void *ExtraInfo)
{
    BaseEntity *pRecvObj = EntityMngInst->GetEntityFromID(receiver);
    Telegram telegram(sender, receiver, msg, 0, ExtraInfo); 

    if(delay <= 0.0)
    {
        Discharge(pRecvObj, telegram);
    }
    else
    {
        double dispatchTime = delay + Clock->GetCurrentTime();
        telegram.DispatchTime = dispatchTime;
        PriorityQ.insert(telegram);
    }
}

void MessageDispatcher::DispatchDelayedMessages()
{
    if(PriorityQ.empty())
        return;
    double currentTime = Clock->GetCurrentTime();

    if((PriorityQ.begin()->DispatchTime > 0) && (PriorityQ.begin()->DispatchTime < currentTime))
    {
        Telegram msg = *PriorityQ.begin();
        Discharge(EntityMngInst->GetEntityFromID(msg.Receiver), msg);
        PriorityQ.erase(PriorityQ.begin());
    }
}
