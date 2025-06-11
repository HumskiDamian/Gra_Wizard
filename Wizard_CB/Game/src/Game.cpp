#include "Game.h"




void Game::initVariables(int dif)
{
	this->a = 1600;
	this->b = 900;
	this->gravity = 50;
	this->endgame = false;
	this->plat.setSize(sf::Vector2f(this->a*30, this->b / 3));
	this->plat.setPos(sf::Vector2f(this->a*30 / 2.f-800, 680));
	this->Lwall.setSize(sf::Vector2f(10, 1100));
	this->Lwall.setPos(sf::Vector2f(0, 0));
	this->Lwall.setColor(0,0,0,0);
	texture.loadFromFile("./image/zamek.png");
	this->ending.setSize(sf::Vector2f(400,400));
	this->ending.setPosition(sf::Vector2f(15000,130));
	this->ending.setTexture(&texture);
	//this->ending.setFillColor(sf::Color::Blue);
	srand(time(NULL));
    trapLos = (rand()%30)+1;
    for(int i=1;i<=trapLos;i++){
        traps.emplace_back();
    }
    //player.setVelocity_y(981.f);
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
		gob.setDmg_hp(dif);
	}
	skelLos = (rand()%50)+5;
	for(int i=1;i<=skelLos;i++){
        skeletons.emplace_back();
    }
	dLos=1000;
	for (auto& skel : skeletons) {
        dLos+=(rand()%2000);
		skel.setPos(dLos);
		skel.setDmg_hp(dif);
	}
	platLos = (rand()%10)+1;
    for(int i=1;i<=platLos;i++){
        platforms.emplace_back();
        bonus.emplace_back();
    }
    int xLos=500;
    int yLos=200;
    for (auto& plat : platforms) {
        xLos+=((rand()%1000)+2000);
        plat.setSize(sf::Vector2f(300,50));
		plat.setPos(sf::Vector2f(xLos,yLos+(rand()%200)));
	}

	for (auto& bon : bonus) {
	    int k;
	    float losb=500;
	float r=(rand()%3+1.f);
	if(r<=1||r>3)
        k=3;
    else if(r<=2)
        k=2;
    else if(r<=3)
        k=1;
        losb+=rand()%100*100;
        bon.setBonus(rand()%40+10,sf::Vector2f(losb,rand()%150+300),k);
	}

    view.setCenter(sf::Vector2f(0.f,0.f));
    view.setSize(sf::Vector2f(a,b));

    mag_t=0;
    proficiency=1;
    typ=1;

    if (!bgTexture.loadFromFile("./image/las1.jpg")) {
    std::cerr << "B³¹d ³adowania tekstury las.jpg" << std::endl;
    } else {
    bgTexture.setRepeated(true);  // pozwala na powtarzanie tekstury

    //background.setTexture(&bgTexture);  // przypisanie tekstury do obiektu
    //background.setTextureRect(sf::IntRect(0, 0, a * 30, b*2));  // rozci¹gniêcie obszaru tekstury
    background.setSize(sf::Vector2f(a*30, b+800));  // ustawia rozmiar t³a
   // background.setPosition(0.f, 0.f);  // pozycja startowa
    //background.setSize(sf::Vector2f(a * 30, static_cast<float>(bgTexture.getSize().y*60)));
    bgTexture.setRepeated(true);  // pozwala na powtarzanie tekstury

    background.setTexture(&bgTexture);

    // Powtarzanie tylko w poziomie (szerokoœæ = a * 30, wysokoœæ = wysokoœæ oryginalnej tekstury)
   background.setTextureRect(sf::IntRect(0, 0, a*10, bgTexture.getSize().y));

    // Rozmiar prostok¹ta musi siê zgadzaæ z TextureRect


    background.setPosition(-1000.f, -700.f);
    }
}

void Game::initWindow()
{
	this->videomode = sf::VideoMode(a, b);
	this->window = new sf::RenderWindow(this->videomode, "Game 1", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(120);


}

//konstruktor i destruktor
Game::Game(int dif) {
	this->initVariables(dif);
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
            if(this->windowEvent.key.code == sf::Keyboard::Num1)
                typ=1;
            if(this->windowEvent.key.code == sf::Keyboard::Num2)
                typ=2;
			break;
		}
		///********************************************************************************************
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            if(player.getMana()>=(10/proficiency) && mag_t<=0 ){
                player.setMana(10/proficiency);
                mag_t=1.5;
                magic.emplace_back();
                if(typ==1)
                    magic.back().setMagic(800.f*proficiency,2.f*proficiency,100.f*(proficiency+0.5),2.f,10.f,20.f,2.f,player.GetPosition(),sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y-150,typ,this->window);
                if(typ!=1)
                    /*float maxDist,
    float speed,
    float damage,
    float time,
    float mana,
    float body_size,
    float incantation,
    sf::Vector2f pos,
    float tar_x,
    float tar_y,
    int typ, const sf::RenderTarget* target*/
                   magic.back().setMagic(1000.f*proficiency,2.f*proficiency,100.f*(proficiency-0.1),2.f,10.f,20.f,2.f,player.GetPosition(),sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y-150,typ,this->window);
                proficiency+=0.05;
            }
		}
	}
}


void Game::updateCollision()
{
}

void Game::update(float dTime)
{
    //std::cout<<sf::Mouse::getPosition(*window).x<<"===="<<sf::Mouse::getPosition(*window).y<<std::endl;

	this->pollEvents();

	if(mag_t>0) mag_t-=dTime;
    //std::cout << sf::Mouse::getPosition(*window).x<< ", "<<sf::Mouse::getPosition(*window).y<< ", "<<window->getPosition().x<< "\n";//-------------------------------------------------

	/*if (plat.GetCollider().CheckCollider(player.getCollider(), direction, 1.f)) {
		player.OnCollision(direction);
	}*/
	if (plat.GetCollider().GetBounds().top-(player.getCollider().GetBounds().top+player.getCollider().GetBounds().height)<=0){
            //std::cout<<plat.GetCollider().GetBounds().top-player.getCollider().GetBounds().top+player.getCollider().GetBounds().height-100<<std::endl;
        player.setVelocity_y(0.f);
        player.OnCollision(sf::Vector2f(0.f,0.f));


	}

    else player.setVelocity_y(981.f);

	if (Lwall.GetCollider().CheckCollider(player.getCollider(), direction, 1.f)) {
		player.OnCollision(sf::Vector2f(0.f,1.f));
	}
	for (auto& plat : platforms) {
        if (plat.GetCollider().CheckCollider(player.getCollider(), direction, 1.f)) {
            //player.setVelocity_y(0.f);
		player.OnCollision(direction);
	}
	//else
        //player.setVelocity_y(981.f);
	}
	for (auto& gob : goblins) {
        if (gob.GetCollider().CheckCollider(player.getCollider(), direction, 0.3f))
		player.OnCollision(direction);
	}
	for (auto& skel : skeletons) {
        if (skel.GetCollider().CheckCollider(player.getCollider(), direction, 0.3f))
		player.OnCollision(direction);
	}
	for (auto& gob : goblins) {
        for (auto mag = magic.begin(); mag != magic.end(); ) {
            if (mag->getShape().getGlobalBounds().intersects(gob.getShape().getGlobalBounds())) {
                gob.takeDamage(mag->getDmg());
                mag = magic.erase(mag);
                player.levelUp();
            }
            else ++mag;
        }
	}
	for (auto& skel : skeletons) {
        for (auto mag = magic.begin(); mag != magic.end(); ) {
            if (mag->getShape().getGlobalBounds().intersects(skel.getShape().getGlobalBounds())) {
                skel.takeDamage(mag->getDmg());
                mag = magic.erase(mag);
                player.levelUp();
            }
            else ++mag;
        }
	}
	for (auto mag = magic.begin(); mag != magic.end(); ) {
        if (mag->getShape().getGlobalBounds().intersects(plat.getShape().getGlobalBounds())) {
                mag = magic.erase(mag);
            }
            else ++mag;
	}



	for (auto& plat : platforms) {
        for (auto mag = magic.begin(); mag != magic.end(); ) {
            if (mag->getShape().getGlobalBounds().intersects(plat.getShape().getGlobalBounds())) {
                mag = magic.erase(mag);
            }
            else ++mag;
        }
	}
	///******************************************************************************************************************?
	 /*for (auto gob = goblins.begin(); gob != goblins.end(); ++gob){
        for (auto gob1 = goblins.begin(); gob1 != goblins.end(); ++gob1)
        {
            if(gob!=gob){
                gob.GetCollider().CheckCollider(gob1.GetCollider(), direction, 0.3f)


            }
        }
	 }*/



        ///=======================================================================================================
    /*for (auto& plat : platforms) {
        if(plat.GetCollider().GetBounds().top-(player.getCollider().GetBounds().top+player.getCollider().GetBounds().height)<=0){
            std::cout<<"tak"<<std::endl;
            player.setVelocity_y(0.f);}
        else {player.setVelocity_y(981.f); std::cout<<"nie"<<std::endl;}
    }*/

/*
    for (auto& gob : goblins) {
        gob.takeDamage(player.takeRect(gob.getShape()));
	}*/

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
    //this->goblin.update(dTime, player);
    for (auto& gob : goblins) {
		gob.update(dTime, player);
	}
	for (auto& skel : skeletons) {
		skel.update(dTime, player);
	}
    this->trap.update(&player);
    this->trap.setApraisal(player.getApraisal());
    for (auto& tr : traps) {
		tr.update(&player);
		tr.setApraisal(player.getApraisal());
	}
    for(auto& bon:bonus){
        bon.visible(player.getApraisal());
    }
	for (auto& mag : magic) {
		mag.update(dTime);
	}
	for (auto bon = bonus.begin(); bon != bonus.end(); ) {
        bon->update(dTime);
		if(bon->getShape().getGlobalBounds().intersects(player.getShape().getGlobalBounds())&&sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
            if(bon->getTyp()==1) player.setmHp(bon->getPoint());
            if(bon->getTyp()==2) player.setmMan(bon->getPoint());
            if(bon->getTyp()==3) player.takeDamage(bon->getPoint());
            bon = bonus.erase(bon);
		}
		else ++bon;

	}
	for (auto gob = goblins.begin(); gob != goblins.end(); ) {
        if(gob->isDead()==true)
            gob=goblins.erase(gob);
        else ++gob;
	}
	for (auto skel = skeletons.begin(); skel != skeletons.end(); ) {
        if(skel->isDead()==true)
            skel=skeletons.erase(skel);
        else ++skel;
	}
}

void Game::render()
{

	this->window->clear(sf::Color(70,180,220));
	window->draw(background);
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
	//this->goblin.render(this->window);
	window->draw(ending);
    for (auto& gob : goblins) {
		gob.render(this->window);
	}
	for (auto& skel : skeletons) {
		skel.render(this->window);
	}
	for (auto& mag : magic) {
		mag.render(this->window);
	}
	for (auto& bon : bonus) {
		bon.render(this->window);
	}
	this->window->display();
}
bool Game::getEndgame(){
return endgame;
}

