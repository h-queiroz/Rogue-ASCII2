#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Player.h"

class Game {
private:
    bool m_isFinished = false;
    Player m_player;
    char m_level[7][24];
    std::vector<std::string> m_log;

public:
    bool getIsFinished();

    void promptPlayer();
    void startMenu();
    void loadLevel(int level);
    void drawLevel();
    void drawLog();
    void drawControls();
};

#endif // GAME_H
