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
    Menu menu;
    int result = menu.run();
    if (result == 0) {
        return 0; // Zakończenie programu, jeśli użytkownik kliknął "Exit" lub zamknął okno
    }

    float deltaTime;
    Game game(result);
    sf::Clock deltaClock;
    /*Menu menu();
    int result = menu.run();
    if (result == 0) {
        return 0; // Zakoñczenie programu
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
