#include "EntityManager.h"


void EntityManager::RegisterEntity(BaseEntity *pEntity)
{
    mEntityIDToPtrMap[pEntity->ID()] = pEntity;
}

BaseEntity* EntityManager::GetEntityFromID(int id)
{
    if(mEntityIDToPtrMap.find(id) != mEntityIDToPtrMap.end())
        return mEntityIDToPtrMap[id];
    else
        return 0;
}

EntityManager* EntityManager::Instance()
{
    static EntityManager singleton;
    return &singleton;
}
