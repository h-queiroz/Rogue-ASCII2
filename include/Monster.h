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
    int m_xp; // The amount of xp the Player receives when the Monster dies

public:
    // Constructor
    Monster(MonsterTypes monsterType);

    int getXp();

    void generateNewPositions();
};

#endif // MONSTER_H
