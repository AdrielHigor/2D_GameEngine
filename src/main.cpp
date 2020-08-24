#include "Game.h"
// to compile, run the following code
// g++ -o ../teste main.cpp TextureManager.cpp Map.cpp Vector2D.cpp Game.cpp GameObject.cpp -lSDL2 -lSDL2main -lSDL2_image

Game *game = nullptr;

int main(int argc, char * argv[]){

    const int FPS = 60;
    const int frameDelay = 1000/ FPS;

    Uint32 frameStart;
    int frameTime;


    game = new Game();
    game->init("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

    while (game->running()) {

        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();
    
        frameTime = (SDL_GetTicks() - frameStart);

        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
    
    return 0;
}