#include "../include/Player.h"

std::string Player::getName() { return m_name; };
int Player::getPositionX() { return m_posX; };
int Player::getPositionY() { return m_posY; };

void Player::setName(std::string name) { m_name = name; };
void Player::setPositionX(int posX) { m_posX = posX; };
void Player::setPositionY(int posY) { m_posY = posY; };
