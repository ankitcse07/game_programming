#ifndef _MESSAGE_DISPATCHER_H
#define _MESSAGE_DISPATCHER_H

#include <set>
#include "BaseEntity.h"
#include "Telegram.h"

class MessageDispatcher
{
    private:
        //a std::set is used as the container for the delayed messages
        //because of the benefit of automatic sorting and avoidance
        //of duplicates. Messages are sorted by their dispatch time.
        std::set<Telegram> PriorityQ;
        //this method is utilized by DispatchMessage or DispatchDelayedMessages.
        //This method calls the message handling member function of the receiving
        //entity, pReceiver, with the newly created telegram
        void Discharge(BaseEntity* pReceiver, const Telegram& msg);
        MessageDispatcher(){}
        MessageDispatcher(const MessageDispatcher&);
        MessageDispatcher& operator=(const MessageDispatcher&);
    public:
        //this class is a singleton
        static MessageDispatcher* Instance();
        //send a message to another agent.
        void DispatchMessage(double delay,
                int sender,
                int receiver,
                int msg,
                void* ExtraInfo);
        //send out any delayed messages. This method is called each time through
        // the main game loop.
        void DispatchDelayedMessages();
};

#define Dispatch MessageDispatcher::Instance()

#endif
