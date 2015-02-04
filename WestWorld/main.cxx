#include "Miner.h"
#include "EntityNames.h"

int main(int argc, char *argv[])
{

    Miner miner(ent_Minter_Bob);
   
    for(int i= 0; i < 100; i++)
       miner.Update(); 
}

