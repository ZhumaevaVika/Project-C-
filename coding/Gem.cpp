#include "Gem.h"
#include "Collider.h"

Gem::Gem(sf::Texture* texture, sf::Vector2f pos)
{
    this->totalTime = 0.0f;
    alive = 1;

    body.setSize(sf::Vector2f(20.0f,20.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(pos.x, pos.y);
    body.setTexture(texture);
}

void Gem::Update(Player& player)
{
    if (alive){
        if((*this).GetCollider().CheckCollider(player.GetCollider(), 0.0f) && alive == 1)
        {
            player.XP++;
            alive = false;
            Gem::~Gem();
        }
    }
}

Gem::~Gem(){}

void Gem::Draw(sf::RenderWindow& window){
    if (alive){
        window.draw(body);
    }
}