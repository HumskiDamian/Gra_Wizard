#include "Magic.h"


Magic::Magic()
{
	this->initMagic();
}

Magic::~Magic()
{
	for (auto& shot : activeShots) {
		delete shot.shape; // Zwolnienie pamiêci
	}
}

void Magic::initMagic()
{
	this->existMagic = false;
	this->incantation = false;
	this->canActivMagic = true;
	this->actMagic = 0;
	for (int i = 0;i < 6;i++) {
		this->mana[i] = 10;
		this->size[i] = 30;
		this->distanc[i] = 200;
		this->damage[i] = 50;
		this->proficiency[i] = 0;
		if (i == 0 || i == 2 || i == 5)
			this->expRange[i] = 20;
		else
			this->expRange[i] = 0;
		this->time[i] = 3;
	}
	this->speed = 500;
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

void Magic::shoot(const sf::Vector2f& startPosition, const sf::Vector2f& targetPosition) {
       /* // Tworzenie kształtu magii
        sf::Shape* shape;
        if (actMagic == 0) {
            shape = new sf::CircleShape(size[actMagic] / 2.f);
        } else {
            shape = new sf::RectangleShape(sf::Vector2f(size[actMagic], size[actMagic] / 2.f));
        }

        shape->setFillColor(sf::Color::Cyan);
        shape->setPosition(startPosition);

        // Obliczanie kierunku
        sf::Vector2f direction = targetPosition - startPosition;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length != 0.f) {
            direction /= length; // Normalizacja wektora
        }

        activeShots.emplace_back(shape, direction, distanc[actMagic], speed);
        cooldownTimer = cooldown; // Reset cooldown
}
*/

/*void Magic::shoot(const sf::Vector2f& pos)
{
	if (this->incantation) {
		this->canActivMagic = false;
		this->cooldownTimer=time[actMagic];
	}

	if (cooldownTimer <= 0.f) {
		proficiency[actMagic] += 1;
		//---------------------------------------------
		//sf::Shape* shape = nullptr;
		//std::unique_ptr<sf::Shape> shape;

		/*sf::Shape* shape;
		if (true) {
			shape = new sf::CircleShape(size[actMagic] / 2.f);
		}
		else {
			shape = new sf::RectangleShape(sf::Vector2f(size[actMagic], size[actMagic]));
		}*/



		//if (actMagic == 0 || actMagic == 1 || actMagic == 4 || actMagic == 5) {
		//	shape = new sf::CircleShape(size[actMagic] / 2.f);
		//}
		//else if (actMagic == 2) {
		//	shape = new sf::RectangleShape(sf::Vector2f(size[actMagic], size[actMagic] / 3));
		//}
		//else if(actMagic == 3){
		//	shape = new sf::RectangleShape(sf::Vector2f(size[actMagic] / 3, size[actMagic] / 3));
		//}
		//else {
		//	shape = new sf::CircleShape(size[0] / 2.f);
		//}



		//sf::CircleShape* shape;
		//-------------------------------------------
		//shape->setRadius(size[actMagic] / 2.f);




		//shape->setFillColor(sf::Color::Blue); // Domyœlny kolor magii
		//shape->setPosition(pos);


		//---------------------------------------------------------------------------------------------------------

		/*if (actMagic == 0 || actMagic == 1 || actMagic == 4 || actMagic == 5) {
			shape = std::make_unique<sf::CircleShape>(size[actMagic] / 2.f);
		}
		else if (actMagic == 2) {
			shape = std::make_unique<sf::RectangleShape>(sf::Vector2f(size[actMagic], size[actMagic] / 3));
		}
		else if (actMagic == 3) {
			shape = std::make_unique<sf::RectangleShape>(sf::Vector2f(size[actMagic] / 3, size[actMagic] / 3));
		}

		if (shape) {
			shape->setFillColor(sf::Color::Blue);
			shape->setPosition(pos);
		}*/

		/*sf::CircleShape* shape = new sf::CircleShape(size[actMagic] / 2.f);
		shape->setFillColor(sf::Color::Blue);
		shape->setPosition(pos);
		//-------------------------------------------------------------------------------------------
		std::cout << "Magia_strzal-------------------------------------------------" << "\n";
		//sf::Vector2f direction = sf::Mouse::getPosition() - pos;
		//float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		//if (length != 0.f) {
		//	direction /= length; // Normalizacja wektora
		//}

		playerPos = pos;
		direction.x = playerPos.x - sf::Mouse::getPosition().x;
		direction.y = playerPos.y - sf::Mouse::getPosition().y;
		shorDirec = sqrt((playerPos.x - sf::Mouse::getPosition().x * (playerPos.x - sf::Mouse::getPosition().x) + (playerPos.y - sf::Mouse::getPosition().y) * (playerPos.y - sf::Mouse::getPosition().y)));
		sind = direction.y / shorDirec;
		cosd = direction.x / shorDirec;
		sf::Vector2f dir{ sind,cosd };

		activeShots.emplace_back(shape, dir, distanc[actMagic],
			speed, damage[actMagic]);
		cooldownTimer = time[actMagic]; // Reset cooldown
		this->canActivMagic = true;
		this->incantation = false;
	}*/

}


void Magic::updateMagic(float dTime)
{
	if (this->incantation) {
		//this->cooldownTimer = time[actMagic];
		//this->incantation = false;
	}
	for (int i = 0;i < 6;i++)
		if (this->proficiency[i] != 0) {
			if (this->time[i] > 0.5f)
				this->time[i] = 3 - this->proficiency[i] / 50;
			this->damage[i] = 50 + this->proficiency[i] / 10;
			this->distanc[i] = 200 + this->proficiency[i];
		}

	cooldownTimer -= dTime;


	for (auto it = activeShots.begin(); it != activeShots.end();) {
		it->shape->move(it->direction * this->speed * dTime);
		it->distanceTraveled += this->speed * dTime;
		std::cout << "Magia_ruch-------------------------------------------------" << "\n";
		if (it->distanceTraveled >= it->maxDistance) {
			delete it->shape; // Zwolnienie pamiêci
			it = activeShots.erase(it); // Usuniêcie z wektora
		}
		else {
			++it;
		}
	}
	/*if(!(dist > distanc[actMagic])&& existMagic)
		moveMagic(dTime, target);
		render(target);*/
}


void Magic::render(sf::RenderTarget* target)
{
	for (const auto& shot : activeShots) {
		target->draw(*shot.shape);
	}
}

