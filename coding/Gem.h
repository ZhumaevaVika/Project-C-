#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "Player.h"


class Gem{
public:
    Gem(sf::Texture* texture, sf::Vector2f pos);
    ~Gem();

    void Draw(sf::RenderWindow& window);

    void Update(Player& player);

    sf::Vector2f GetPosition() { return body.getPosition(); }
    Collider GetCollider() { return Collider(body); }
    sf::Vector2f GetSize() { return size; }

private:
    sf::RectangleShape body;
    const sf::Texture* texture{};
    float totalTime;
    sf::Vector2f size;
public:
    bool alive = true;
};