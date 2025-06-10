#include "Menu.h"

Menu::Menu() {
    this->window = new sf::RenderWindow(sf::VideoMode(800,600), "menu start");
    //this->window = win;

    // Za³aduj czcionkê
    if (!font.loadFromFile("Fonts/CalligraphyFLF.ttf")) {
        throw "Brak czcionki!";
    }

    // Konfiguracja przycisku START
    startText.setFont(font);
    startText.setString("Start");
    startText.setCharacterSize(50);
    startText.setFillColor(sf::Color::White);
    startText.setPosition(300, 200);

    // Konfiguracja przycisku EXIT
    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(50);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(300, 300);
}
Menu::~Menu(){}

int Menu::run() {
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                return 0;

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

                if (startText.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 1; // Start gry

                if (exitText.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 0; // Zamkniêcie gry
            }
        }

        window->clear(sf::Color::Black);
        window->draw(startText);
        window->draw(exitText);
        window->display();
    }

    return 0; // Domyœlnie zamyka program
}
