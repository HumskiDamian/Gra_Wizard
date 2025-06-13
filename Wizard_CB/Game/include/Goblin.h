#ifndef GOBLIN_H
#define GOBLIN_H


#include "Enemy.h"

class Goblin : public Enemy {
public:
    Goblin();
    ~Goblin();

    void attack(Player& player) override;
    void update(float deltaTime, Player& player) override;
    void updateAnimation(float deltaTime,const Player& player);
private:
    sf::Texture texture1;

    int currentFrameX;
    int currentFrameY;
    float animationTimer;
    float animationSpeed;
    int maxFrameX;
    sf::Vector2i frameSize;


};


#endif // GOBLIN_H
