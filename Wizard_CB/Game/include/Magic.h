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
    float dis;
    float maxDist;
    float speed;
    float damage;
    float time;
    float mana;
    float body_size;
    float incantation;
    float x;
    float y;
    int tar_x;
    int tar_y;
    sf::Vector2f pos;
    sf::Vector2f direction;
    sf::CircleShape body;
    int typ;
    sf::Texture texture1;
    sf::Texture texture2;
public:
    Magic();
    void setMagic(float _maxDist,
    float _speed,
    float _damage,
    float _time,
    float _mana,
    float _body_size,
    float _incantation,
    sf::Vector2f _pos,
    int _tar_x,
    int _tar_y,
    int _typ, const sf::RenderTarget* target);
	~Magic();
	void update(float deltaTime);
    void render(sf::RenderTarget* target);
    float getDmg();
    sf::CircleShape getShape();
    bool isDist();
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
