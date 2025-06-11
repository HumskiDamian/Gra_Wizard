#ifndef PLAYER_H
#define PLAYER_H



#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Collider.h"
#include "Math.h"
//#include "Magic.h"



class Player
{
private:



    //stats
    sf::Font fridays;
    sf::Texture texture;
	sf::Text hpText;
	sf::RectangleShape hpStat;
	sf::RectangleShape hpStatL;
    sf::Text manaText;
    sf::RectangleShape manaStat;
    sf::RectangleShape manaStatL;
    sf::Text Timer;
    float TimerT;
	//shapes
	sf::RectangleShape shape;

    //timer
    float timerHeal;
    float timerBarrier;
    float timerApraisal;

	//stats
	float hp;
	float hpMax;
	float mana;
	float manaMax;
	int level;
	int experienc;

	//check delete
	bool canMove;
	bool onGround;
	float movementSpeed;
	float gravity;

	//inicjalizacja
	void initVariables();
	void initShape();

    float timerMag;
	//magic
	float hpTimer;
	float heal;
	int healMana;
	float barier;
	int barierMana;
	float barierRange;
	int apraisalMana;
	float time;
	bool apraisal;
	float apraisalTime;

	//jump
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;

	//Magic magic;

public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	const sf::RectangleShape& getShape() const;
	const float getHp() const;
	const float getHpMax() const;

	void takeDamage(const int damage);
	void gainHealth(const int health);
	void updateinput(float dTime, const sf::RenderTarget* target);
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target, float dTime, int* x, int* y);
	void render(sf::RenderTarget* target, sf::View* view);
	void levelUp();
	//void setGravity(bool g);
    sf::Vector2f GetPosition(){return shape.getPosition();}
	void OnCollision(sf::Vector2f direction);
	Collider getCollider();
	bool getApraisal();
	//Magic* magick();
	float takeRect(sf::RectangleShape& enemy);
	float getTimer();
    void setVelocity_y(float vel_y);
    void setMana(float m);
    float getMana();




};

#endif // PLAYER_H
