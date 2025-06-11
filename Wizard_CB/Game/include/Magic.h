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
};


#endif // MAGIC_H
