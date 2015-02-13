#include "Women.h"
#include "WomenStates.h"

Women::Women(int ID)
{
    mID = ID;
    mCurrentLocation = home;
    mBladderLevel = 1;
    mCooking = false;
    mFSM = new StateMachine<Women> (this);
    mFSM->SetCurrentState(DoHouseWork::Instance());
    mFSM->SetGlobalState(WifesGlobalState::Instance());
}


Women::~Women()
{
    delete mFSM;
}

const char * Women::GetTaskName()
{
    static int taskID = 0;
    switch(taskID)
    {
        case 0:
            {
               taskID++;
               return "Moppin' the floor";
            }
        case 1:
            {
                taskID++;
               return "Moppin' the floor";
            }
        case 2:
            {
               taskID = 0;
               return "Makin' the bed";
            }
    }

}
bool Women::IsBladderFull()
{
    if(mBladderLevel > 3)
        return true;
    else
        return false;

}

void Women::Update()
{
    mBladderLevel++;
    mFSM->Update();
}

void Women::ChangeState(State<Women> *nextState)
{
    mFSM->ChangeState(nextState);
}

bool Women::HandleMessage(const Telegram& msg)
{
    return mFSM->HandleMessage(msg);
}
