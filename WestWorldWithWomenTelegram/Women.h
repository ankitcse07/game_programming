#ifndef _WOMEN_H

#include "GameEnums.h"
#include "StateMachine.h"
#include "BaseEntity.h"

class Women : public BaseEntity
{
    private:
        StateMachine<Women> *mFSM;
        int mBladderLevel;

        bool mCooking;
        

    public:
        Women(int ID);
        ~Women();

        const char *GetTaskName();
        bool IsBladderFull();
        void Update();
        void SetBladderEmpty()
        { mBladderLevel = 0; }

        void ChangeState(State<Women> *nextState);
        StateMachine<Women>* GetFSM() { return mFSM;}
        virtual bool HandleMessage(const Telegram& msg);
        bool Cooking() { return mCooking; }

        bool SetCooking(bool val)
        {
            mCooking = val;
        }

};


#endif
