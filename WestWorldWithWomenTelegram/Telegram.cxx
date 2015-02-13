#include "Telegram.h"

bool Telegram::operator== (const Telegram& op2) const
    {
        double diff = DispatchTime - op2.DispatchTime;

        if(diff < 0)
            diff = -1*diff;

        if( (diff >=0) && (diff <=0.25))
            return true;
        else
            return false;
    }
   bool Telegram::operator< (const Telegram& op2) const
    {
        double diff = DispatchTime - op2.DispatchTime;

        if( diff < 0)
            return true;
        else
            return false;
    }

Telegram::Telegram(int sender, int recv, int msg, double distime, void* extraInfo)
{
    Sender = sender;
    Receiver = recv;
    Msg = msg;
    DispatchTime = distime;
    ExtraInfo = extraInfo;
}
