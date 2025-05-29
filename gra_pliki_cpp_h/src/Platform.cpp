#include "Platform.h"

Platform::Platform()
{

	this->platform.setSize(sf::Vector2f(10.f, 10.f));
	this->platform.setPosition(sf::Vector2f(0.f, 0.f));
	this->platform.setOrigin(sf::Vector2f(10.f, 10.f) / 2.f);
}

Platform::Platform(sf::Vector2f size, sf::Vector2f pos)
{
	this->platform.setSize(size);
	this->platform.setPosition(pos);
	this->platform.setOrigin(size / 2.f);
}

Platform::~Platform()
{
}

void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(this->platform);
}

Collider Platform::GetCollider()
{
	return Collider(this->platform);
}

void Platform::render(sf::RenderTarget* target)
{
	target->draw(this->platform);
}

void Platform::setSize(sf::Vector2f size)
{
	this->platform.setSize(size);
	this->platform.setOrigin(size / 2.f);
}

void Platform::setPos(sf::Vector2f pos)
{
	this->platform.setPosition(pos);
}
