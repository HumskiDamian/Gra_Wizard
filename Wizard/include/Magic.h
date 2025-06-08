#ifndef MAGIC_H
#define MAGIC_H


#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Collider.h"
class Magic
{
private:
	struct Shot {
		sf::Shape* shape;
		//sf::CircleShape * shape;          // Kszta³t magii (CircleShape lub RectangleShape)
		sf::Vector2f direction;       // Kierunek ruchu magii
		float distanceTraveled;       // Pokonana odleg³oœæ
		float maxDistance;            // Maksymalna odleg³oœæ
		float speed;                  // Prêdkoœæ magii
		float damage;                   // Obra¿enia magii

		Shot(sf::Shape* shape  , const sf::Vector2f& direction, float maxDistance, float speed, float damage)
			: shape(shape), direction(direction), distanceTraveled(0.f), maxDistance(maxDistance), speed(speed), damage(damage) {
		}
	};

	sf::CircleShape magic;
	std::vector<Shot> activeShots;
	float cooldown;                    // Czas odczekania miêdzy kolejnymi strza³ami
	float cooldownTimer;

	//magic stats
	float mana[6];
	float size[6];
	float damage[6];
	float expRange[6];
	float distanc[6];
	float time[6];
	float proficiency[6];
	bool isCircular[6];
	// types_of_magic fire_ball , water_ball , ice_spear , air_blade , rocks , holy_magic

	//float actTime;
	//float dist;
	float speed;
	float shorDirec;
	float sind, cosd;
	bool incantation;

	bool canActivMagic;
	bool existMagic;
	int actMagic;
	sf::Vector2f direction;
	sf::Vector2f playerPos;

public:
	Magic();
	~Magic();
	//inicjalizacja magii
	void initMagic();
	//set magic stats
	void setMana();
	void setSize();
	void setDamage();
	void setDist();
	void setExpRange();
	void setActMagic(int q);
	bool getExistMagic();


	void setIncantation_t();

	void setCenActiveMagic_f();
	float getDist();
	float getMana();
	float getTime();
	bool getCanActivMagic();


	//void shoot(const sf::Vector2f& pos);
    void shoot(const sf::Vector2f& startPosition, const sf::Vector2f& targetPosition);

	void updateMagic(float dTime);
	void render(sf::RenderTarget* target);
};


#endif // MAGIC_H
