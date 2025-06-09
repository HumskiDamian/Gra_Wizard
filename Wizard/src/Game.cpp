#include "Game.h"




void Game::initVariables()
{
    this->a = 1600;
    this->b = 900;
    this->gravity = 50;
    this->endgame = false;
    this->plat.setSize(sf::Vector2f(this->a*30, this->b / 3));
    this->plat.setPos(sf::Vector2f(this->a*30 / 2.f, 680));
    this->Lwall.setSize(sf::Vector2f(10, 1100));
    this->Lwall.setPos(sf::Vector2f(0, 0));
    this->Lwall.setColor(0,0,0,0);
    texture.loadFromFile("./image/zamek.png");
    this->ending.setSize(sf::Vector2f(400,400));
    this->ending.setPosition(sf::Vector2f(10000,130));
    this->ending.setTexture(&texture);
    //this->ending.setFillColor(sf::Color::Blue);
    srand(time(NULL));
    trapLos = (rand()%30)+1;
    for(int i=1;i<=trapLos;i++){
        traps.emplace_back();
    }
    int dLos=1000;
    for (auto& tr : traps) {
        dLos+=(rand()%1500+200);
        tr.setPos(dLos);
    }
    goblinLos = (rand()%50)+1;
    for(int i=1;i<=goblinLos;i++){
        goblins.emplace_back();
    }
    dLos=1000;
    for (auto& gob : goblins) {
        dLos+=(rand()%1500);
        gob.setPos(dLos);
    }
    platLos = (rand()%100)+1;
    for(int i=1;i<=platLos;i++){
        platforms.emplace_back();
    }
    int xLos=500;
    int yLos=200;
    for (auto& plat : platforms) {
        xLos+=((rand()%1000)+200);
        plat.setSize(sf::Vector2f(300,50));
        plat.setPos(sf::Vector2f(xLos,yLos+(rand()%200)));
    }
    view.setCenter(sf::Vector2f(0.f,0.f));
    view.setSize(sf::Vector2f(a,b));

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

    //std::cout << sf::Mouse::getPosition(*window).x<< ", "<<sf::Mouse::getPosition(*window).y<< ", "<<window->getPosition().x<< "\n";//-------------------------------------------------

    if (plat.GetCollider().CheckCollider(player.getCollider(), direction, 1.f)) {
        player.OnCollision(direction);
    }
    if (Lwall.GetCollider().CheckCollider(player.getCollider(), direction, 1.f)) {
        player.OnCollision(direction);
    }
    for (auto& plat : platforms) {
        if (plat.GetCollider().CheckCollider(player.getCollider(), direction, 1.f)) {
            player.OnCollision(direction);
        }
    }
    for (auto& gob : goblins) {
        if (gob.GetCollider().CheckCollider(player.getCollider(), direction, 0.3f)) {
            player.OnCollision(direction);
        }
    }


    for (auto& gob : goblins) {
        gob.takeDamage(player.takeRect(gob.getShape()));
    }

    if(ending.getGlobalBounds().intersects(player.getShape().getGlobalBounds())){
        endgame=true;

    }
    if(player.getHp()<=0){
        endgame=true;



    }

    this->x=sf::Mouse::getPosition(*window).x;
    this->y=sf::Mouse::getPosition(*window).y-150;
    //std::cout << this->x<< ", "<<this->y<< ", "<< "\n";
    this->player.update(this->window, dTime, &this->x, &this->y);
    this->goblin.update(dTime, player);
    for (auto& gob : goblins) {
        gob.update(dTime, player);
    }
    this->trap.update(&player);
    this->trap.setApraisal(player.getApraisal());
    for (auto& tr : traps) {
        tr.update(&player);
        tr.setApraisal(player.getApraisal());
    }
}

void Game::render()
{
    this->window->clear(sf::Color(70,180,220));
    view.setCenter(player.GetPosition().x,player.GetPosition().y-150);
    window->setView(view);
    this->trap.render(this->window);
    for (auto& tr : traps) {
        tr.render(this->window);
    }
    for (auto& plat : platforms) {
        plat.render(this->window);
    }
    this->plat.render(this->window);
    this->Lwall.render(this->window);
    this->player.render(this->window,&view);
    this->goblin.render(this->window);
    window->draw(ending);
    for (auto& gob : goblins) {
        gob.render(this->window);
    }
    this->window->display();
}
bool Game::getEndgame(){
    return endgame;
}

