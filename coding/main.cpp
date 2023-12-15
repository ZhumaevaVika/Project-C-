#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include "Player.h"
#include "Platform.h"
#include "Bat.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Whip.h"
#include "Gem.h"
#include "Visuals.h"
#include "Fire.h"

static const float VIEW_HEIGHT = 512.0f;
std::vector<Enemy> enemies;
std::vector<Gem> gems;
sf::Texture batTexture1;
sf::Texture batTexture2;
sf::Texture batTexture3;



void ResizeView(const sf::RenderWindow& window, sf::View& view){
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

void spawn_enemies(Player player, int num_enemies, std::string enemy_type) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < num_enemies; i++) {
        bool x_bool = std::rand() % 2 == 0;
        bool y_bool = std::rand() % 2 == 0;
        int x = (player.GetPosition().x + 256 + std::rand() % 101)*x_bool + (player.GetPosition().x - 256 -  std::rand() % 101)*(1-x_bool);
        int y = (player.GetPosition().y + 256 + std::rand() % 101)*y_bool + (player.GetPosition().y - 256 -  std::rand() % 101)*(1-y_bool);

        if (enemy_type == "Bat1"){
            batTexture1.loadFromFile("../textures/bat1.png");
            Bat bat(&batTexture1, player, x, y, 1);
            enemies.push_back(bat);
        }
        if (enemy_type == "Bat2"){
            batTexture2.loadFromFile("../textures/bat2.png");
            Bat bat(&batTexture2, player, x, y, 3);
            enemies.push_back(bat);
        }
        if (enemy_type == "Bat3"){
            batTexture3.loadFromFile("../textures/bat3.png");
            Bat bat(&batTexture3, player, x, y, 5);
            enemies.push_back(bat);
        }
    }
}

void random_spawn(Player player){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int n = 1;
    int t = std::rand() % 3;

    if (t == 0){
        spawn_enemies(player, n, "Bat1");
    }
    if (t == 1){
        spawn_enemies(player, n, "Bat2");
    }
    if (t == 2){
        spawn_enemies(player, n, "Bat3");
    }
}

int main(){
    sf::RenderWindow window(sf::VideoMode(512, 512), "Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

    sf::Texture playerTexture;
    playerTexture.loadFromFile("../textures/antonio.png");

    sf::Texture whipTexture;
    whipTexture.loadFromFile("../textures/attack-whip.png");

    sf::Texture gemTexture;
    gemTexture.loadFromFile("../textures/gem.png");

    sf::Texture fireTexture;
    fireTexture.loadFromFile("../textures/fire.png");

    Player player(&playerTexture, sf::Vector2u(4, 2), 0.2f, 100.0f);
    
    Platform platform1(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
    Platform platform2(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));

    spawn_enemies(player, 1, "Bat1");

    Whip whip(&whipTexture, player);

    Fire fire(&fireTexture, player, 300, 300, 10000);

    sf::RectangleShape game_over;  
        sf::Texture gameover_Texture; 
        gameover_Texture.loadFromFile("../textures/game_over.png"); 
        game_over.setSize(sf::Vector2f(233.4f, 37.8f)); 
        game_over.setOrigin(game_over.getSize() / 2.0f);  
        game_over.setTexture(&gameover_Texture);

    Bar xp_bar(sf::Color::Blue, player, player.XP, 50, -100.0f, -200.0f, sf::Vector2f(200.0f, 10.0f)); 
    Bar health_bar(sf::Color::Red, player, player.HP, player.HP, -25.0f, 60.0f, sf::Vector2f(50.0f, 5.0f));

    float deltaTime = 0.0f;
    sf::Clock clock;
    auto startTime = std::chrono::steady_clock::now();
    bool spawn = true;

    while (window.isOpen()){
        deltaTime = clock.restart().asSeconds();
        // auto endTime = std::chrono::steady_clock::now();
        // auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
        // if ((duration.count()%5 == 0) && (spawn == true)){
        //     random_spawn(player);
        //     spawn = false;
        // }
        // if ((duration.count()%5 != 0) && (spawn == false)){
        //     spawn = true;
        // }

        sf::Event event;
        while (window.pollEvent(event)){

            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    ResizeView(window, view);
                    break;
            }
        }

        player.Update(deltaTime);
        platform1.GetCollider().CheckCollider(player.GetCollider(), 0.0f);
        platform2.GetCollider().CheckCollider(player.GetCollider(), 0.6f);
        
        for (auto& enemy : enemies){
            whip.DamageEnemy(enemy, deltaTime);
        }

        for (auto& enemy : enemies){
            enemy.Update(deltaTime, player);
        }

        for (auto& enemy : enemies){
            if (enemy.alive == false && enemy.spawned == false){
                Gem gem(&gemTexture, sf::Vector2f(enemy.GetPosition().x, enemy.GetPosition().y));
                gems.push_back(gem);
                enemy.spawned = true;
            }
        }

        for (int i = 0; i < enemies.size(); i++) {
            for (int j = i + 1; j < enemies.size(); j++) {
                enemies[i].GetCollider().CheckCollider(enemies[j].GetCollider(), 0.0f);
            }
        }

        for (auto& gem : gems){
            gem.Update(player);
        }
        health_bar.Update(player, player.HP); 
        xp_bar.Update(player, player.XP);
        whip.Update(deltaTime, player);
        fire.Update(deltaTime, player);
        view.setCenter(player.GetPosition());
        window.clear(sf::Color(0, 128, 0));
        window.setView(view);
        if(player.alive) 
        { 
            player.Draw(window); 
            platform1.Draw(window); 
            platform2.Draw(window); 
            for (auto& enemy : enemies){ 
                enemy.Draw(window); 
            } 
            for (auto& gem : gems){ 
                if (gem.alive == true){ 
                    gem.Draw(window); 
                } 
            } 
            whip.Draw(window); 
            health_bar.Draw(window); 
            xp_bar.Draw(window);
            fire.Draw(window);
        } 
        else 
        { 
            game_over.setPosition(player.GetPosition().x, player.GetPosition().y); 
            window.draw(game_over); 
        }
        window.display();
    }    
    return 0;
}