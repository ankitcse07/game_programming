#ifndef _MINER_STATES_H
#define _MINER_STATES_H

#include "State.h"

class Miner;
class EnterMineAndDigForNugget : public State<Miner>
{
    private:
        EnterMineAndDigForNugget() {}
        EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);
        EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget &);

    public:
        virtual void Enter(Miner *pMiner);
        virtual void Execute(Miner *pMiner);
        virtual void Exit(Miner *pMiner);

        static EnterMineAndDigForNugget* Instance();

        ~EnterMineAndDigForNugget(){}

};

class VisitBankAndDepositGold : public State<Miner>
{
    private:
        VisitBankAndDepositGold() {}
        VisitBankAndDepositGold(const VisitBankAndDepositGold&);
        VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold &);

    public:
        virtual void Enter(Miner *pMiner);
        virtual void Execute(Miner *pMiner);
        virtual void Exit(Miner *pMiner);

        static VisitBankAndDepositGold* Instance();

        ~VisitBankAndDepositGold(){}

};

class GoHomeAndSleepTilRested : public State<Miner>
{
    private:
        GoHomeAndSleepTilRested() {}
        GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested&);
        GoHomeAndSleepTilRested& operator=(const GoHomeAndSleepTilRested &);

    public:
        virtual void Enter(Miner *pMiner);
        virtual void Execute(Miner *pMiner);
        virtual void Exit(Miner *pMiner);

        static GoHomeAndSleepTilRested* Instance();

        ~GoHomeAndSleepTilRested(){}

};

class QuenchThrist : public State<Miner>
{
    private:
        QuenchThrist() {}
        QuenchThrist(const QuenchThrist&);
        QuenchThrist& operator=(const QuenchThrist &);

    public:
        virtual void Enter(Miner *pMiner);
        virtual void Execute(Miner *pMiner);
        virtual void Exit(Miner *pMiner);

        static QuenchThrist* Instance();

        ~QuenchThrist(){}

};





#endif
