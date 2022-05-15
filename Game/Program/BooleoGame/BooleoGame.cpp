#include "game.h"

int WinMain(HINSTANCE hInstance,
            HINSTANCE hPrevInstance,
            LPSTR lpCmdLine,
            int nShowCmd)
{
    Game* game = new Game();
    game->start();
    return 0;
}