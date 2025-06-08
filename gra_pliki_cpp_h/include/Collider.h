#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>

class Collider
{
private:
	sf::RectangleShape& body;
	bool onGroud;

public:
	Collider(sf::RectangleShape& body);
	~Collider();
	void Move(float dx, float dy);
	bool CheckCollider(Collider other, sf::Vector2f& direction, float push);
	sf::Vector2f GetPosition();
	sf::Vector2f GetHalfSize();

};

#endif // COLLIDER_H
