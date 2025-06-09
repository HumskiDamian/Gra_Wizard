#ifndef COLLIDER_PLATFORM_H
#define COLLIDER_PLATFORM_H


class Collider_Platform
{
    public:
        Collider_Platform();
        virtual ~Collider_Platform();
        bool CheckCollider(Collider other, sf::Vector2f& direction, float push);
        sf::Vector2f GetPosition();
        sf::Vector2f GetHalfSize();

    private:
	sf::RectangleShape& body;
	bool onGroud;

};

#endif // COLLIDER_PLATFORM_H
