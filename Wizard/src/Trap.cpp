#include "Trap.h"

Trap::Trap()
{
    activeTrap=true;
    trap.setSize(sf::Vector2f(100.f,100.f));
    trap.setOrigin(50.f,50.f);
    trap.setPosition(200.f,520.f);
    trap.setFillColor(sf::Color(255,255,255,0));
    apraisal=false;
    //ctor
}

Trap::~Trap()
{
    //dtor
}
void Trap::update(Player* player){
    if(trap.getGlobalBounds().intersects(player->getShape().getGlobalBounds())){
        activeTrap=false;
        trap.setFillColor(sf::Color(50,50,50,255));
        player->takeDamage(50.f);
    }
    if(activeTrap){
        if(apraisal)
            trap.setFillColor(sf::Color(40,40,40,150));
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
