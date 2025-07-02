#ifndef MONSTER_H
#define MONSTER_H

class Monster {
private:
    char m_name = 'G'; // G for goblin
    int m_posX;
    int m_posY;
    int m_health = 15; // healthBar

public:
    // Constructor
    Monster();

    // Getters
    char getName();
    int getPosX();
    int getPosY();
    int getHealth();
    
    // Setters
    void setPosX(int newPosX);
    void setPosY(int newPosY);
    void setHealth(int newHealth);

    void generateNewPositions();

    bool takeDamage(int damage);
};

#endif // MONSTER_H
