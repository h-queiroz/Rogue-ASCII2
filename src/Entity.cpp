#include "../include/Entity.h"

char Entity::getCharRep() { return m_charRep; };
std::string Entity::getName() { return m_name; };
int Entity::getPosX() { return m_posX; };
int Entity::getPosY() { return m_posY; };
int Entity::getAttackStat() { return m_attackStat; };
int Entity::getHealth() { return m_health; };

void Entity::setName(std::string name) { m_name = name; };
void Entity::setPositionX(int posX) { m_posX = posX; };
void Entity::setPositionY(int posY) { m_posY = posY; };
void Entity::setHealth(int newHealth) { m_health = newHealth; };

// Returns true if health is over 0, in other words, if is still alive
bool Entity::takeDamage(int damage)
{
    m_health = (m_health - damage);
    return (m_health > 0);
};

void Entity::attack(Entity* targetEntity){
    targetEntity->setHealth(targetEntity->getHealth() - m_attackStat);
}
