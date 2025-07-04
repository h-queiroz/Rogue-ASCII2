#include <iostream>

#include "../include/Game.h"

int main()
{
    Game game;

    game.startMenu();

    game.loadLevel(1);

    while(!game.getIsFinished()){
        game.drawLevel();
        game.drawPlayerStatus();
        game.drawLog();
        game.drawControls();
        game.promptPlayer();
        game.moveMonsters();
    }

    if(game.getPlayerHealth() <= 0){
        game.drawLevel();
        game.drawLog();
        std::cout << "\nGAME OVER!!!\n";
    }

    std::cout << "\nThanks for playing.\n";

    // Saving Game Feature
    // std::ofstream savingFile;
    // savingFile.open("savingFile.txt");
    // if(savingFile.fail()){
    //     perror("savingFile");
    //     return 1;
    // }
    // savingFile << "This is \none\nbig Test.";
    // savingFile.close();

    return 0;
};
