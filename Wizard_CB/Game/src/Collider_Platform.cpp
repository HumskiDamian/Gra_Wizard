#include "Collider_Platform.h"

Collider_Platform::Collider_Platform(sf::RectangleShape& body) :
	body(body)
{
    onGroud=false;
    //ctor
}

Collider_Platform::~Collider_Platform()
{
    //dtor

}

bool Collider_Platform::CheckCollider(Collider_Platform other)
{
    sf::FloatRect otherBounds = other.GetBounds();
    sf::FloatRect thisBounds = GetBounds();

    if(otherBounds.left-(thisBounds.left+thisBounds.width)<=0){
        return true;
    }
    if(otherBounds.left-(thisBounds.left+thisBounds.width)>0){
        return false;
    }
    if(otherBounds.top-(thisBounds.top+thisBounds.height)<=0){
        return true;
    }
    if(otherBounds.top-(thisBounds.top+thisBounds.height)>0){
        return false;
    }

}

sf::Vector2f Collider_Platform::GetPosition()
{
	return this->body.getPosition();
}

sf::Vector2f Collider_Platform::GetHalfSize()
{
	return this->body.getSize() / 2.f;
}
sf::FloatRect Collider_Platform:: GetBounds()
{
    return this->body.getGlobalBounds();
}
