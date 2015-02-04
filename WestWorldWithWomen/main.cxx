#include "Miner.h"
#include "Women.h"
#include "EntityNames.h"

int main(int argc, char *argv[])
{

    Miner miner(ent_Minter_Bob);
    Women women(ent_Women_Elsa);
   
    for(int i= 0; i < 100; i++)
    {
       miner.Update(); 
       women.Update();
    }
}

