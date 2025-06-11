#include "Magic.h"

    Magic::Magic(){
    if (!texture1.loadFromFile("./image/fire1.png")) {
		std::cerr << "B³¹d ³adowania tekstury png" << std::endl;
	}
	texture1.setRepeated(true);
	if (!texture2.loadFromFile("./image/water.png")) {
		std::cerr << "B³¹d ³adowania tekstury png" << std::endl;
	}
	texture2.setRepeated(true);
    }
    void Magic::setMagic(float _maxDist,
    float _speed,
    float _damage,
    float _time,
    float _mana,
    float _body_size,
    float _incantation,
    sf::Vector2f _pos,
    int _tar_x,
    int _tar_y,
    int _typ, const sf::RenderTarget* target){
        maxDist=_maxDist;
        speed=_speed;
        damage=_damage;
        mana=_mana;
        body_size=_body_size;
        pos=sf::Vector2f(_pos.x,_pos.y-30);
        tar_x=_tar_x;
        tar_y=_tar_y;
        typ=_typ;
        dis=0;
        body.setRadius(body_size);
        if(typ==1)
            body.setTexture(&texture1);

        if(typ!=1)
            body.setTexture(&texture2);
        body.setPosition(pos);

        sf::Vector2f dir;
        sf::Vector2u windowSize=target->getSize();
        dir.x=tar_x-(1600/2);
        dir.y=tar_y-(900/2);
        while(abs(dir.x)<1||abs(dir.y)<1){
            dir.x/=2;
            dir.y/=2;
        }
        direction=dir;

    }
	Magic::~Magic(){}
	void Magic::update(float deltaTime){
        dis+=sqrt(direction.x*direction.x+direction.y*direction.y)*speed*deltaTime;
        body.move(direction*speed*deltaTime);
	}
    void Magic::render(sf::RenderTarget* target){
        target->draw(this->body);
    }
    float Magic::getDmg(){
        return damage;
    }
    bool Magic::isDist(){
        return (maxDist<dis);
    }
    sf::CircleShape Magic::getShape(){
        return body;
    }

