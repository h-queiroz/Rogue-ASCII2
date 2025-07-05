#include <random>
#include <chrono>

#include "../include/Monster.h"

Monster::Monster(MonsterTypes monsterType)
{
    m_monsterType = monsterType;
    switch(monsterType){
        case MonsterTypes::Snake: {
            m_name = "Snake";
            m_charRep = 'S';
            m_attackStat = 1;
            m_health = 5;
            m_xp = 2;
            break;
        }

        case MonsterTypes::Goblin: {
            m_name = "Green goblin";
            m_charRep = 'G';
            m_attackStat = 3;
            m_health = 10;
            m_xp = 4;
            break;
        }

        case MonsterTypes::Orc: {
            m_name = "Orc";
            m_charRep = 'O';
            m_attackStat = 5;
            m_health = 20;
            m_xp = 6;
            break;
        }

        case MonsterTypes::Dragon: {
            m_name = "Dragon";
            m_charRep = 'D';
            m_attackStat = 10;
            m_health = 45;
            m_xp = 25;
            break;
        }
    };

    generateNewPositions();
};

int Monster::getXp() { return m_xp; };

void Monster::generateNewPositions()
{
    std::mt19937 eng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dist(0, 23); // Generates between 0 and 23 inclusive
    std::uniform_int_distribution<> dist2(0, 6); // Generates between 0 and 6 inclusive

    m_posX = dist(eng);
    m_posY = dist2(eng);
};
