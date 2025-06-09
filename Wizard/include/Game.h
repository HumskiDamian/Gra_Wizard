#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <fstream>

#include "Player.h"
#include "Collider.h"
#include "Platform.h"
#include "GameSave.h"
#include "Goblin.h"
#include "Trap.h"
class Game
{
private:
    //GameSave saveManager;


    sf::VideoMode videomode;
    sf::RenderWindow* window;

    sf::Texture las;
    sf::Sprite slas;

    sf::Texture texture;
    sf::RectangleShape ending;
    bool endgame;
    float a, b;
    bool onGround;
    float gravity;

    sf::View view;
    int x,y;
    int trapLos;
    int goblinLos;
    int platLos;

    sf::Event windowEvent;
    //sf::RectangleShape floor;
    Player player;
    Platform plat;
    Platform Lwall;
    std::vector<Trap> traps;
    std::vector<Goblin> goblins;
    std::vector<Platform> platforms;

    Goblin goblin;
    Trap trap;



    sf::Vector2i mouse;
    sf::Text guiText;
    void initVariables();
    void initWindow();

    sf::Vector2f direction;

public:
    Game();
    ~Game();
    const bool running() const;
    void pollEvents();



    void updateCollision();
    void update(float dTime);
    void render();
    bool getEndgame();

};

#endif // GAME_H
