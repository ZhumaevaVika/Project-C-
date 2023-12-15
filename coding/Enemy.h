#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "Player.h"

class Enemy{
public:
    Enemy(sf::Texture* texture, Player player, int x, int y, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, float speed, int HP, int damage);
    ~Enemy();

    void Update(float deltaTime, Player& player);
    void Draw(sf::RenderWindow& window);
    void DamagePlayer(Player& player, float deltaTime);
    void Die();

    sf::Vector2f GetPosition() { return body.getPosition(); }
    Collider GetCollider() { return Collider(body); }
    sf::Vector2f GetSize() { return size; }

private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float totalTime;
    float speed;
    bool faceRight;
    int damage;
    sf::Vector2f size;
public:
   int HP;
   bool alive = true;
   bool spawned = false;
};