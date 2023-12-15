#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture, Player player, int x, int y, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, float speed, int HP, int damage) : animation(texture, imageCount, switchTime)
{
    this->totalTime = 0.0f;
    this->speed = speed;
    this->HP = HP;
    this->damage = damage;
    row = 0;
    faceRight = true;

    body.setSize(size);
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}

Enemy::~Enemy(){}

void Enemy::Update(float deltaTime, Player& player){
    if (alive){
        sf::Vector2f movement(0.0f, 0.0f);
        sf::Vector2f position = GetPosition();

        if (position.x > player.GetPosition().x)
            movement.x -= speed*deltaTime;
        if (position.x < player.GetPosition().x)
            movement.x += speed*deltaTime;
        if (position.y > player.GetPosition().y)
            movement.y -= speed*deltaTime;
        if (position.y < player.GetPosition().y)
            movement.y += speed*deltaTime;

        
        if ((movement.x == 0.0f)and(movement.y == 0.0f))
            row = 0;
        else{
            if (movement.x > 0.0f)
                faceRight = true;
            if (movement.x < 0.0f)
                faceRight = false;
        }
        animation.Update(row, deltaTime, faceRight);
        body.setTextureRect(animation.uvRect);
        body.move(movement);
        DamagePlayer(player, deltaTime);
        Die();
    }
}

void Enemy::Draw(sf::RenderWindow& window){
    if (alive){
        window.draw(body);
    }
}

void Enemy::DamagePlayer(Player& player, float deltaTime){
    if (player.alive){
        if (GetCollider().CheckCollider(player.GetCollider(), 0.0f)){
            totalTime += deltaTime*12.0f;
            if (totalTime >= 0.5f){
                totalTime = 0.0f;
                player.HP -= this->damage;
            }
        }
    }
}

void Enemy::Die(){
    if (this->HP <= 0 && alive == true){
        alive = false;
        Enemy::~Enemy();
    }
}