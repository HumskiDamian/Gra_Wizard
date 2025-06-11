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
private:
    sf::Texture texture2;


};

#endif // SKELETON_H
