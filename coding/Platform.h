#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

class Platform{
public:
    Platform(sf::Vector2f size, sf::Vector2f position);
    ~Platform();
    void Die();

    void Draw(sf::RenderWindow& window);
    Collider GetCollider() { return Collider(body); }
    bool alive = true;

private:
    sf::RectangleShape body;
};