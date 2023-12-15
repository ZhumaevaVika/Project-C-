#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "Weapon.h"

class Whip: public Weapon{
public:
    Whip(sf::Texture* texture, Player player);
    ~Whip();

private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float totalTime;
    bool faceRight;
    sf::Vector2f size;
    sf::Vector2f shift;
};