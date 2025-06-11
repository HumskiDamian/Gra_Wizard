#include "Platform.h"

Platform::Platform()
{

	this->platform.setSize(sf::Vector2f(10.f, 10.f));
	this->platform.setPosition(sf::Vector2f(0.f, 0.f));
	this->platform.setOrigin(sf::Vector2f(10.f, 10.f) / 2.f);
	//texture.loadFromFile("./image/trawa1.png");
	//platform.setTexture(&texture);
	//this->platform.setFillColor(sf::Color(86,240,74,255));
	if (!texture.loadFromFile("./image/trawa1.png")) {
        this->platform.setFillColor(sf::Color(102,204,0));
		std::cerr << "Bad ³adowania tekstury trawa1.png" << std::endl;

	}
	else{
        texture.setRepeated(true);
    //platform.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
	this->platform.setTexture(&texture);
	}


}

Platform::Platform(sf::Vector2f size, sf::Vector2f pos)
{
	this->platform.setSize(size);
	this->platform.setPosition(pos);
	this->platform.setOrigin(size / 2.f);

	if (!texture.loadFromFile("./image/trawa1.png")) {
        this->platform.setFillColor(sf::Color(102,204,0));
		std::cerr << "B³¹d ³adowania tekstury trawa1.png" << std::endl;
	}
	//texture.setRepeated(true);
    //platform.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
	else this->platform.setTexture(&texture);
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
	if (!texture.loadFromFile("./image/trawa1.png")) {
        this->platform.setFillColor(sf::Color(102,204,0));
		std::cerr << "B³¹d ³adowania tekstury trawa1.png" << std::endl;

	}
	//texture.setRepeated(true);
    //platform.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
    else this->platform.setTexture(&texture);
}

void Platform::setPos(sf::Vector2f pos)
{
	this->platform.setPosition(pos);
}
void Platform::setColor(int x, int y, int z, int a){
    this->platform.setFillColor(sf::Color(x,y,z,a));
}

sf::RectangleShape Platform::getShape(){
    return platform;
}
