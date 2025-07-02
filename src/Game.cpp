#include "../include/Game.h"

#include <iostream>
#include <cstdlib>
#include <fstream>

void Game::loadMenu()
{
    system("clear");
    std::cout << "Welcome to my little ASCII-Rogue Game!!!\n\n";
    std::cout << "What's your name fellow adventurer: ";
    std::string newName;
    std::cin >> newName;
    m_player.setName(newName);
    std::cout << "\nHave a nice journey " << m_player.getName() << "\n(Enter to continue...)";
    getchar(); // Clearing buffer
    char c;
    while((c = getchar()) != '\n'){ };
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

    m_level[m_player.getPositionX()][m_player.getPositionY()] = '@';

    for(i = 0; i < 7; i++){
        for(j = 0; j < 24; j++)
            std::cout << m_level[i][j];
        std::cout << std::endl;
    }

    loadingFile.close();
};
