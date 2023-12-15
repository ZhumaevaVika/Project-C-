#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Player{
public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
    ~Player();

    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    void Die();

    sf::Vector2f GetPosition() { return body.getPosition(); }
    Collider GetCollider() { return Collider(body); }
    sf::Vector2f GetSize() { return {50.0f, 75.0f}; }
    int GetHP() { return HP; }

private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
public:
    bool faceRight;
    int HP;
    bool alive = true;
    int XP;
};