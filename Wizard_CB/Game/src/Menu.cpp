#include "Menu.h"

Menu::Menu() {
    this->window = new sf::RenderWindow(sf::VideoMode(800,600), "menu start");


    // Za³aduj czcionkê
    if (!font.loadFromFile("Fonts/CalligraphyFLF.ttf")) {
        throw "Brak czcionki!";
    }
    krok=0;
    title.setFont(font);
    title.setString("Wizard");
    title.setCharacterSize(70);
    title.setFillColor(sf::Color::White);
    title.setPosition(300, 90);
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
    //poziom trudności
    dif.setFont(font);
    dif.setString("choose difficulty:");
    dif.setCharacterSize(50);
    dif.setFillColor(sf::Color::White);
    dif.setPosition(300, 100);


    easy.setFont(font);
    easy.setString("EASY");
    easy.setCharacterSize(50);
    easy.setFillColor(sf::Color::White);
    easy.setPosition(300, 200);

    // Konfiguracja przycisku EXIT
    hard.setFont(font);
    hard.setString("HARD");
    hard.setCharacterSize(50);
    hard.setFillColor(sf::Color::Red);
    hard.setPosition(300, 300);
}
Menu::~Menu(){
delete this->window;
}

int Menu::run() {
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                return 0;

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                if(krok!=0){
                    if (easy.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 1;

                if (hard.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 2;
                }
                if(krok==0){
                    if (startText.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    krok=1;

                    if (exitText.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    return 0; // Zamkniêcie gry
                }
                sf::sleep(sf::seconds(0.5));
            }
        }

        window->clear(sf::Color::Black);
        if(krok==0){
            window->draw(title);
            window->draw(startText);
            window->draw(exitText);
        }
        if(krok!=0){
            window->draw(dif);
            window->draw(easy);
            window->draw(hard);
        }
        window->display();
    }

    return 0; // Domyslnie zamyka program
}
