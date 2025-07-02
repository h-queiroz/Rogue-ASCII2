#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game {
private:
    Player m_player;
    char m_level[7][24];

public:
    void loadMenu();
    void loadLevel(int level);
};

#endif // GAME_H
