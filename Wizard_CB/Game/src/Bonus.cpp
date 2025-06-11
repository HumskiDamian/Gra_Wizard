#include "Bonus.h"

Bonus::Bonus()
{
    isVisible=false;
    //ctor
}

Bonus::~Bonus()
{
    //dtor
}
void Bonus::setBonus(float a,sf::Vector2f pos,int typ){
    shape.setPosition(pos);
    typ=typ;
    point=a;
    shape.setFillColor(sf::Color::Green);

}
void Bonus::update(float dTime){


    if(isVisible){
        if(typ=1)
            typ_a.setFillColor(sf::Color::Red);
        if(typ=2)
            typ_a.setFillColor(sf::Color::Blue);
        if(typ=3)
            typ_a.setFillColor(sf::Color::Magenta);
    }


}
void Bonus::render(sf::RenderTarget* target){
    target->draw(this->shape);
    target->draw(this->typ_a);
}

int Bonus::getTyp(){
    return typ;
}
const sf::CircleShape& Bonus::getShape() const{
    return this->shape;
}
void Bonus::visible(bool b){
    isVisible=b;
}
float Bonus::getPoint(){
    return point;
}
