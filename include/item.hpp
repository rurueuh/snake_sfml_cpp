/*
** EPITECH PROJECT, 2022
** snake_cpp_sfml
** File description:
** item
*/

#ifndef ITEM_HPP_
    #define ITEM_HPP_

    #include "include_sfml.hpp"

    class Item {
        public:
            Item();
            ~Item() = default;

            void draw(sf::RenderWindow *window);
            void respawn_item(Player *player);
            bool detect_eat(float x, float y);
        private:
            sf::RectangleShape  _shape;
            sf::Vector2f        _position       {0, 0};
    };

#endif /* !ITEM_HPP_ */
