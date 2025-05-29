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
	/*sf::RectangleShape enemy;
	float hpmax;
	float hp;
	float damage;


public:
	Enemy();
	~Enemy();
	void initEnemy(float hpMax, float damage);
	void updateEnemy();
	void atakEnemy();*/

    sf::RectangleShape body;     // Wygl�d przeciwnika
    float health;                // Zdrowie przeciwnika
    float damage;                // Obra�enia, jakie zadaje
    float detectionRadius;       // Zasi�g wykrywania gracza
    float attackRadius;          // Zasi�g ataku
    float speed;                 // Pr�dko�� poruszania si�
    bool isAttacking;            // Flaga ataku

public:
    Enemy(float x, float y, float width, float height, float health, float damage, float detectionRadius, float attackRadius, float speed);
    virtual ~Enemy();

    virtual void update(float deltaTime, const Player& player);
    virtual void render(sf::RenderTarget& target);

    bool isPlayerInRange(const Player& player, float range) const;
    virtual void moveToPlayer(const Player& player, float deltaTime);
    virtual void attack(Player& player);

    bool isDead() const;

};


#endif // ENEMY_H
