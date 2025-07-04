#ifndef MONSTER_H
#define MONSTER_H

#include "Entity.h"

class Monster : public Entity {
public:
    // Constructor
    Monster();

    void generateNewPositions();
};

#endif // MONSTER_H
