#ifndef ENEMY_H
#define ENEMY_H


#include <iostream>
#include <vector>
#include <ctime>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Collider.h"
#include "Player.h"
#include <cmath>

class Enemy
{
protected:

    float cy,cx;
    sf::RectangleShape body;
    float health;
    float damage;
    float detectionRadius;
    float attackRadius;
    float speed;
    bool isAttacking;
    float x;
    float y;
    float width;
    float height;
    bool canFly;
    float attackTimer;
    sf::Texture texture;
    sf::Sprite sprite;
    int frameWidth;
    int frameHeight;
    int frameCount;
    int currentFrame;
    float frameTime;

public:
    Enemy(float x, float y, float width, float height, float health, float damage, float detectionRadius, float attackRadius, float speed);
    virtual ~Enemy();

    virtual void update(float deltaTime, Player& player);
    virtual void render(sf::RenderTarget* target);

    bool isPlayerInRange(const Player& player, float range) const;
    virtual void moveToPlayer(const Player& player, float deltaTime);
    virtual void attack(Player& player);
    virtual void takeDamage(float d);
    virtual void setPos(int d);
    sf::RectangleShape& getShape();
    virtual void setDmg_hp(int dif);
    void OnCollision(sf::Vector2f direction);
    bool isDead() const;
    virtual Collider GetCollider();
};


#endif // ENEMY_H
