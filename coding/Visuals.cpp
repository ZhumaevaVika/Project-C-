#include <SFML/Graphics.hpp>
#include "Visuals.h"

Bar::Bar(sf::Color color, Player player, int value_, int max_, float x_, float y_, sf::Vector2f size_)
{
    value = value_;
    max = max_;
    x = x_;
    y = y_;
    size = size_;
    bg_body.setSize(size);
    bg_body.setPosition(player.GetPosition().x + x, player.GetPosition().y + y);
    bg_body.setFillColor(sf::Color::Black);

    mn_body.setSize(sf::Vector2f(size.x * (static_cast<float>(value))/(static_cast<float>(max)), size.y * 0.70f));
    mn_body.setPosition(player.GetPosition().x + x, player.GetPosition().y + y + (size.y * 0.05f));
    mn_body.setFillColor(color);
}

Bar::~Bar(){}

void Bar::Draw(sf::RenderWindow& window)
{
    window.draw(bg_body);
    window.draw(mn_body);
}

void Bar::Update(Player player,int value_)
{
    value = value_;
    if(value > max)
        value = max;
    bg_body.setPosition(player.GetPosition().x + x, player.GetPosition().y + y);
    mn_body.setPosition(player.GetPosition().x + x, player.GetPosition().y + y + (size.y * 0.05f));
    mn_body.setSize(sf::Vector2f(size.x * (static_cast<float>(value))/(static_cast<float>(max)), size.y * 0.70f));
}