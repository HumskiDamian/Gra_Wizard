#include "Skeleton.h"


Skeleton::Skeleton()
    : Enemy(500.f, 300.f, 50.f, 50.f, 200.f, 40.f, 1800.f, 80.f, 200.f) {
    frameSize = sf::Vector2i(257, 300);
    currentFrameX = 0;
    currentFrameY = 2;
    animationTimer = 0.f;
    animationSpeed = 0.1f;
    maxFrameX = 6;

    body.setSize(sf::Vector2f(85.f, 100.f));
    body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
    body.setPosition(x, y);
    body.setFillColor(sf::Color::White);
    canFly = false;

    if (!texture2.loadFromFile("./image/skeletons.png")) {
        std::cerr << "Nie udało się załadować obrazka!\n";
    }

    texture2.setRepeated(false);
    body.setTexture(&texture2);
    body.setTextureRect(sf::IntRect(0, currentFrameY * frameSize.y, frameSize.x, frameSize.y));

}

Skeleton::~Skeleton() {}

void Skeleton::attack(Player& player) {
    Enemy::attack(player);
    body.setTexture(&texture2);
}
void Skeleton::update(float deltaTime, Player& player){
    Enemy::update(deltaTime,player);
    body.setTexture(&texture2);
    updateAnimation(deltaTime, player);
}

void Skeleton::updateAnimation(float deltaTime, const Player& player) {
    animationTimer += deltaTime;

    sf::Vector2f playerPos = player.getShape().getPosition();
    sf::Vector2f selfPos = body.getPosition();
    bool isFacingRight = playerPos.x > selfPos.x;


    if (isPlayerInRange(player, attackRadius)) {
        currentFrameY = 3; // atakowanie zawsze w 4 wierszu (row 3)
        maxFrameX = 3;

    }
    else if (isPlayerInRange(player, detectionRadius)) {
        currentFrameY = isFacingRight ? 2 : 1;
        maxFrameX = 6;
    }
    else {
        currentFrameY = 0;
        currentFrameX = 0;
        maxFrameX = 0;
    }

    if (animationTimer >= animationSpeed) {
        animationTimer = 0.f;
        currentFrameX++;
        if (currentFrameX > maxFrameX)
            currentFrameX = 0;
    }

    int texX = currentFrameX * frameSize.x;
    int texY = currentFrameY * frameSize.y;

    if (!isFacingRight && (currentFrameY == 1 || currentFrameY == 3)) {
        body.setTextureRect(sf::IntRect((currentFrameX + 1) * frameSize.x, texY, -frameSize.x, frameSize.y));
    }
    else {
        body.setTextureRect(sf::IntRect(texX, texY, frameSize.x, frameSize.y));
    }
}
