#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <fstream>
#include "Game.h"
#include "Menu.h"

int main()
{
    srand(static_cast<unsigned>(time(0)));
    float deltaTime;
    Game game;
    sf::Clock deltaClock;
    /*Menu menu();
    int result = menu.run();
    if (result == 0) {
        return 0; // Zako�czenie programu
    }*/
    while (game.running()) {
        deltaTime = deltaClock.restart().asSeconds();
        game.update(deltaTime);
        game.render();
        if(game.getEndgame()==true){

            break;
        }


    }

    return 0;
}
