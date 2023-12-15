#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"


class Bar{
public:
    Bar(sf::Color color, Player player, int value_, int max_, float x_, float y_, sf::Vector2f size_);
    ~Bar();

    void Draw(sf::RenderWindow& window);

    void Update(Player player, int value_);

    sf::Vector2f GetPosition() { return bg_body.getPosition(); }

private:
    sf::RectangleShape bg_body;
    sf::RectangleShape mn_body;
    sf::Vector2f size;
    int value;
    int max;
    float x;
    float y;
};