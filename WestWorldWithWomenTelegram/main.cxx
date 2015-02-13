#include "Miner.h"
#include "Women.h"
#include "GameEnums.h"
#include "EntityManager.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MessageDispatcher.h"

int main(int argc, char *argv[])
{

    Miner miner(ent_Minter_Bob);
    EntityMngInst->RegisterEntity(&miner);
    Women women(ent_Women_Elsa);
    EntityMngInst->RegisterEntity(&women);
   
    for(int i= 0; i < 100; i++)
    {
       miner.Update(); 
       women.Update();
       Dispatch->DispatchDelayedMessages();
       sleep(1);
    }
}

