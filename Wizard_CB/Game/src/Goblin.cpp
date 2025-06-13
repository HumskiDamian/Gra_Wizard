#include "Goblin.h"

Goblin::Goblin()
    : Enemy(500.f, 300.f, 50.f, 50.f, 100.f, 30.f, 1500.f, 80.f, 150.f) {


    body.setSize(sf::Vector2f(64.f, 64.f));
    body.setPosition(x, y);
    //body.setFillColor(sf::Color(144,91,50));
    body.setFillColor(sf::Color(255,255,255));
    body.setOrigin(25.f,25.f);
    canFly=false;

    currentFrameX = 0;
    currentFrameY = 2; // domyślnie chodzenie w lewo
    animationTimer = 0.f;
    animationSpeed = 0.1f; // czas między klatkami (sekundy)
    maxFrameX = 6;

    if(!texture1.loadFromFile("./image/a_goblin.png")) {
    std::cerr << "Nie uda³o siê za³adowaæ obrazka!\n";
    }
    texture1.setRepeated(true);
    //body.setTextureRect(sf::IntRect(0, 0, 320, 290));
    body.setTexture(&texture1);


}

Goblin::~Goblin() {}

void Goblin::attack(Player& player) {
    Enemy::attack(player);
    //body.setTexture(&texture1);
}
void Goblin::update(float deltaTime, Player& player){
    Enemy::update(deltaTime,player);
    body.setTexture(&texture1);
    //updateAnimation(deltaTime, player);
    updateAnimation(deltaTime, player);
}


void Goblin::updateAnimation(float deltaTime, const Player& player) {
    animationTimer += deltaTime;

    // Wybierz animację
    if (isPlayerInRange(player, attackRadius)) {
        currentFrameY = (player.getShape().getPosition().x > body.getPosition().x) ? 7 : 5;
        maxFrameX = 4;
    }
    else if (isPlayerInRange(player, detectionRadius)) {
        currentFrameY = (player.getShape().getPosition().x > body.getPosition().x) ? 3 : 1;
        maxFrameX = 6;
    }
    else {
        currentFrameY = 2;  // bezczynność
        currentFrameX = 0;
        maxFrameX = 0;
    }

    if (animationTimer >= animationSpeed) {
        currentFrameX++;
        if (currentFrameX > maxFrameX)
            currentFrameX = 0;
        animationTimer = 0.f;
    }

    // Ustaw odpowiedni fragment tekstury (32x64)
    body.setTextureRect(sf::IntRect(currentFrameX * 64, currentFrameY * 64, 64, 64));
}
