#ifndef ENDWINDOW_H
#define ENDWINDOW_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <sstream>

class EndWindow
{
    public:
        EndWindow(bool e);
        ~EndWindow();
        void run();

    protected:

    private:
    sf::RenderWindow* window;
    sf::Font font;
    sf::Text winText;
    sf::Text lostText;
    bool isWin;
};

#endif // ENDWINDOW_H
