#ifndef _STATE_H
#define _STATE_H

template <class entity_type>
class State
{
    public:
        State() {}
        virtual void Enter(entity_type *pMiner) = 0;
        virtual void Execute(entity_type *pMiner) = 0;
        virtual void Exit(entity_type *pMiner) = 0;
};


#endif
