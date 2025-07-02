#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string m_name;
    int m_posX = 2;
    int m_posY = 2;
    int m_attackStat = 5;

public:
    // Getters
    std::string getName();
    int getPositionX();
    int getPositionY();
    int getAttackStat();

    // Setters
    void setName(std::string name);
    void setPositionX(int posX);
    void setPositionY(int posY);
};

#endif // PLAYER_H
