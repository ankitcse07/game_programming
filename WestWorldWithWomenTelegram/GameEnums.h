#ifndef _GAME_ENUMS_H_
#define _GAME_ENUMS_H_ 

#define START_ENUM_LOCATION 1
// Entity Names 1-99 
enum eEntityNames
{
    ent_Minter_Bob = START_ENUM_LOCATION,
    ent_Women_Elsa
};

// Locations 100-200
enum eLocations
{
    goldmine = START_ENUM_LOCATION + 100,
    bank,
    saloon,
    home,
    bathroom
};

enum eMessageType
{
    Msg_HiHoneyImHome = START_ENUM_LOCATION + 200,
    Msg_StewReady,
    NO_ADDITIONAL_INFO
};

#endif
