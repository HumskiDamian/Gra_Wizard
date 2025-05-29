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

#include "Player.h"
#include "Collider.h"
#include "Platform.h"
#include "GameSave.h"
#include "Goblin.h"

class Game
{
private:
	//GameSave saveManager;


	sf::VideoMode videomode;
	sf::RenderWindow* window;
	bool endgame;
	float a, b;
	bool onGround;
	float gravity;

    sf::View view;


	sf::Event windowEvent;
	//sf::RectangleShape floor;
	Player player;
	Platform plat;

	int points;


	sf::Font font;
	sf::Text guiText;
	void initVariables();
	void initWindow();

	sf::Vector2f direction;

public:
	Game();
	~Game();
	const bool running() const;
	void pollEvents();
	//const int randowizerType();

	//void spawnSwagBalls();
	void updateCollision();
	void update(float dTime);
	void render();

};

#endif // GAME_H
