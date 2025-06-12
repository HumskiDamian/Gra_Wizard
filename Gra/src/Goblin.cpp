#include "Goblin.h"

Goblin::Goblin()
    : Enemy(500.f, 300.f, 50.f, 50.f, 100.f, 30.f, 1500.f, 80.f, 150.f) {
    body.setSize(sf::Vector2f(width, height));
    body.setPosition(x, y);
    //body.setFillColor(sf::Color(144,91,50));
    body.setFillColor(sf::Color(255,255,255));
    body.setOrigin(25.f,25.f);
    canFly=false;

    if(!texture1.loadFromFile("./image/goblin.png")) {
    std::cerr << "Nie uda³o siê za³adowaæ obrazka!\n";
    }
    texture1.setRepeated(true);
    //body.setTextureRect(sf::IntRect(0, 0, 320, 290));
    body.setTexture(&texture1);

}

Goblin::~Goblin() {}

void Goblin::attack(Player& player) {
    Enemy::attack(player);
    body.setTexture(&texture1);
}
void Goblin::update(float deltaTime, Player& player){
    Enemy::update(deltaTime,player);
    body.setTexture(&texture1);
}
