#include "Skeleton.h"


Skeleton::Skeleton()
    : Enemy(500.f, 300.f, 50.f, 50.f, 200.f, 40.f, 1800.f, 80.f, 200.f) {
    body.setSize(sf::Vector2f(width, height));
    body.setPosition(x, y);
    //body.setFillColor(sf::Color(144,91,50));
    body.setFillColor(sf::Color(255,255,255));
    body.setOrigin(25.f,25.f);
    canFly=false;

    if(!texture2.loadFromFile("./image/szkielet.png")) {
    std::cerr << "Nie uda³o siê za³adowaæ obrazka!\n";
    }
    texture2.setRepeated(true);
    //body.setTextureRect(sf::IntRect(0, 0, 320, 290));
    body.setTexture(&texture2);

}

Skeleton::~Skeleton() {}

void Skeleton::attack(Player& player) {
    Enemy::attack(player);
    body.setTexture(&texture2);
}
void Skeleton::update(float deltaTime, Player& player){
    Enemy::update(deltaTime,player);
    body.setTexture(&texture2);
}
