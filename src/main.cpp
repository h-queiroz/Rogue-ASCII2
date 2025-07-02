#include "../include/Game.h"

int main()
{
    Game game;

    game.loadMenu();

    game.loadLevel(1);
    
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
