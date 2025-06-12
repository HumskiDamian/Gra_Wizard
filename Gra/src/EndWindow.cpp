#include "EndWindow.h"

EndWindow::EndWindow(bool e)
{
    isWin=e;
    this->window = new sf::RenderWindow(sf::VideoMode(800,600), "Wizard");


    // Za³aduj czcionkê
    if (!font.loadFromFile("Fonts/CalligraphyFLF.ttf")) {
        throw "Brak czcionki!";
    }
    lostText.setFont(font);
    lostText.setString("GAME OVER");
    lostText.setCharacterSize(130);
    lostText.setFillColor(sf::Color::Red);
    lostText.setPosition(20, 250);

    winText.setFont(font);
    winText.setString("YOU WIN");
    winText.setCharacterSize(130);
    winText.setFillColor(sf::Color::White);
    winText.setPosition(20, 250);

}

EndWindow::~EndWindow()
{
    //dtor
    delete this->window;
}

void EndWindow::run() {
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->window->close();
        }

        window->clear(sf::Color::Black);

        if(isWin==true){
            window->draw(winText);
        }
        if(isWin==false){
        window->draw(lostText);
        }
        window->display();
    }

}
