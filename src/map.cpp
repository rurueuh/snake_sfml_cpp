/*
** EPITECH PROJECT, 2022
** snake_cpp_sfml
** File description:
** map
*/

#include "game.hpp"

Map::Map()
{
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            this->map_array[i][j].shape.setSize(sf::Vector2f(50, 50));
            this->map_array[i][j].shape.setPosition(sf::Vector2f(i * 50 + 600, j * 50 + 100));
            this->map_array[i][j].shape.setOutlineColor(sf::Color::Red);
            this->map_array[i][j].shape.setOutlineThickness(1);
            this->map_array[i][j].shape.setFillColor(sf::Color::Black);
            this->map_array[i][j].used = false;
        }
    }
}

void Map::set_used(int x, int y, bool used)
{
    this->map_array[x][y].used = used;
}

bool Map::is_used(int x, int y)
{
    return this->map_array[x][y].used;
}

void Map::draw(sf::RenderWindow *window)
{
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            window->draw(this->map_array[i][j].shape);
        }
    }
}
