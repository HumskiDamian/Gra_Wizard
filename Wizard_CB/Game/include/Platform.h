#ifndef PLATFORM_H
#define PLATFORM_H


#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Collider.h"
class Platform
{
private:
    sf::Texture texture;
    sf::Sprite platf;
	sf::RectangleShape platform;
public:
	Platform();
	Platform(sf::Vector2f size, sf::Vector2f pos);
	~Platform();
	void Draw(sf::RenderWindow& window);
	Collider GetCollider();
	void render(sf::RenderTarget* target);
	void setSize(sf::Vector2f size);
	void setPos(sf::Vector2f pos);
	void setColor(int x, int y, int z, int a);
	sf::RectangleShape getShape();

};




#endif // PLATFORM_H
