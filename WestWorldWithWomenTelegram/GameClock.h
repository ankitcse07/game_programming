#ifndef _CLOCK_H
#define _CLOCK_H

#include <sys/time.h>


class GameClock
{
    private:
       GameClock() 
       {
           struct timeval initTime;
           gettimeofday(&initTime, 0);
           mStartTime = initTime.tv_sec;
       }

       GameClock(const GameClock&);
       GameClock& operator=(const GameClock&);

       double mStartTime;

    public:
       static GameClock* Instance();
       double GetCurrentTime();
};

#define Clock GameClock::Instance()

#endif
