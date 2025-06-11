#include "Trap.h"

Trap::Trap()
{
    //texture.loadFromFile("./image/zamek.png");
    if (!texture.loadFromFile("./image/trap.jpg")) {
		std::cerr << "B³¹d ³adowania tekstury trawa1.png" << std::endl;
	}
	texture.setRepeated(true);
    activeTrap=true;
    trap.setSize(sf::Vector2f(100.f,100.f));
    trap.setOrigin(50.f,50.f);
    trap.setPosition(200.f,520.f);
    //trap.setFillColor(sf::Color(255,255,255,0));
    apraisal=false;
    trap.setTexture(&texture);
    trap.setFillColor(sf::Color(255,255,255,0));
    //ctor
}

Trap::~Trap()
{
    //dtor
}
void Trap::update(Player* player){
    trap.setTexture(&texture);
    if(trap.getGlobalBounds().intersects(player->getShape().getGlobalBounds())){
        activeTrap=false;
        //trap.setTexture(&texture);
        trap.setFillColor(sf::Color(255,255,255,255));
        player->takeDamage(50.f);
    }
    if(activeTrap){
        if(apraisal)
        trap.setFillColor(sf::Color(255,255,255,100));
    else
        trap.setFillColor(sf::Color(255,255,255,0));
    }

}
void Trap::render(sf::RenderTarget* target){
    target->draw(this->trap);
}
void Trap::setApraisal(bool a){
    apraisal=a;
}
void Trap::setPos(int q){
    trap.setPosition(q,520);
}
