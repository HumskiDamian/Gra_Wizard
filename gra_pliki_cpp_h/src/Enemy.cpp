#include "Enemy.h"

Enemy::Enemy(float x, float y, float width, float height, float health, float damage, float detectionRadius, float attackRadius, float speed)
    : health(health), damage(damage), detectionRadius(detectionRadius), attackRadius(attackRadius), speed(speed), isAttacking(false) {
    body.setSize(sf::Vector2f(width, height));
    body.setPosition(x, y);
    body.setFillColor(sf::Color::Red); // Domyœlny kolor przeciwnika
}

Enemy::~Enemy() {}

void Enemy::update(float deltaTime, const Player& player) {
    if (isPlayerInRange(player, detectionRadius)) {
        if (isPlayerInRange(player, attackRadius)) {
            attack(const_cast<Player&>(player)); // Atakowanie gracza
        }
        else {
            moveToPlayer(player, deltaTime); // Poruszanie siê w kierunku gracza
        }
    }
}

void Enemy::render(sf::RenderTarget& target) {
    target.draw(body);
}

bool Enemy::isPlayerInRange(const Player& player, float range) const {
    sf::Vector2f playerPos = player.getShape().getPosition();
    sf::Vector2f enemyPos = body.getPosition();
    float distance = sqrt(pow(playerPos.x - enemyPos.x, 2) + pow(playerPos.y - enemyPos.y, 2));
    return distance <= range;
}

void Enemy::moveToPlayer(const Player& player, float deltaTime) {
    sf::Vector2f playerPos = player.getShape().getPosition();
    sf::Vector2f enemyPos = body.getPosition();
    sf::Vector2f direction = playerPos - enemyPos;

    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0.f) {
        direction /= length; // Normalizacja wektora
    }

    body.move(direction * speed * deltaTime);
}

void Enemy::attack(Player& player) {
    if (!isAttacking) {
        player.takeDamage(damage); // Gracz otrzymuje obra¿enia
        isAttacking = true; // Flaga ataku (mo¿esz dodaæ cooldown)
    }
}

bool Enemy::isDead() const {
    return health <= 0;
}
