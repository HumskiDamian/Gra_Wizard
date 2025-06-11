#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <sstream>

class Menu
{
 private:
    sf::RenderWindow* window;
    sf::Font font;
    sf::Text title;
    sf::Text startText;
    sf::Text exitText;
    sf::Text dif;
    sf::Text easy;
    sf::Text hard;
    int krok;

public:
    Menu();
    ~Menu();
    int run(); // 1 - start, 0 - exit
};

#endif // MENU_H
