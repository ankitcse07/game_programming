#include "EntityNames.h"

const char* GetNameOfEntity(int ID)

{

    switch(ID)
    {
        case ent_Minter_Bob:
            {
                return  "Minter_Bob";
                break;
            }
        case ent_Women_Elsa:
            {
                return "Elsa";
                break;
            }
    }
}


