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
void Bonus::setBonus(float a,sf::Vector2f pos,int _typ){
    shape.setPosition(pos);
    shape.setRadius(20);
    typ_a.setRadius(40);
    typ=_typ;

    point=a;
    shape.setFillColor(sf::Color::Green);
    typ_a.setPosition(sf::Vector2f(pos.x-20,pos.y-20));


}
void Bonus::update(float dTime){


    if(isVisible){
            //std::cout<<typ<<std::endl;
        if(typ==1)
            typ_a.setFillColor(sf::Color::Red);
        if(typ==2)
            typ_a.setFillColor(sf::Color::Blue);
        if(typ==3)
            typ_a.setFillColor(sf::Color::Magenta);
    }
    else
        typ_a.setFillColor(sf::Color(0,0,0,0));


}
void Bonus::render(sf::RenderTarget* target){
    target->draw(typ_a);
    target->draw(shape);
}

int Bonus::getTyp(){
    return typ;
}
const sf::CircleShape& Bonus::getShape() const{
    return shape;
}
void Bonus::visible(bool b){
    isVisible=b;
}
float Bonus::getPoint(){
    return point;
}
