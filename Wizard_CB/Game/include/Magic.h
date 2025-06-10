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
#include "Shot_Magic.h"

class Magic
{

protected:
    float maxDist;
    float speed;
    float damage;
    float time;
    float mana;
    float body_size;
    float incantation;
    float x;
    float y;
    sf::Vector2f pos;
    sf::RectangleShape body;
public:
    Magic(float maxDist,
    float speed,
    float damage,
    float time,
    float mana,
    float body_size,
    float incantation,
    float x,
    float y);
	virtual~Magic();
	virtual void update(float deltaTime);
    virtual void render(sf::RenderTarget* target);
/*protected:


	//sf::CircleShape magic;
	float cooldown;                    // Czas odczekania miêdzy kolejnymi strza³ami
	float cooldownTimer;
    std::vector<Shot_Magic> activeShots;
	//magic stats
	float mana[2];
	float size[2];
	float damage[2];
	float expRange[2];
	float distanc[2];
	float time[2];
	float speed[2];
	float proficiency[2];

//=============================
	// [types_of_magic: fire_ball , water_ball]
//=============================
	//float actTime;
	//float dist;

    int x;
    int y;

	float shorDirec;
	float sind, cosd;
	bool incantation;

	float timerMag;

	bool canActivMagic;
	bool existMagic;
	int actMagic;
	sf::Vector2f playerPos;

public:
	Magic();
	~Magic();
	//inicjalizacja magii
	void initMagic();
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


    void shoot(sf::Vector2f startPosition,const sf::RenderTarget* target);

    float takeReck(sf::RectangleShape& enemy);
	void updateMagic(float dTime, int* x, int* y);
	void render(sf::RenderTarget* target);
	std::vector<Shot_Magic>* getVector();*/
};


#endif // MAGIC_H
