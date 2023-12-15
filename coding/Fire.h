#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "Enemy.h"

class Fire : public Enemy {
public:
    Fire(sf::Texture* texture, Player player, int x, int y, int HP): Enemy(texture, player, x, y, sf::Vector2u(1, 1), 0.2f, {40.0f, 40.0f}, 0.0f, HP, 10){}
    ~Fire(){}

private:
    sf::Texture* texture;
};