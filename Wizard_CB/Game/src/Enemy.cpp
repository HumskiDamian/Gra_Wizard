#include "Enemy.h"

Enemy::Enemy(float x, float y, float width, float height, float health, float damage, float detectionRadius, float attackRadius, float speed)
    : health(health), damage(damage), detectionRadius(detectionRadius), attackRadius(attackRadius), speed(speed), isAttacking(false), x(x), y(y), width(width), height(height) {
    canFly=false;
    attackTimer=0.f;
    cy=1;
    cx=1;

}

Enemy::~Enemy() {}

void Enemy::update(float deltaTime, Player& player) {
    if(!(health<=0)){
    if (isPlayerInRange(player, detectionRadius)) {
        if (isPlayerInRange(player, attackRadius)) {
            if(attackTimer<=0){
                attack(const_cast<Player&>(player));
                attackTimer=1;
            }
        }
        else {
            moveToPlayer(player, deltaTime);
        }
    }
    if(attackTimer>0){
        attackTimer-=deltaTime;
    }
    if(body.getPosition().y<=500)
    body.move(sf::Vector2f(0.f,981/2*deltaTime));
    //gravity
    }
}
//render
void Enemy::render(sf::RenderTarget* target) {
    target->draw(body);
}

bool Enemy::isPlayerInRange(const Player& player, float range) const {
    if(!(health<=0)){
        sf::Vector2f playerPos = player.getShape().getPosition();
    sf::Vector2f enemyPos = body.getPosition();
    float distance = sqrt(pow(playerPos.x - enemyPos.x, 2) + pow(playerPos.y - enemyPos.y, 2));
    return distance <= range;

    }

}

void Enemy::moveToPlayer(const Player& player, float deltaTime) {
    if(!(health<=0)){
        sf::Vector2f playerPos = player.getShape().getPosition();
    sf::Vector2f enemyPos = body.getPosition();
    sf::Vector2f direction = playerPos - enemyPos;
    if(sqrt(direction.x * direction.x + direction.y * direction.y)>40){
        float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0.f) {
        direction /= length;
    }

    body.move(direction * speed * deltaTime*cx);

    }
    }


}

void Enemy::attack(Player& player) {
    if (!isAttacking) {
        player.takeDamage(damage);
    }
}

bool Enemy::isDead() const {
    return health <= 0;
}
void Enemy::takeDamage(float d){
    this->health-=d;
}
void Enemy::setPos(int d){
    body.setPosition(d,400);
}
sf::RectangleShape& Enemy::getShape()
{
	return this->body;
}
Collider Enemy::GetCollider()
{
	return Collider(this->body);
}
void Enemy::setDmg_hp(int dif){
    damage*=dif;
    health*=dif;
}

void Enemy::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.f) {

		cx=0;
	}
	else if (direction.x > 0.f) {

		cx=0;

	}

	if (direction.y <= 0.f) {


	}
	else if (direction.y > 0.f) {



	}
	else cx=1;
}

