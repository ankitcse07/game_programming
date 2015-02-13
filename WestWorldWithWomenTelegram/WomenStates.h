#ifndef _WOMEN_STATES_H
#define _WOMEN_STATES_H

#include "State.h"

class Women;
class VistBathroom : public State<Women>
{
    private:
        VistBathroom() {}
        VistBathroom(const VistBathroom&);
        VistBathroom& operator=(const VistBathroom &);

    public:
        virtual void Enter(Women *pWomen);
        virtual void Execute(Women *pWomen);
        virtual void Exit(Women *pWomen);

        static VistBathroom* Instance();

        virtual bool OnMessage(Women* pEntity, const Telegram& msg)
        {
            return false;
        }



        ~VistBathroom(){}

};

class DoHouseWork : public State<Women>
{
    private:
        DoHouseWork() {}
        DoHouseWork(const DoHouseWork&);
        DoHouseWork& operator=(const DoHouseWork&);

    public:
        virtual void Enter(Women *pWomen);
        virtual void Execute(Women *pWomen);
        virtual void Exit(Women *pWomen);

        static DoHouseWork* Instance();

        virtual bool OnMessage(Women* pEntity, const Telegram& msg)
        {
            return false;
        }

        ~DoHouseWork(){}

};

class WifesGlobalState : public State<Women>
{
    private:
        WifesGlobalState() {}
        WifesGlobalState(const WifesGlobalState&);
        WifesGlobalState& operator=(const WifesGlobalState&);

    public:
        virtual void Enter(Women *pWomen);
        virtual void Execute(Women *pWomen);
        virtual void Exit(Women *pWomen);

        static WifesGlobalState* Instance();

        virtual bool OnMessage(Women* pEntity, const Telegram& msg);

        ~WifesGlobalState(){}

};

class CookStew : public State<Women>
{
    private:
        CookStew() {}
        CookStew(const CookStew&);
        CookStew& operator=(const CookStew&);

    public:
        virtual void Enter(Women *pWomen);
        virtual void Execute(Women *pWomen);
        virtual void Exit(Women *pWomen);

        static CookStew* Instance();

        virtual bool OnMessage(Women* pEntity, const Telegram& msg);

        ~CookStew(){}
};



#endif
