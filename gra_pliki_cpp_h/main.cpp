#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Game.h"

int main()
{
    srand(static_cast<unsigned>(time(0)));
    float deltaTime;
    Game game;
    sf::Clock deltaClock;
    while (game.running()) {
        deltaTime = deltaClock.restart().asSeconds();
        game.update(deltaTime);
        game.render();
    }

    return 0;
}
