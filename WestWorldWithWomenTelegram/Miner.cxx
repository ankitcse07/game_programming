#include "Miner.h"
#include "MinerStates.h"


Miner::Miner(int ID)
{
    mID = ID;
    mCurrentLocation = home;
    dTotalGoldInBank = 2;
    dTotalGoldInPocket = 0;
    dFatigueLevel = 0;
    dThristLevel = 0;

    mFSM = new StateMachine<Miner>(this);
    mFSM->SetCurrentState(GoHomeAndSleepTilRested::Instance());
}
Miner::~Miner()
{
    delete mFSM;
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

void Miner::ChangeState(State<Miner> *nextState)
{
    mFSM->ChangeState(nextState);
}

void Miner::Update()
{
    dThristLevel++;
    mFSM->Update();
}

bool Miner::HandleMessage(const Telegram& msg)
{
    return mFSM->HandleMessage(msg);
}
