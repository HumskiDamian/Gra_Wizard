#include "Game.h"




void Game::initVariables()
{

	this->a = 800;
	this->b = 600;
	this->gravity = 50;
	this->endgame = false;

	this->points = 0;

	this->plat.setSize(sf::Vector2f(this->a, this->b / 12));
	this->plat.setPos(sf::Vector2f(a / 2.f, this->b - (this->b / 12)));
    view.setCenter(sf::Vector2f(0.f,0.f));
    view.setSize(sf::Vector2f(800,600));

}

void Game::initWindow()
{
	this->videomode = sf::VideoMode(a, b);
	this->window = new sf::RenderWindow(this->videomode, "Game 1", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(120);
}

//konstruktor i destruktor
Game::Game() {
	this->initVariables();
	this->initWindow();

}
Game::~Game() {
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->windowEvent)) {
		switch (this->windowEvent.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->windowEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}


void Game::updateCollision()
{


}

void Game::update(float dTime)
{
	this->pollEvents();


	if (plat.GetCollider().CheckCollider(player.getCollider(), direction, 1.f)) {
		player.OnCollision(direction);
	}

	this->player.update(this->window, dTime);

}

void Game::render()
{
	this->window->clear();
	view.setCenter(player.GetPosition());
	//window.setView(view);
	//this->window->draw(floor);
	view.setCenter(player.GetPosition().x,player.GetPosition().y-150);
	window->setView(view);
	this->plat.render(this->window);
	this->player.render(this->window);


	this->window->display();
}


