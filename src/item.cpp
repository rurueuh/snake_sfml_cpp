/*
** EPITECH PROJECT, 2022
** snake_cpp_sfml
** File description:
** item
*/

#include "game.hpp"

Item::Item()
{
    this->_shape.setSize(sf::Vector2f(49, 49));
    this->_position = sf::Vector2f(rand() % 15, rand() % 15);
    this->_shape.setPosition(sf::Vector2f(600 + this->_position.y * 50, 100 + this->_position.x * 50));
    this->_shape.setFillColor(sf::Color::Blue);
}

void Item::draw(sf::RenderWindow *window)
{
    window->draw(this->_shape);
}

void Item::respawn_item(Player *player)
{
    uint8_t x = rand() % 15;
    uint8_t y = rand() % 15;
    this->_position = sf::Vector2f(x, y);
    this->_shape.setPosition(sf::Vector2f(600 + this->_position.y * 50, 100 + this->_position.x * 50));
    for (int i = player->_score; i > 0; i--) {
        sf::Vector2f pos_player = player->_shape[i].getPosition();
        if (pos_player == this->_shape.getPosition()) {
            this->respawn_item(player);
        }
    }
}

bool Item::detect_eat(float y, float x)
{
    if (this->_position.x == x && this->_position.y == y){
        return true;
    } else {
        return false;
    }
}
