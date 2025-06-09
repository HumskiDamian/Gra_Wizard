#ifndef SHOT_MAGIC_H
#define SHOT_MAGIC_H

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

class Shot_Magic
{
private:
    //odwo³¹nia do tej klasy w innych klasach-----------------------------------------------------
    sf::CircleShape shape;
    //sf::RectangleShape shape;
    sf::Vector2f direction;
    float distanceTraveled;
    float maxDistance;
    float speed;
    float damage;
    float dis;

public:

    Shot_Magic(sf::Vector2f pos,float speed, float dis, const sf::RenderTarget* target, int x, int y);
    virtual ~Shot_Magic();
    void update(float dTime);
    void render(sf::RenderTarget* target);
    bool isMaxDistance();
    float getDamage();
    //sf::RectangleShape getShape();
    sf::CircleShape& getShape();
protected:
};

#endif // SHOT_MAGIC_H
