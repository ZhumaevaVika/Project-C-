#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) : animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->HP = 120;
    this->XP = 0;
    row = 0;
    faceRight = true;

    body.setSize(sf::Vector2f(50.0f, 75.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(206.0f, 206.0f);
    body.setTexture(texture);
}

Player::~Player(){}

void Player::Update(float deltaTime){
    if (alive){
        sf::Vector2f movement(0.0f, 0.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            movement.x -= speed*deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            movement.x += speed*deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            movement.y -= speed*deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            movement.y += speed*deltaTime;

        if ((movement.x == 0.0f)and(movement.y == 0.0f))
            row = 0;
        else{
            row = 1;
            if (movement.x > 0.0f)
                faceRight = true;
            if (movement.x < 0.0f)
                faceRight = false;
        }
        animation.Update(row, deltaTime, faceRight);
        body.setTextureRect(animation.uvRect);
        body.move(movement);
        Die();
    }
}

void Player::Draw(sf::RenderWindow& window){
    if (alive){
        window.draw(body);
    }
}

void Player::Die(){
    if (this->HP <= 0 && alive == true){
        alive = false;
        Player::~Player();
    }
}