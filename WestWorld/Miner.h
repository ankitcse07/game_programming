#ifndef _MINER_H
#define _MINER_H

#include "EntityNames.h"
#include "Miner.h"
#include "States.h"

class Miner
{
    private:
        State *mCurrentState;
        int dID;
        int dCurrentLocation;
        int dTotalGoldInBank;
        int dTotalGoldInPocket;
        int dFatigueLevel;
        int dThristLevel;

    public:
        Miner(int ID);

        int ID() { return dID; }
        void AddToGoldCarried(int num);
        void IncreaseFatigue();
        void DecreaseFatigue();
        int GetLocation() { return dCurrentLocation;}
        void DecreaseThrist()
        { dThristLevel = 0; }
        void ChangeLocation(int location)
        {  dCurrentLocation = location; }
        bool IsPocketFull();
        bool IsThristy();
        void DepositNugget(int num);
        int GetSavings() { return dTotalGoldInBank; }
        bool IsEnoughRich();
        bool IsFatigueLevelLow();

        void ChangeState(State *nextState);

        void Update();

};

#endif
