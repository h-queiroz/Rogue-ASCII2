#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Player.h"
#include "Monster.h"

class Game {
private:
    bool m_isFinished = false;
    Player m_player;
    char m_level[7][24];
    std::vector<std::string> m_log;
    std::vector<Monster> m_monsters;

public:
    bool getIsFinished();

    void promptPlayer();
    void startMenu();
    void loadLevel(int level);
    void drawLevel();
    void drawLog();
    void drawControls();
    void createMonster();
    Monster* findMonster(int posX, int posY);
};

#endif // GAME_H
