#ifndef _TELEGRAM_H
#define _TELEGRAM_H

#include "GameEnums.h"

struct Telegram
{
    int Sender;
    int Receiver;

    // This represents MessageType
    int Msg;

    // Message can delayed dispatched
    //This value if > 0 represents time 
    // at which message should be dispatched
    double DispatchTime;

    // Any extra payload specific to message
    // should go here
    void* ExtraInfo;

    bool operator== (const Telegram& op2) const;
   bool operator< (const Telegram& op2) const;
   Telegram(int sender, int recv, int msg, double distime, void *ExtraInfo);
};

#endif
