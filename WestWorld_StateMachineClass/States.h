#ifndef _STATES_H
#define _STATES_H

template <class entity_type>
class State
{
    public:
        State() {}
        virtual void Enter(entity_type *pMiner) = 0;
        virtual void Execute(entity_type *pMiner) = 0;
        virtual void Exit(entity_type *pMiner) = 0;
};

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
