#include "WomenStates.h"
#include "GameEnums.h"
#include "Women.h"
#include <iostream>
#include "MessageDispatcher.h"
#include "GameClock.h"
using namespace std;

extern const char* GetNameOfEntity(int ID);

VistBathroom* VistBathroom::Instance()
{
    static VistBathroom singleton;
    return &singleton;
}

void VistBathroom::Enter(Women *pWomen)
{
    if(pWomen->GetLocation() != bathroom)
    {
        cout<<"\n "<<GetNameOfEntity(pWomen->ID())<<": "
            << "Walkin' to the can. Need to powda mah pretty li'l nose\n";
        pWomen->ChangeLocation(bathroom);
    }
}

void VistBathroom::Execute(Women *pWomen)
{
    cout<<"\n "<<GetNameOfEntity(pWomen->ID())<<": "
        << "Ahhhhhh! Sweet relief!\n";

    pWomen->SetBladderEmpty();
    pWomen->GetFSM()->RevertToPrevState();
}

void VistBathroom::Exit(Women *pWomen)
{
    cout<<"\n "<<GetNameOfEntity(pWomen->ID())<<": "
        << "Leavin' the john\n";
}

void DoHouseWork::Enter(Women *pWomen)
{
    if(pWomen->GetLocation() != home)
    {
        pWomen->ChangeLocation(home);
    }

}

void DoHouseWork::Execute(Women *pWomen)
{
    static int idleCount = 0;
    static int work = 0;
    
    if(work || (idleCount > 4)) 
    {
       cout<<"\n "<<GetNameOfEntity(pWomen->ID())<<": "
           << pWomen->GetTaskName() <<"\n";

       work++;
       idleCount = 0;
       if(work >= 2)
           work = 0;
    }
    else
        idleCount++;

}
void DoHouseWork::Exit(Women *pWomen)
{

}

DoHouseWork* DoHouseWork::Instance()
{
    static DoHouseWork singleton;
    return &singleton;
}


WifesGlobalState* WifesGlobalState::Instance()
{
    static WifesGlobalState singleton;
    return &singleton;
}

void WifesGlobalState::Enter(Women *pWomen)
{
}

void WifesGlobalState::Exit(Women *pWomen)
{
}

void WifesGlobalState::Execute(Women *pWomen)
{
    if(pWomen->IsBladderFull())
    {
        pWomen->ChangeState(VistBathroom::Instance());
    }
}

bool WifesGlobalState::OnMessage(Women *pWomen, const Telegram& msg)
{
    if(msg.Msg == Msg_HiHoneyImHome)
    {
        cout << "\nMessage handled by " << GetNameOfEntity(pWomen->ID())
            << " at time: " << Clock->GetCurrentTime();
        cout << "\n" << GetNameOfEntity(pWomen->ID()) <<
            ": Hi honey. Let me make you some of mah fine country stew\n";
        pWomen->GetFSM()->ChangeState(CookStew::Instance());
        return true;
    } 
    return false;
}

CookStew* CookStew::Instance()
{
    static CookStew singleton;
    return &singleton;
}

void CookStew::Enter(Women *pWomen)
{

}

void CookStew::Execute(Women* pWomen)
{
    if(!pWomen->Cooking())
    {
        cout << "\n" << GetNameOfEntity(pWomen->ID())
            << ": Puttin' the stew in the oven\n";
        pWomen->SetCooking(true);
        Dispatch->DispatchMessage(1, pWomen->ID(), pWomen->ID(), Msg_StewReady, (void *)NO_ADDITIONAL_INFO);
    }
}

void CookStew::Exit(Women* pWomen)
{

}

bool CookStew::OnMessage(Women* pWomen, const Telegram& msg)
{
   if(msg.Msg == Msg_StewReady) 
   {
       cout << "\nMessage received by " << GetNameOfEntity(pWomen->ID()) <<
           " at time: " << Clock->GetCurrentTime();
       cout << "\n" << GetNameOfEntity(pWomen->ID())
           << ": Stew ready! Let's eat\n";
       Dispatch->DispatchMessage(0, pWomen->ID(),
                                 ent_Minter_Bob,
                                 Msg_StewReady,
                                 (void *)NO_ADDITIONAL_INFO);


       pWomen->SetCooking(false);
       pWomen->ChangeState(DoHouseWork::Instance());
       return true;
   }

   return false;
}

