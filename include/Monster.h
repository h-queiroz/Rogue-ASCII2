#ifndef MONSTER_H
#define MONSTER_H

#include "Entity.h"

class Monster : public Entity {
public:
    enum class MonsterTypes {
        Snake,
        Goblin,
        Orc,
        Dragon,
    };

private:
    MonsterTypes m_monsterType;

public:
    // Monster();
    // Constructor
    Monster(MonsterTypes monsterType);

    void generateNewPositions();
};

#endif // MONSTER_H
