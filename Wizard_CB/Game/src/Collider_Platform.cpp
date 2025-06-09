#include "Collider_Platform.h"

Collider_Platform::Collider_Platform()
{
    //ctor
}

Collider_Platform::~Collider_Platform()
{
    //dtor
}

bool Collider::CheckCollider(Collider other, sf::Vector2f& direction, float push)
{



}

sf::Vector2f Collider::GetPosition()
{
	return this->body.getPosition();
}

sf::Vector2f Collider::GetHalfSize()
{
	return this->body.getSize() / 2.f;
}
