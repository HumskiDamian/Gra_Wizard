#include "Shot_Magic.h"

Shot_Magic::Shot_Magic(sf::Vector2f pos,float speed, float dis, const sf::RenderTarget* target, int x, int y)
{
    dis=0.f;
    shape.setRadius(20);
    //shape.setSize(sf::Vector2f(20,20));
    shape.setFillColor(sf::Color::Cyan);
    shape.setPosition(pos);
    sf::Vector2f dir;
    sf::Vector2u windowSize=target->getSize();
    dir.x=x-(1600/2);
    dir.y=y-(900/2);
    //std::cout<<x<<","<<y<<"\n";
    dir.x/=sqrt(dir.x*dir.x+dir.y*dir.y);
    dir.y/=sqrt(pow(x-800,2)+pow(y-450,2));

    this->direction=dir;
    this->speed=speed*5;
    this->maxDistance=dis;
    //std::cout<<"Shot_Magic:: start"<<"\n";
    //ctor
}

Shot_Magic::~Shot_Magic()
{
    //dtor
}


void Shot_Magic:: update(float dTime){
    dis+=sqrt(direction.x*direction.x+direction.y*direction.y)*speed*dTime;
    this->shape.move(direction*speed*dTime);

}
void Shot_Magic:: render(sf::RenderTarget* target){
    target->draw(this->shape);
}
bool Shot_Magic:: isMaxDistance(){
    if(dis>maxDistance)
        return true;
    else
        return false;
}
float Shot_Magic:: getDamage(){
    return this->damage;
}
/*sf::RectangleShape Shot_Magic::getShape(){
return shape;
}*/
sf::CircleShape& Shot_Magic::getShape(){
    return shape;
}
