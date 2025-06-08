#ifndef PLAYER_H
#define PLAYER_H



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
#include "Magic.h"


class Player
{
private:
	//shapes
	sf::RectangleShape shape;




	//stats
	float hp;
	float hpMax;
	float mana;
	float manaMax;
	int level;
	int experienc;

	//check delete
	bool canMove;
	float movementSpeed;

	//inicjalizacja
	void initVariables();
	void initShape();


	//magic
	float heal;
	int healMana;
	float barier;
	int barierMana;
	float barierRange;
	int apraisalMana;
	float time;

	//jump
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;

	Magic magic;

public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	const sf::RectangleShape& getShape() const;
	const int& getHp() const;
	const int& getHpMax() const;

	void takeDamage(const int damage);
	void gainHealth(const int health);
	void updateinput(float dTime);
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target, float dTime);
	void render(sf::RenderTarget* target);
	void levelUp();
    sf::Vector2f GetPosition(){return shape.getPosition();}
	void OnCollision(sf::Vector2f direction);
	Collider getCollider();


};

#endif // PLAYER_H
