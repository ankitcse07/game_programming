#ifndef _ENTITY_MANAGER_H
#define _ENTITY_MANAGER_H

#include "BaseEntity.h"
#include <map>

class EntityManager
{
    private:
        std::map <int, BaseEntity *> mEntityIDToPtrMap;

        EntityManager() {}
        EntityManager(const EntityManager&);
        EntityManager& operator=(const EntityManager&);

    public:
        void RegisterEntity(BaseEntity *pEntity);
        BaseEntity *GetEntityFromID(int id); 
        static EntityManager *Instance();
};

#define EntityMngInst EntityManager::Instance() 


#endif
