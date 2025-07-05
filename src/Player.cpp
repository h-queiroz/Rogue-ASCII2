#include "../include/Player.h"

#include <cmath> // std::ceil()

Player::Player(){
    m_level = 1;
    m_currentXp = 0;
    m_xpToLevelUp = 10;
    m_charRep = '@';
    m_posX = 2;
    m_posY = 2;
    m_attackStat = 100;
    m_health = 999999999;
    // m_attackStat = 6;
    // m_health = 20;
}

int Player::getLevel() { return m_level; };
int Player::getCurrentXp() { return m_currentXp; };
int Player::getXpToLevelUp() { return m_xpToLevelUp; };

// True if leveled up
bool Player::gainXp(int xp)
{
    m_currentXp += xp;

    // If has enough has to level up
    if(m_currentXp >= m_xpToLevelUp) {
        m_level++;
        m_health = (20 + (m_level*2)); // Recovers all health. May remove later
        m_attackStat += 2;
        m_currentXp = (m_currentXp - m_xpToLevelUp);
        m_xpToLevelUp = static_cast<int>(std::ceil(m_xpToLevelUp * 1.3));
        return true;
    }

    return false;
};
