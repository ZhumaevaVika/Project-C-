#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "Player.h"
#include "Enemy.h"

class Weapon{
public:
    Weapon(sf::Texture* texture, Player player, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f shift, int damage, float reload);
    ~Weapon();

    void Update(float deltaTime, Player player);
    void Draw(sf::RenderWindow& window);

    void DamageEnemy(Enemy &enemy, float deltaTime);

    sf::Vector2f GetPosition() { return body.getPosition(); }
    Collider GetCollider() { return Collider(body); }
    sf::Vector2f GetSize() { return size; }
private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float totalTime;
    bool faceRight;
    sf::Vector2f size;
    sf::Vector2f shift;
    int damage;
    float reload;
};