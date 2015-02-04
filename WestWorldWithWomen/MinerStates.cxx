// This file defines all FINITE STATE machines using state design pattern
// All State classe are singleton

#include "MinerStates.h"
#include "Miner.h"
#include <iostream>
using namespace std;

extern const char* GetNameOfEntity(int ID);

void EnterMineAndDigForNugget::Enter(Miner *pMiner)
{
    if(pMiner->GetLocation() != goldmine)
    {
        cout<<"\n "<<GetNameOfEntity(pMiner->ID())<<": "
            <<"Walking to gold mine ..!\n";
        pMiner->ChangeLocation(goldmine);
    }
}

void EnterMineAndDigForNugget::Execute(Miner *pMiner)
{
    pMiner->AddToGoldCarried(1);
    pMiner->IncreaseFatigue();

    cout<<"\n "<<GetNameOfEntity(pMiner->ID())<<": "
        <<"Picking gold nugget..!\n";

    if(pMiner->IsPocketFull())
    {
        pMiner->ChangeState(VisitBankAndDepositGold::Instance());
    }

    if(pMiner->IsThristy())
    {
        pMiner->ChangeState(QuenchThrist::Instance());
    }
}

EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
{
    static EnterMineAndDigForNugget singleton;
    return &singleton;
}

void EnterMineAndDigForNugget::Exit(Miner *pMiner)
{
    cout<<"\n "<<GetNameOfEntity(pMiner->ID())<<": "
            <<"Leaving gold mine with pocket full of sweet gold ..!\n";
}


void VisitBankAndDepositGold::Enter(Miner *pMiner)
{
    if(pMiner->GetLocation() != bank)
    {
        cout<<"\n "<<GetNameOfEntity(pMiner->ID())<<": "
            <<"Walking to bank to deposit gold nugget ..!\n";
        pMiner->ChangeLocation(bank);

    }
} 

void VisitBankAndDepositGold::Execute(Miner *pMiner)
{

    pMiner->DepositNugget(1);
    
    cout<<"\n "<<GetNameOfEntity(pMiner->ID())<<": "
        <<"Deposit gold. Total Savings "<< pMiner->GetSavings()<<"..!\n";

    if(pMiner->IsEnoughRich())
    {
        cout<<"\n "<<GetNameOfEntity(pMiner->ID())<<": "
            <<"Woohoo! Rich enough for now. Back home to mah li'l lady"<<endl;
        pMiner->ChangeState(GoHomeAndSleepTilRested::Instance());
    }
    else
    {
        pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
    }
}

void VisitBankAndDepositGold::Exit(Miner *pMiner)
{
    cout<<"\n "<<GetNameOfEntity(pMiner->ID())<<": "
            <<"Leaving bank after depositing gold nuggets in bank ..!\n";
}

VisitBankAndDepositGold *VisitBankAndDepositGold::Instance()
{
    static VisitBankAndDepositGold singleton;
    return &singleton;
}

void GoHomeAndSleepTilRested::Enter(Miner* pMiner)
{
    if(pMiner->GetLocation() != home)
    {
        cout<<"\n "<<GetNameOfEntity(pMiner->ID())<<": "
            <<"Walking home ..!\n";
        pMiner->ChangeLocation(home);
    }
}

void GoHomeAndSleepTilRested::Execute(Miner *pMiner)
{
    while(!pMiner->IsFatigueLevelLow())
    {
        cout<<"ZZZZ\n";
        pMiner->DecreaseFatigue();
    }
    pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
}

void GoHomeAndSleepTilRested::Exit(Miner* pMiner)
{
    cout<<"\n "<<GetNameOfEntity(pMiner->ID())<<": "
        <<"What a God-darn fantastic nap! Time to find more gold\n";
}


GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::Instance()
{
    static GoHomeAndSleepTilRested singleton;
    return &singleton;
}


QuenchThrist* QuenchThrist::Instance()
{
    static QuenchThrist singleton;
    return &singleton;
}

void QuenchThrist::Enter(Miner *pMiner)
{
    if(pMiner->GetLocation() != saloon)
    {
        cout<<"\n "<<GetNameOfEntity(pMiner->ID())<<": "
            <<"Boy, ah sure is thusty! Walkin' to the saloon\n";       
        pMiner->ChangeLocation(saloon);
    }
}

void QuenchThrist::Execute(Miner* pMiner)
{
    cout<<"\n "<<GetNameOfEntity(pMiner->ID())<<": "
        <<"That's mighty fine sippin' liquor\n";
    
    pMiner->DecreaseThrist();
    pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
}

void QuenchThrist::Exit(Miner *pMiner)
{
    cout<<"\n "<<GetNameOfEntity(pMiner->ID())<<": "
        <<"Leavin' the saloon, feelin' good\n";

}
        


