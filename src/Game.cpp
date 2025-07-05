#include "../include/Game.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm> // Required for std::remove_if()
#include <typeinfo> // Required for typeid()
#include <random>
#include <chrono>

bool Game::getIsFinished() { return m_isFinished; };
int Game::getPlayerHealth() { return m_player.getHealth(); };

void Game::startMenu()
{
    system("clear");
    std::cout << "Welcome to my little ASCII-Rogue Game!!!\n\n";
    std::cout << "What's your name fellow adventurer: ";
    std::string newName;
    getline(std::cin, newName);
    m_player.setName(newName);
    std::cout << "\nHave a nice journey " << m_player.getName() << "\n(Press Enter to continue...)";
    char c;
    while((c = getchar()) != '\n') {}; // Clear Buffer
};

void Game::loadLevel(int level)
{
    system("clear");

    std::ifstream loadingFile;
    loadingFile.open("level"+ std::to_string(level) +".txt");
    if(loadingFile.fail()){ // If fails to load file for some reason
        perror("level1.txt");
        std::exit(1);
    }

    int i = 0;
    int j = 0;
    char ch;
    while(loadingFile >> ch)
        if(ch != '\n')
            m_level[i][j++] = ch;
        else{
            i++;
            j = 0;
        }

    loadingFile.close();

    // Temporary
    // Creating first Goblin monster;
    createMonster(Monster::MonsterTypes::Goblin);

    // Setting player in the level
    m_level[m_player.getPosY()][m_player.getPosX()] = m_player.getCharRep();
};

void Game::promptPlayer()
{
    std::cout << "\nWhat's your next action: ";
    char action;
    while((action = getchar()) != '\n') {
        switch(action){
            case 'w':{ move(&m_player, Direction::UP); break; }

            case 'd':{ move(&m_player, Direction::RIGHT); break; }

            case 's':{ move(&m_player, Direction::DOWN); break; }

            case 'a': { move(&m_player, Direction::LEFT); break; }

            // Create random Monster in a random position
            case 'c': { createMonster(); break; }

            // Prints how many monsters exist and their positions
            case 'p': { m_log.push_back("Num of monsters total: " + std::to_string(m_monsters.size())); break; }

            // Quit the game
            case 'q': { m_isFinished = true; break; }

            // Do nothing with every key, with exception of the Enter key
            default:
                if(action != '\n')
                    m_log.push_back("Invalid Movement");
                break;
        }
    };
};

void Game::drawLevel()
{
    system("clear");

    // Drawing level
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 24; j++)
            std::cout << m_level[i][j];
        std::cout << std::endl;
    }
};

void Game::drawLog()
{
    for(std::string line : m_log)
        std::cout << std::endl << line;

    if(!m_log.empty())
        std::cout << std::endl;

    m_log.clear();
};

void Game::drawControls()
{
    std::cout << "\nCONTROLS:\n\n"
              << "w - Move up\n"
              << "d - Move right\n"
              << "s - Move down\n"
              << "a - Move left\n"
              << "c - Create Monster a random position\n"
              << "p - Print in log total amount of monsters alive\n"
              << "q - Quit\n";
};

void Game::drawPlayerStatus()
{
    std::cout
            << "\nLevel: " + std::to_string(m_player.getLevel())
            << "\tXP: " + std::to_string(m_player.getCurrentXp()) + " (" + std::to_string(m_player.getXpToLevelUp()) + ")"
            << "\tHP: " + std::to_string(m_player.getHealth())
            << "\tStrength: " + std::to_string(m_player.getAttackStat())
            << '\n';

};

// If not monsterType provided, selects it random
void Game::createMonster() {
    std::mt19937 eng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dist(0, 3);

    createMonster(static_cast<Monster::MonsterTypes>(dist(eng)));
};

void Game::createMonster(Monster::MonsterTypes monsterType)
{
    Monster monster(monsterType);

    // Don't create monster in actual position if is already occupied
    while(m_level[monster.getPosY()][monster.getPosX()] != '.'){
        monster.generateNewPositions();
        // Or if generated Position is adjacent to Player position
        // It's not working, no idea why
        // if(m_level[monster.getPosY() - 1][monster.getPosX()] == m_player.getCharRep() ||
        //     m_level[monster.getPosY() + 1][monster.getPosX()] == m_player.getCharRep() ||
        //     m_level[monster.getPosY()][monster.getPosX() - 1] == m_player.getCharRep() ||
        //     m_level[monster.getPosY()][monster.getPosX() + 1] == m_player.getCharRep())
        //     continue;
    }

    m_monsters.push_back(monster);
    m_level[monster.getPosY()][monster.getPosX()] = monster.getCharRep();

    // **********
    // DEBUG ONLY
    // **********
    m_log.push_back(monster.getName() + " created");
};

Monster* Game::findMonster(int posX, int posY)
{
    for(Monster& monster : m_monsters)
        if(monster.getPosX() == posX && monster.getPosY() == posY)
            return &monster;

    return nullptr;
};

void Game::move(Entity* entity, Direction direction)
{
    int nextX = entity->getPosX();
    int nextY = entity->getPosY();

    switch(direction){
        case Direction::UP:    nextY--; break;
        case Direction::RIGHT: nextX++; break;
        case Direction::DOWN:  nextY++; break;
        case Direction::LEFT:  nextX--; break;
    }

    // Boundary checks from original code
    bool boundaryOk = false;
    switch(direction){
        case Direction::UP:    boundaryOk = (nextY > 0); break;
        case Direction::RIGHT: boundaryOk = (nextX < 23); break;
        case Direction::DOWN:  boundaryOk = (nextY < 6); break;
        case Direction::LEFT:  boundaryOk = (nextX > 0); break;
    }

    if (!boundaryOk) {
        return;
    }

    // How my approach for boundary check would be
    // if(direction == Direction::UP && nextY < 0) return;
    // if(direction == Direction::RIGHT && nextX > 23) return;
    // if(direction == Direction::DOWN && nextY > 6) return;
    // if(direction == Direction::LEFT && nextX < 0) return;

    char destinationTile = m_level[nextY][nextX];

    if (destinationTile == '.') { // Empty space
        m_level[entity->getPosY()][entity->getPosX()] = '.';
        entity->setPositionX(nextX);
        entity->setPositionY(nextY);
        m_level[nextY][nextX] = entity->getCharRep();
        return;
    }

    // If not empty space, it might be combat.
    if (typeid(*entity) == typeid(Player)) { // Player moving
        if (destinationTile == 'S'|| destinationTile == 'G' || destinationTile == 'O' || destinationTile == 'D') { // Attacking a monster
            Monster* monster = findMonster(nextX, nextY);
            battle(&m_player, monster);
        }
    }else// Monster moving
        if (destinationTile == m_player.getCharRep()) // Attacking the player
            battle(entity, &m_player);
};

// Moves each monster in a random direction
void Game::moveMonsters()
{
    std::mt19937 eng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dist(0, 3);

    for(Monster& monster : m_monsters){
        // If the player is around the monster, fight it, otherwise move randomly
        if(m_level[monster.getPosY() - 1][monster.getPosX()] == m_player.getCharRep() ||
            m_level[monster.getPosY() + 1][monster.getPosX()] == m_player.getCharRep() ||
            m_level[monster.getPosY()][monster.getPosX() - 1] == m_player.getCharRep() ||
            m_level[monster.getPosY()][monster.getPosX() + 1] == m_player.getCharRep())
            battle(&monster, &m_player);
        else
            move(&monster, static_cast<Direction>(dist(eng)));

        if(m_isFinished)
            break;
    }
};

void Game::battle(Entity* attackingEntity, Entity* targetEntity)
{
    attackingEntity->attack(targetEntity);
    m_log.push_back(attackingEntity->getName() + " attacked " + targetEntity->getName());

    if (targetEntity->getHealth() <= 0) {
        m_log.push_back(targetEntity->getName() + " died.");

        // If target that died was a Monster
        if (typeid(*targetEntity) == typeid(Monster)) {
            bool hasLeveledUp = m_player.gainXp(static_cast<Monster*>(targetEntity)->getXp());
            if(hasLeveledUp)
                m_log.push_back("Level Up!");
            m_level[targetEntity->getPosY()][targetEntity->getPosX()] = '.';
            m_monsters.erase(std::remove_if(m_monsters.begin(), m_monsters.end(), [&targetEntity](const Monster& m){ return (&m == targetEntity);} ), m_monsters.end());
            createMonster();
        }

        // If target that died was a Player
        if (typeid(*targetEntity) == typeid(Player))
            m_isFinished = true;
    }
};
