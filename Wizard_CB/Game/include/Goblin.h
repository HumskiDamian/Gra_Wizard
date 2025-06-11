#ifndef GOBLIN_H
#define GOBLIN_H


#include "Enemy.h"

class Goblin : public Enemy {
public:
    Goblin();
    ~Goblin();

    void attack(Player& player) override;
    void update(float deltaTime, Player& player) override;
private:
    sf::Texture texture1;


};


#endif // GOBLIN_H
