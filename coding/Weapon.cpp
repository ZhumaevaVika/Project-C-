#include "Weapon.h"
#include "Collider.h"
#include "Enemy.h"

Weapon::Weapon(sf::Texture* texture, Player player, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f shift, int damage, float reload): animation(texture, imageCount, switchTime), totalTime(0), row(0), faceRight(true), shift(shift) {
    body.setSize(size);
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(player.GetPosition().x - shift.x, player.GetPosition().y - shift.y);
    body.setTexture(texture);
    this->damage = damage;
    this->reload = reload;
}

Weapon::~Weapon(){}

void Weapon::Update(float deltaTime, Player player){
    faceRight = player.faceRight;
    if(faceRight == true){
        row = 0;
        body.setPosition(player.GetPosition().x - shift.x, player.GetPosition().y - shift.y);
    }
    else{
        row = 1;
        body.setPosition(player.GetPosition().x + shift.x, player.GetPosition().y - shift.y);
    }
    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
}

void Weapon::DamageEnemy(Enemy &enemy, float deltaTime){
    if (enemy.alive == true){
        if (GetCollider().CheckCollider(enemy.GetCollider(), 0.0f)){
            totalTime += deltaTime*12.0f;
            if (totalTime >= 0.5f){
                totalTime = 0.0f;
                enemy.HP -= this->damage;
            }
        }
    }
}

void Weapon::Draw(sf::RenderWindow& window){
    window.draw(body);
}

