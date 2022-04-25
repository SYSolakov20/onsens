#include "game.h"

int main()
{
    sf::Window newWindow(sf::VideoMode(1545, 810), "", sf::Style::Close);
    game game(newWindow);
    game.start(newWindow);
    return 0;
}