#include <random>
#include <chrono>

#include "../include/Monster.h"

Monster::Monster()
{
    m_name = "Green goblin";
    m_charRep = 'G';
    m_attackStat = 2;
    m_health = 15;
    generateNewPositions();
};

void Monster::generateNewPositions()
{
    std::mt19937 eng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dist(0, 23); // Generates between 0 and 23 inclusive
    std::uniform_int_distribution<> dist2(0, 6); // Generates between 0 and 6 inclusive

    m_posX = dist(eng);
    m_posY = dist2(eng);
};
