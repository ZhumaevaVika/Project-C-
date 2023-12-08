#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Platform.h"

static const float VIEW_HEIGHT = 512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view){
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main(){
    sf::RenderWindow window(sf::VideoMode(512, 512), "Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

    sf::Texture playerTexture;
    playerTexture.loadFromFile("../textures/penguin.png");

    // tecture sheet
    // sf::Vector2u textureSize = playerTexture.getSize();
    // textureSize.x /= 3;
    // textureSize.y /= 9;
    // player.setTextureRect(sf::IntRect(textureSize.x*2, textureSize.y*8, textureSize.x, textureSize.y));

    // animation
    Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.0f);
    
    Platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
    Platform platform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));

    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen()){
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)){

            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    //printf("w:  %i h: %i\n", event.size.width, event.size.height);
                    ResizeView(window, view);
                    break;
                // case sf::Event::TextEntered:
                //     if (event.text.unicode < 128){
                //         printf("%c", event.text.unicode);
                //     }
            }
        }

        // animation.Update(0, deltaTime, false);
        // player.setTextureRect(animation.uvRect);

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        //     player.move(-0.1f, 0.0f);
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        //     player.move(0.1f, 0.0f);
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        //     player.move(0.0f, -0.1f);
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        //     player.move(0.0f, 0.1f);
        // }

        // if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        //     sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        //     player.setPosition((float)mousePos.x, (float)mousePos.y);
        // }

        player.Update(deltaTime);
        platform1.GetCollider().CheckCollider(player.GetCollider(), 0.0f);
        platform2.GetCollider().CheckCollider(player.GetCollider(), 1.0f);
        view.setCenter(player.GetPosition());

        window.clear();
        window.setView(view);
        player.Draw(window);
        platform1.Draw(window);
        platform2.Draw(window);
        window.display();
    }
    
    return 0;
}