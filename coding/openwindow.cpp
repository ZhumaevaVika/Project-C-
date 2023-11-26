#include <SFML/Graphics.hpp>
#include <iostream>

int main(){
    sf::RenderWindow window(sf::VideoMode(512, 512), "Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    //player.setFillColor(sf::Color::Cyan);
    player.setOrigin(50.0f, 50.0f);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("textures/san.jpg");
    player.setTexture(&playerTexture);

    // tecture sheet
    // sf::Vector2u textureSize = playerTexture.getSize();
    // textureSize.x /= 3;
    // textureSize.y /= 9;
    // player.setTextureRect(sf::IntRect(textureSize.x*2, textureSize.y*8, textureSize.x, textureSize.y));

    // animation
    


    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){

            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    printf("w:  %i h: %i\n", event.size.width, event.size.height);
                    break;
                // case sf::Event::TextEntered:
                //     if (event.text.unicode < 128){
                //         printf("%c", event.text.unicode);
                //     }
            }
        }

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

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            player.setPosition((float)mousePos.x, (float)mousePos.y);
        }

        window.clear();
        window.draw(player);
        window.display();
    }
    
    return 0;
}