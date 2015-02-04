#ifndef _WOMEN_H

#include "EntityNames.h"
#include "StateMachine.h"

class Women
{
    private:
        StateMachine<Women> *mFSM;
        int mID;
        int mCurrentLocation;
        int mBladderLevel;
        

    public:
        Women(int ID);
        ~Women();

        const char *GetTaskName();

        int GetLocation()
        {
            return mCurrentLocation;
        }
        void ChangeLocation(int location)
        {
            mCurrentLocation = location;
        }
        int ID() { return mID; }
        bool IsBladderFull();
        void Update();
        void SetBladderEmpty()
        { mBladderLevel = 0; }

        void ChangeState(State<Women> *nextState);
        StateMachine<Women>* GetFSM() { return mFSM;}

};


#endif
