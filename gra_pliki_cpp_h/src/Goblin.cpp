#include "Goblin.h"

Goblin::Goblin(float x, float y)
    : Enemy(x, y, 50.f, 50.f, 100.f, 10.f, 300.f, 50.f, 150.f) {
    body.setFillColor(sf::Color::Green);
}

Goblin::~Goblin() {}

void Goblin::attack(Player& player) {
    Enemy::attack(player);
    // Mo¿esz dodaæ specjalne zachowanie Goblina podczas ataku
}
