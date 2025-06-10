#ifndef COLLIDER_PLATFORM_H
#define COLLIDER_PLATFORM_H

#include <SFML/Graphics.hpp>
#include <iostream>
class Collider_Platform
{
    public:
        Collider_Platform(sf::RectangleShape& body);
        virtual ~Collider_Platform();
        bool CheckCollider(Collider_Platform other);
        sf::Vector2f GetPosition();
        sf::Vector2f GetHalfSize();
        sf::FloatRect GetBounds();

    private:
        sf::RectangleShape& body;
        bool onGroud;

};

#endif // COLLIDER_PLATFORM_H
