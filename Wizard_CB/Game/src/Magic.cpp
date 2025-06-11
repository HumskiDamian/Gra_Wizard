#include "Magic.h"

    Magic::Magic(){}
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
        //std::cout<<tar_x<<"===="<<tar_y<<std::endl;
        //std::cout<<pos.x<<"----"<<pos.y<<std::endl;
        dis=0;
        body.setRadius(body_size);
        if(typ==1)
            body.setFillColor(sf::Color::Red);
        if(typ!=1)
            body.setFillColor(sf::Color::Blue);
        body.setPosition(pos);

        sf::Vector2f dir;
        sf::Vector2u windowSize=target->getSize();
        //std::cout<<speed<<std::endl;
        //std::cout<<tar_x<<"----"<<tar_y<<std::endl;
        //std::cout<<pos.x<<"++++"<<pos.y<<std::endl;
        dir.x=tar_x-(1600/2);
        dir.y=tar_y-(900/2);
        while(abs(dir.x)<1||abs(dir.y)<1){
            dir.x/=2;
            dir.y/=2;
        }
        //std::cout<<x<<","<<y<<"\n";
        //dir.x/=sqrt(dir.x*dir.x+dir.y*dir.y);
        //dir.y/=sqrt(dir.x*dir.x+dir.y*dir.y);
        /*float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
        direction = sf::Vector2f(dir.x / length, dir.y / length);*/
        direction=dir;

    }
	Magic::~Magic(){}
	void Magic::update(float deltaTime){
        dis+=sqrt(direction.x*direction.x+direction.y*direction.y)*speed*deltaTime;
        //std::cout<<direction.x*speed<<"===="<<direction.y*speed<<std::endl;
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
/*
Magic::Magic()
{
	this->initMagic();
}

Magic::~Magic()
{
	//for (auto& shot : activeShots) {
		//delete shot.shape;
	//}
}

void Magic::initMagic()
{
    timerMag=0;
	this->existMagic = false;
	this->incantation = false;
	this->canActivMagic = true;
	this->actMagic = 0;
	for (int i = 0;i < 6;i++) {
		this->mana[i] = 10;
		this->size[i] = 30;
		this->distanc[i] = 200;
		this->damage[i] = 100;
		this->proficiency[i] = 0;
		if (i == 0 || i == 2 || i == 5)
			this->expRange[i] = 20;
		else
			this->expRange[i] = 0;
		this->time[i] = 3;
		this->speed[i] = 100;
	}

}

void Magic::setMana()
{
}

void Magic::setSize()
{
}
void Magic::setDamage()
{

}

void Magic::setDist()
{
}

void Magic::setExpRange()
{
}

void Magic::setActMagic(int key)
{
	this->actMagic = key;
}

bool Magic::getExistMagic()
{
	return this->existMagic;
}

void Magic::setIncantation_t()
{
	this->incantation = true;
}

void Magic::setCenActiveMagic_f()
{
	this->canActivMagic = false;
}

float Magic::getDist()
{
	return 0;
}

float Magic::getMana()
{
	return this->mana[actMagic];
}

float Magic::getTime()
{
	return time[actMagic];
}

bool Magic::getCanActivMagic()
{
	return this->canActivMagic;
}

void Magic::shoot(sf::Vector2f startPosition,const sf::RenderTarget* target) {

       activeShots.emplace_back(startPosition, speed[actMagic], distanc[actMagic], target, x, y);

}


void Magic::updateMagic(float dTime, int* x, int* y)
{
    this->x=*x;
    this->y=*y;
    if(timerMag>0)
        timerMag-=dTime;
    for (auto& shot : activeShots) {
		shot.update(dTime);
		if(shot.isMaxDistance()){
           // delete &shot;
            }
	}
	for (auto it = activeShots.begin(); it != activeShots.end(); ++it) {
    if (it->isMaxDistance()) {
        //activeShots.erase(it);  // erase() zwraca nastêpny iterator
    }
}
	if (this->incantation) {
		//this->cooldownTimer = time[actMagic];
		//this->incantation = false;
	}*/
/*	for (int i = 0;i < 6;i++){
        if (this->proficiency[i] != 0) {
			if (this->time[i] > 0.5f)
				this->time[i] = 3 - this->proficiency[i] / 5;
			this->damage[i] = 100 + this->proficiency[i]*2;
			this->distanc[i] = 200 + this->proficiency[i]*10;
			this->speed[i] = 600 + this->proficiency[i]*10;
		}
	}

	cooldownTimer -= dTime;
*/
	/*for (auto it = activeShots.begin(); it != activeShots.end();) {
		it->shape->move(it->direction * it->speed * dTime);
		it->distanceTraveled += it->speed * dTime;
		std::cout << "Magia_ruch-------------------------------------------------" << "\n";
		if (it->distanceTraveled >= it->maxDistance) {
			delete it->shape;
			it = activeShots.erase(it);
		}
		else {
			++it;
		}
	}*/
//}

/*
void Magic::render(sf::RenderTarget* target)
{
	for (auto& shot : activeShots) {
		shot.render(target);
	}
}
std::vector<Shot_Magic>* Magic::getVector(){
    return &activeShots;
}
float Magic::takeReck(sf::RectangleShape& enemy){
    for (auto& shot : activeShots) {
		if(enemy.getGlobalBounds().intersects(shot.getShape().getGlobalBounds())){
            return shot.getDamage();
		}
	}

}
*/
