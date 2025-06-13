#ifndef SKELETON_H
#define SKELETON_H

#include "Enemy.h"

class Skeleton: public Enemy
{
   public:
    Skeleton();
    ~Skeleton();

    void attack(Player& player) override;
    void update(float deltaTime, Player& player) override;
    void updateAnimation(float deltaTime,const Player& player);
private:
    sf::Texture texture2;
    int currentFrameX;
    int currentFrameY;
    float animationTimer;
    float animationSpeed;
    int maxFrameX;
    sf::Vector2i frameSize;


};

#endif // SKELETON_H
