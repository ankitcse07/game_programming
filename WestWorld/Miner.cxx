#include "Miner.h"


Miner::Miner(int ID)
{
    dID = ID;
    dCurrentLocation = home;
    dTotalGoldInBank = 2;
    dTotalGoldInPocket = 0;
    dFatigueLevel = 0;
    dThristLevel = 0;
    mCurrentState = GoHomeAndSleepTilRested::Instance(); 
}

void Miner::AddToGoldCarried(int num)
{
    dTotalGoldInPocket += num;
}

void Miner::IncreaseFatigue()
{
    dFatigueLevel++;
}

void Miner::DecreaseFatigue()
{
    dFatigueLevel--;
}

bool Miner::IsPocketFull()
{

    if(dTotalGoldInPocket >= 2)
        return true;
    else
        return false;
}

bool Miner::IsThristy()
{
    if(dThristLevel >= 3)
        return true;
    else
        return false;
}


void Miner::DepositNugget(int num)
{
    dTotalGoldInBank += num;
    dTotalGoldInPocket = 0;
}

bool Miner::IsEnoughRich()
{
    if(dTotalGoldInBank >= 5)
        return true;
    else
        return false;
}

bool Miner::IsFatigueLevelLow()
{

    if(dFatigueLevel < 3)
        return true;
    else
        return false;
}

void Miner::ChangeState(State *nextState)
{
    mCurrentState->Exit(this);
    mCurrentState = nextState;
    mCurrentState->Enter(this);
}

void Miner::Update()
{
    dThristLevel++;
    mCurrentState->Execute(this);
}
