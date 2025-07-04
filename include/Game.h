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
    enum class Direction{
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    bool getIsFinished();
    int getPlayerHealth();

    void promptPlayer();
    void startMenu();
    void loadLevel(int level);
    void drawLevel();
    void drawLog();
    void drawControls();
    void drawPlayerStatus();
    void createMonster();
    void createMonster(Monster::MonsterTypes monsterType);
    Monster* findMonster(int posX, int posY);
    void move(Entity* entity, Game::Direction direction);
    void moveMonsters();
    void battle(Entity* attackingEntity, Entity* targetEntity);
};

#endif // GAME_H
