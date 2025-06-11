#ifndef BONUS_H
#define BONUS_H
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Collider.h"

class Bonus
{
    public:
        Bonus();
        ~Bonus();
        void setBonus(float a,sf::Vector2f pos,int _typ);
        void update(float dTime);
        void render(sf::RenderTarget* target);
        int getTyp();
        const sf::CircleShape& getShape() const;
        void visible(bool b);
        float getPoint();



    private:
        sf::CircleShape shape;
        sf::CircleShape typ_a;
        int typ;
        float point;
        bool isVisible;

};

#endif // BONUS_H
