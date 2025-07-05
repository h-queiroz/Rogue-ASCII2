#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity{
private:
    int m_level;
    int m_currentXp;
    int m_xpToLevelUp;

public:
    // Constructor
    Player();

    // Getters
    int getLevel();
    int getCurrentXp();
    int getXpToLevelUp();

    // True if leveled up
    bool gainXp(int xp);
};

#endif // PLAYER_H
