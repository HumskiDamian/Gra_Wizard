#ifndef TRAP_H
#define TRAP_H

#include <iostream>
#include <cmath>
#include <windows.h>
#include <SFML/Graphics.hpp>

#include "Player.h"
class Trap
{
private:

    sf::RectangleShape trap;
    float damage;
    float x,y,w,h;
    bool activeTrap;
    bool apraisal;
public:
    Trap();
    virtual ~Trap();
    void update(Player* player);
    void render(sf::RenderTarget* target);
    bool getActiveTrap();
    void setApraisal(bool a);
    void setPos(int q);
protected:


};

#endif // TRAP_H
