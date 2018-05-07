#include <memory>
#include "../headers/main.h"
#include "../headers/GameLoop.h"

using namespace std;

int main(int argc, char *argv[])
{
//    osSetup();

    //create instance of game loop
    auto gameLoop = make_shared<GameLoop>();

    //... and run the game
    gameLoop->run();

    return 0;
}
