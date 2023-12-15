#include "Whip.h"

Whip::Whip(sf::Texture* texture, Player player): 
    Weapon(texture, player, sf::Vector2u(2, 2), 0.3f, {300, 30}, {-20, 25}, 2, 1),
    animation(texture, sf::Vector2u(2, 2), 0.3f){};
Whip::~Whip(){};