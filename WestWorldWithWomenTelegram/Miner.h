#ifndef _MINER_H
#define _MINER_H

#include "BaseEntity.h"
#include "GameEnums.h"
#include "StateMachine.h"

class Miner : public BaseEntity
{
    private:
        StateMachine<Miner> *mFSM;
        int dTotalGoldInBank;
        int dTotalGoldInPocket;
        int dFatigueLevel;
        int dThristLevel;

    public:
        Miner(int ID);
        ~Miner();

        StateMachine<Miner>* GetFSM() { return mFSM; }
        void AddToGoldCarried(int num);
        void IncreaseFatigue();
        void DecreaseFatigue();
        void DecreaseThrist()
        { dThristLevel = 0; }
        bool IsPocketFull();
        bool IsThristy();
        void DepositNugget(int num);
        int GetSavings() { return dTotalGoldInBank; }
        bool IsEnoughRich();
        bool IsFatigueLevelLow();

        void ChangeState(State<Miner> *nextState);

        void Update();

        virtual bool HandleMessage(const Telegram& msg);
};

#endif
