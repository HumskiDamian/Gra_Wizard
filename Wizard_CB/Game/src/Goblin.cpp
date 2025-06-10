#include "Goblin.h"

Goblin::Goblin()
    : Enemy(500.f, 300.f, 50.f, 50.f, 100.f, 10.f, 500.f, 50.f, 150.f) {
        body.setSize(sf::Vector2f(width, height));
    body.setPosition(x, y+1);
    body.setFillColor(sf::Color(44,91,1));
    body.setOrigin(25.f,25.f);
    canFly=false;

}

Goblin::~Goblin() {}

void Goblin::attack(Player& player) {
    Enemy::attack(player);

}
