#include <cstdlib> // srand(), rand()
#include <ctime> // time()

#include "../include/Monster.h"

Monster::Monster()
{
    generateNewPositions();
};

// Getters
char Monster::getName() { return m_name; };
int Monster::getPosX() { return m_posX; };
int Monster::getPosY() { return m_posY; };
int Monster::getHealth() { return m_health; };

// Setters
void Monster::setPosX(int newPosX) { m_posY = newPosX; };
void Monster::setPosY(int newPosY) { m_posX = newPosY; };
void Monster::setHealth(int newHealth) { m_health = newHealth; };

//Bug Alert
//For some reason, the goblins are being created at the same exact positions
//I belive I really need to use srand(time(0)) to make them random, but I'm not sure where
//Maybe just add a time between the number draws
void Monster::generateNewPositions()
{
    // srand(time(0)); // Was causing problems and it seems to not be actually essential for how I'm using it

    m_posX = rand() % 24; // Generate new int between 0 and 23 inclusive
    m_posY = rand() % 7; // Generate new int between 0 and 6 inclusive
};

// Returns true if health is over 0, in other words, if is still alive
bool Monster::takeDamage(int damage)
{
    // setHealth(0);
    // setHealth(m_health - damage);
    // m_health = (m_health - damage);
    m_health -= 1;
    return (m_health > 0);
};
