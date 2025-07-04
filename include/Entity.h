#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity{
protected:
    char m_charRep; // Character that represents it in the level
    std::string m_name;
    int m_posX;
    int m_posY;
    int m_health;
    int m_attackStat;

public:
    // Getters
    char getCharRep();
    std::string getName();
    int getPosX();
    int getPosY();
    int getAttackStat();
    int getHealth();

    // Setters
    void setName(std::string name);
    void setPositionX(int posX);
    void setPositionY(int posY);
    void setHealth(int newHealth);

    bool takeDamage(int damage);
    void attack(Entity* targetEntity);

    virtual void dummy() {}; // Base class must be polymorphic for typeid with pointers/references
};

#endif // ENTITY_H
