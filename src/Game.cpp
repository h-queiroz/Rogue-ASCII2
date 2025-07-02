#include "../include/Game.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm> // for std::remove

bool Game::getIsFinished() { return m_isFinished; };

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

    // Temp
    createMonster();
};

void Game::promptPlayer()
{
    std::cout << "\nWhat's your next action: ";
    char action;
    while((action = getchar()) != '\n') {
        switch(action){
            case 'w':{
                // if(m_level[m_player.getPositionY() - 1][m_player.getPositionX()] == '.' && ((m_player.getPositionY() - 1) > 0))
                //     m_player.setPositionY(m_player.getPositionY() - 1);
                // break;
                if((m_player.getPositionY() - 1) > 0){
                    if(m_level[m_player.getPositionY() - 1][m_player.getPositionX()] == '.'){
                        m_player.setPositionY(m_player.getPositionY() - 1);
                        break;
                    }

                    if(m_level[m_player.getPositionY() - 1][m_player.getPositionX()] == 'G'){
                        Monster* monster = findMonster(m_player.getPositionX(), m_player.getPositionY() - 1);
                        bool isAlive = monster->takeDamage(m_player.getAttackStat()); // takeDamage is not actually decreasing the monster life.
                        m_log.push_back(m_player.getName()+" attacked Green goblin. Now Green goblin only have " + std::to_string(monster->getHealth()) + " of life.");

                        if(!isAlive){
                            m_monsters.erase(std::remove_if(m_monsters.begin(), m_monsters.end(), [&monster](Monster m){ return (&m == monster);} ), m_monsters.end()); // Not working
                            m_log.push_back("Green goblin died.");
                        }
                        break;
                    }
                }
                break;
            }

            case 'd':{
                if(m_level[m_player.getPositionY()][m_player.getPositionX() + 1] == '.' && ((m_player.getPositionX() + 1) < 23))
                    m_player.setPositionX(m_player.getPositionX() + 1);
                break;
            }

            case 's':{
                if(m_level[m_player.getPositionY() + 1][m_player.getPositionX()] == '.' && ((m_player.getPositionY() + 1) < 6))
                    m_player.setPositionY(m_player.getPositionY() + 1);
                break;
            }

            case 'a': {
                if(m_level[m_player.getPositionY()][m_player.getPositionX() - 1] == '.' && ((m_player.getPositionX() - 1) > 0))
                    m_player.setPositionX(m_player.getPositionX() - 1);
                break;
            }

            case 'q': {
                m_isFinished = true;
                break;
            }

            case 'c': { // Create Monster in random position
                createMonster();
                break;
            }

            case 'p': { // Prints how many monsters exist and their positions
                m_log.push_back("Num of monsters total: " + std::to_string(m_monsters.size()));
                break;
            }

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

    m_level[m_player.getPositionY()][m_player.getPositionX()] = '@';
    for(Monster monster : m_monsters)
        m_level[monster.getPosY()][monster.getPosX()] = monster.getName();

    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 24; j++) {
            if(m_level[i][j] == '@' && (i != m_player.getPositionY() || j != m_player.getPositionX())) // Erases player's last position to common floor
                m_level[i][j] = '.';

            std::cout << m_level[i][j];
        }
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
              << "q - Quit\n";
};

void Game::createMonster()
{
    Monster monster;

    // Don't create monster in actual position if is already occupied
    while(true){
        if(m_level[monster.getPosY()][monster.getPosX()] == '#' ||
           m_level[monster.getPosY()][monster.getPosX()] == '@' ||
           m_level[monster.getPosY()][monster.getPosX()] == 'G')
            monster.generateNewPositions();
        else
            break;
    }

    m_monsters.push_back(monster);

    m_log.push_back("Monster Created");
};

Monster* Game::findMonster(int posX, int posY)
{
    Monster* foundMonster;
    for(Monster monster : m_monsters){
        if(monster.getPosX() == posX && monster.getPosY() == posY){
            foundMonster = &monster;
            return foundMonster;
        }
    }

    return nullptr;
};
