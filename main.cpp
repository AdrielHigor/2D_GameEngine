#include "Game.hpp"
// to compile, run the following code
// g++ -o Game main.cpp Game.cpp -lSDL2 -lSDL2main 

Game *game = nullptr;

int main(int argc, char * argv[]){

    game = new Game();
    
    game->init("Teste", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, true);

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    
    return 0;
}