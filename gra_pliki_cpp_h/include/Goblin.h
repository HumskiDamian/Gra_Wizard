#ifndef GOBLIN_H
#define GOBLIN_H


#include "Enemy.h"

class Goblin : public Enemy {
public:
    Goblin(float x, float y);
    ~Goblin();

    void attack(Player& player) override;
};


#endif // GOBLIN_H
