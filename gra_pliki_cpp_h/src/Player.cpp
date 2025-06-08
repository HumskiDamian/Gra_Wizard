#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 500.f;
	this->hpMax = 100;
	this->manaMax = 100;
	this->mana = manaMax;
	this->hp = hpMax;
	/*this->go.x = 0;
	this->go.y = 0;*/
	this->jumpHeight = 200;
	this->level = 1;
	this->experienc = 0;
	this->time = 0.f;
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setSize(sf::Vector2f(25.f, 50.f));
	this->shape.setOrigin(sf::Vector2f(50.f, 50.f) / 2.f);
}


Player::Player(float x, float y)
{
	this->shape.setPosition(550, 50);
	this->initVariables();
	this->initShape();
}

Player::~Player()
{

}

const sf::RectangleShape& Player::getShape() const
{

	return this->shape;
}

const int& Player::getHp() const
{

	return this->hp;
}

const int& Player::getHpMax() const
{

	return this->hpMax;
}

void Player::takeDamage(const int damage)
{
	if (this->hp > 0)
		this->hp -= damage;
	if (this->hp < 0)
		this->hp = 0;
}

void Player::gainHealth(const int health)
{
	if (this->hp < this->hpMax)
		this->hp += health;
	if (this->hp > this->hpMax)
		this->hp = hpMax;
}

void Player::updateinput(float dTime)
{
	//keyboard----------------------------------------
	velocity.x *= 0.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->velocity.x -= movementSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->velocity.x += movementSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->canJump) {
		this->canJump = false;
		this->velocity.y -= sqrt(2.f * 981.f * jumpHeight);

	}
	//std::cout << canJump << "\n";
	this->velocity.y += 981.f * dTime;

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->shape.move(0.f, -this->movementSpeed*dTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->shape.move(0.f, this->movementSpeed*dTime);
	}*/
	this->shape.move(velocity * dTime);

	//mouse------------------------------
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (this->mana >= this->magic.getMana() && magic.getCanActivMagic()) {
			this->mana -= magic.getMana();
			magic.shoot(shape.getPosition() + sf::Vector2f(shape.getSize().x / 2.f, shape.getSize().y / 2.f),static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
			magic.setIncantation_t();
		}
		std::cout << "prawy_przycisk---------------------------------" << "\n";
	}



}
void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
	////Left
	//if (this->shape.getGlobalBounds().left <= 0.f) {
	//	this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
	//}
	////Right
	//if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x) {
	//	this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	//}
	//if (this->shape.getGlobalBounds().top <= 0.f) {
	//	this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
	//}
	//if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y) {
	//	this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);
	//}

}

void Player::update(const sf::RenderTarget* target, float dTime)
{
	this->updateinput(dTime);
	this->levelUp();
	this->updateWindowBoundsCollision(target);

	magic.updateMagic(dTime);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	magic.render(target);
}

void Player::levelUp()
{
	if (this->experienc >= 200 * this->level) {
		this->experienc = 0;
		level += 1;
		this->manaMax += 100;
		this->hpMax += 50;
	}


}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.f) {
		//collisionj on left
		this->velocity.x = 0.f;
	}
	else if (direction.x > 0.f) {
		//collision on right
		this->velocity.x = 0.f;
	}
	if (direction.y < 0.f) {
		this->velocity.y = 0.f;
		this->canJump = true;
	}
	else if (direction.y > 0.f) {
		this->velocity.y = 0.f;
	}
}

Collider Player::getCollider()
{
	return Collider(this->shape);
}
