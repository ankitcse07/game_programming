#ifndef _STATE_MACHINE_H
#define _STATE_MACHINE_H
#include "State.h"

template <class entity_type>
class StateMachine
{
    private:
        entity_type *mOwner;
        State<entity_type> *mCurrentState;
        State<entity_type> *mPrevState;
        State<entity_type> *mGlobalState;

    public:
        StateMachine(entity_type *owner)
        {
            mOwner = owner;
            mCurrentState = 0;
            mPrevState = 0;
            mGlobalState = 0;
        }

        bool HandleMessage(const Telegram& msg)
        {
            if(mCurrentState && mCurrentState->OnMessage(mOwner, msg))
                return true;

            if(mGlobalState && mGlobalState->OnMessage(mOwner, msg))
                return true;

            return false;
        }

        void SetCurrentState(State<entity_type> *pState)
        {
            mCurrentState = pState;
        }

        void SetPrevState(State<entity_type> *pState)
        {
            mPrevState = pState;
        }

        void SetGlobalState(State<entity_type> *pState)
        {
            mGlobalState = pState;
        }

        void Update()
        {
            if(mGlobalState)
                mGlobalState->Execute(mOwner);

            if(mCurrentState)
                mCurrentState->Execute(mOwner);
        }

        void ChangeState(State<entity_type> *nextState)
        {
            mPrevState = mCurrentState;
            mCurrentState->Exit(mOwner);
            mCurrentState = nextState;
            mCurrentState->Enter(mOwner);
        }

        void RevertToPrevState()
        {
            ChangeState(mPrevState);
        }

        ~StateMachine() {}
};

#endif
