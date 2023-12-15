#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "Enemy.h"

class Bat : public Enemy {
public:
    Bat(sf::Texture* texture, Player player, int x, int y, int HP): Enemy(texture, player, x, y, sf::Vector2u(1, 1), 0.2f, {25.0f, 25.0f}, 75.0f, HP, 5){}
    ~Bat(){}

private:
    sf::Texture* texture;
};