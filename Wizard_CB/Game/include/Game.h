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
#include "Collider_Platform.h"
#include "Platform.h"
#include "GameSave.h"
#include "Goblin.h"
#include "Trap.h"
#include "Bonus.h"
#include "Magic.h"
#include "Skeleton.h"
class Game
{
private:
    sf::RectangleShape background;
    sf::Texture bgTexture;

	sf::VideoMode videomode;
	sf::RenderWindow* window;

	sf::Texture las;
    sf::Sprite slas;

	sf::Texture texture;
	sf::RectangleShape ending;
	bool endgame;
	bool win;
	float a, b;
	bool onGround;
	float gravity;

    sf::View view;
    int x,y;
    int trapLos;
    int goblinLos;
    int skelLos;
    int platLos;

	sf::Event windowEvent;
	Player player;
	Platform plat;
	Platform Lwall;
	std::vector<Trap> traps;
    std::vector<Goblin> goblins;
    std::vector<Platform> platforms;
    std::vector<Magic> magic;
    std::vector<Bonus> bonus;
    std::vector<Skeleton> skeletons;

	Goblin goblin;
	Trap trap;

    //=======magic
    float proficiency;
    int typ;
    float mag_t;

    sf::Vector2i mouse;
	sf::Text guiText;
	void initVariables(int dif);
	void initWindow();

	sf::Vector2f direction;

public:
	Game(int dif);
	~Game();
	const bool running() const;
	void pollEvents();



	void updateCollision();
	void update(float dTime);
	void render();
    bool getEndgame();
    bool getWin();

};

#endif // GAME_H
