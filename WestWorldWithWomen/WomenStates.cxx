#include "WomenStates.h"
#include "EntityNames.h"
#include "Women.h"
#include <iostream>
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

