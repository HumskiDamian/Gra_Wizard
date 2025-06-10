#include "Player.h"

void Player::initVariables()
{
    gravity=981.f;
    onGround=false;
    timerMag=0.f;
    hpTimer=0.f;
    TimerT=0.f;
    texture.loadFromFile("./image/wizard.png");
    //init fonts, text and bars
    fridays.loadFromFile("Fonts/Fridays.ttf");
	hpStat.setSize(sf::Vector2f(150,25));
	hpStat.setFillColor(sf::Color::Red);
	hpStat.setPosition(10,10);
	manaStat.setSize(sf::Vector2f(150,25));
	manaStat.setFillColor(sf::Color::Blue);
	manaStat.setPosition(10,40);
	hpStatL.setSize(sf::Vector2f(150,25));
	hpStatL.setFillColor(sf::Color(0,0,0,0));
	hpStatL.setOutlineColor(sf::Color::Black);
	hpStatL.setOutlineThickness(3);
	hpStatL.setPosition(10,10);
	manaStatL.setSize(sf::Vector2f(150,25));
	manaStatL.setFillColor(sf::Color(0,0,0,0));
	manaStatL.setOutlineColor(sf::Color::Black);
	manaStatL.setOutlineThickness(3);
	manaStatL.setPosition(10,40);
	hpText.setFont(fridays);
	hpText.setColor(sf::Color(255,255,255));
    hpText.setCharacterSize(24);
    hpText.setPosition(50,10);
    manaText.setFont(fridays);
    manaText.setColor(sf::Color(255,255,255));
    manaText.setCharacterSize(24);
    manaText.setPosition(40,40);
    Timer.setFont(fridays);
	Timer.setColor(sf::Color(255,255,255));
    Timer.setCharacterSize(24);
    Timer.setPosition(800,10);

	this->movementSpeed = 500.f;
	this->hpMax = 100;
	this->manaMax = 100;
	this->mana = manaMax;
	this->hp = hpMax;
	/*this->go.x = 0;
	this->go.y = 0;*/
	this->jumpHeight = 200;
	this->level = 1;
	this->experienc = 0;
	this->time = 0.f;
	this->timerHeal=0.f;
	this->timerBarrier=0.f;
	this->barier=0.f;
	this->barierMana=50;
	this->apraisalMana=10;
}

void Player::initShape()
{
	//this->shape.setFillColor(sf::Color::Red);
	this->shape.setSize(sf::Vector2f(25.f, 50.f));
	this->shape.setOrigin(sf::Vector2f(25.f, 50.f) / 2.f);
	this->shape.setTexture(&texture);
}


Player::Player(float x, float y)
{
	this->shape.setPosition(300, 200);
	this->initVariables();
	this->initShape();
}

Player::~Player()
{

}

const sf::RectangleShape& Player::getShape() const
{
	// TODO: tu wstawiæ instrukcjê return
	return this->shape;
}

const float Player::getHp() const
{
	// TODO: tu wstawiæ instrukcjê return
	return this->hp;
}

const float Player::getHpMax() const
{
	// TODO: tu wstawiæ instrukcjê return
	return this->hpMax;
}
//========================================================================================================take damage
void Player::takeDamage(const int damage)
{
    if(hpTimer<=0){
        if (this->hp > 0){
        if(barier==0)
            this->hp -= damage;
        if(barier>0){
            barier-=damage;
        }
        if(barier<0)
            barier=0.f;
	}

	if (this->hp < 0)
		this->hp = 0;
        hpTimer=1;
    }

}

void Player::gainHealth(const int health)
{
	if (this->hp < this->hpMax)
		this->hp += health;
	if (this->hp > this->hpMax)
		this->hp = hpMax;
}

void Player::updateinput(float dTime, const sf::RenderTarget* target)
{
	//keyboard----------------------------------------
	//heal
	{
	if(this->timerHeal<=0){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
            this->timerHeal=3;
            if(this->mana >=20.f){
                    mana-=20;
                if(this->hp>this->hpMax-80.f)
                    this->hp=this->hpMax;
                else
                    this->hp+=80.f;
            }
        }
    }
    else{
        timerHeal-=dTime;
    }
	}
	//barier
	{
	if(this->timerBarrier<=0){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
            this->timerBarrier=10;
            if(this->mana >=barierMana){
                    mana-=barierMana;
                this->barier=this->hpMax*2;
            }
        }
    }
    else{
        timerBarrier-=dTime;
    }
	}
    //apraisal
    {
    if(this->timerApraisal<=0){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
            this->timerApraisal=2;
            if(this->mana >= apraisalMana){
                    mana-=apraisalMana;
                this->apraisal=true;
                this->apraisalTime=5;
            }
        }
    }
    else{
        timerApraisal-=dTime;
    }
    if(apraisalTime>0.f){
        apraisalTime-=dTime;
    }
    if(apraisalTime<=0.f){
        this->apraisal=false;
    }
    }

	velocity.x *= 0.f;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->velocity.x -= movementSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->velocity.x += movementSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->canJump) {
		this->canJump = false;
		gravity=981.f;
		this->velocity.y -= sqrt(2.f * 981.f * jumpHeight);
		this->onGround=false;

	}
	//std::cout << canJump << "\n";
	//if(canJump==false)
    this->velocity.y += gravity * dTime;

	this->shape.move(velocity * dTime);

	//mouse------------------------------

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if(timerMag<=0.f){
            if (this->mana >= this->magic.getMana() && magic.getCanActivMagic()) {
			this->mana -= magic.getMana();
			magic.shoot(sf::Vector2f (shape.getPosition()), target);
			magic.setIncantation_t();
		}
		//std::cout << "prawy_przycisk---------------------------------" << "\n";
		timerMag=magic.getTime();
	}
	}




}
void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{


}

void Player::update(const sf::RenderTarget* target, float dTime, int* x, int* y)
{

    TimerT+=dTime;
    if(timerMag>0)
        timerMag-=dTime;
    if(hpTimer>0)
        hpTimer-=dTime;

    {
        std::stringstream sshp;
        std::stringstream ssmana;
        std::stringstream sstime;
        sshp<<round(this->hp)<<"/"<<this->hpMax;
        ssmana<<round(this->mana)<<"/"<<this->manaMax;
        sstime<<round(TimerT);

        hpText.setString(sshp.str());
        manaText.setString(ssmana.str());
        Timer.setString(sstime.str());
        hpStat.setScale(sf::Vector2f(hp/hpMax,1));
        manaStat.setScale(sf::Vector2f(mana/manaMax,1));
    }
    if(round(hp)>0)
    {
	this->updateinput(dTime, target);
	this->levelUp();
	this->updateWindowBoundsCollision(target);
    //std::cout << *x<< ", "<<*y<< ", "<< "\n";
	magic.updateMagic(dTime,x,y);
	if(this->mana<this->manaMax){
        this->mana+=dTime;
	}
	if(this->hp<this->hpMax){
        this->hp+=dTime/10;
	}
    }

    //fonts and text


}

void Player::render(sf::RenderTarget* target, sf::View* view)
{

	target->draw(this->shape);
	magic.render(target);
	target->setView(target->getDefaultView());
    target->draw(hpStatL);
	target->draw(hpStat);
	target->draw(hpText);
	target->draw(manaStatL);
	target->draw(manaStat);
	target->draw(manaText);
	target->draw(Timer);
	target->setView(*view);
}

void Player::levelUp()
{
	if (this->experienc >= 200 * this->level) {
		this->experienc = 0;
		level += 1;
		this->manaMax += 100;
		this->hpMax += 50;
	}


}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.f) {
		//collisionj on left
		this->velocity.x = 0.f;
	}
	else if (direction.x > 0.f) {
		//collision on right
		this->velocity.x = 0.f;

	}
	//gravity=981.f;
	if (direction.y <= 0.f) {
		this->velocity.y = 0.f;
		//gravity=0.f;
		this->canJump = true;
		//this->onGround=false;
	}
	else if (direction.y > 0.f) {
		this->velocity.y = 0.f;
		//gravity=981.f;
		//this->onGround=false;

	}
}

Collider Player::getCollider()
{
	return Collider(this->shape);
}
bool Player::getApraisal(){
    return apraisal;
}
Magic* Player::magick(){
    return &magic;

}

float Player::takeRect(sf::RectangleShape& enemy){
    return magic.takeReck(enemy);
}
float Player::getTimer(){
return TimerT;
}

/*void Player::setGravity(bool g){
    if(g) onGround=true;
    else onGround=false;
}*/

void Player::setVelocity_y(float vel_y){
    gravity=vel_y;
}
