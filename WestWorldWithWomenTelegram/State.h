#ifndef _STATE_H
#define _STATE_H

#include "Telegram.h"
template <class entity_type>
class State
{
    public:
        State() {}
        virtual void Enter(entity_type *pEntity) = 0;
        virtual void Execute(entity_type *pEntity) = 0;
        virtual void Exit(entity_type *pEntity) = 0;

        virtual bool OnMessage(entity_type* pEntity, const Telegram& msg) = 0;
};


#endif
