#ifndef _BASE_ENTITY_H
#define _BASE_ENTITY_H

#include "Telegram.h"

class BaseEntity
{
    protected:
        int mID;
        int mCurrentLocation;
    public:
        virtual int ID() { return mID;}
        virtual int GetLocation() { return mCurrentLocation;}

        void ChangeLocation(int location)
        {  mCurrentLocation = location; }

        virtual bool HandleMessage(const Telegram& msg)=0;
};

#endif
