#include "Platform.h"
#include <iostream>

sf::Texture san;

Platform::Platform(sf::Vector2f size, sf::Vector2f position){
    body.setSize(size);
    body.setOrigin(size / 2.0f);
    san.loadFromFile("../textures/san.jpg");
    body.setTexture(&san);
    body.setPosition(position);
}

Platform::~Platform(){}

void Platform::Die(){
    if(alive == true){
        alive = false;
        Platform::~Platform();
    }
}

void Platform::Draw(sf::RenderWindow& window){
    window.draw(body);
}