#include "GameClock.h"
GameClock* GameClock::Instance()
{
   static GameClock singleton;
   return &singleton; 
}

double GameClock::GetCurrentTime()
{
    struct timeval initTime;
    gettimeofday(&initTime, 0);
    return  (initTime.tv_sec - mStartTime);
}
