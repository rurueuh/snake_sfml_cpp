/*
** EPITECH PROJECT, 2022
** snake_cpp_sfml
** File description:
** player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include "include_sfml.hpp"

    enum direction_t {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    class Player {
        public:
            Player();
            ~Player() = default;

            void draw(sf::RenderWindow *window);
            void move();
            void change_direction();
            void add_score();

            sf::Vector2f        _position       {0, 0};
            u_int8_t            _score          {0};
            std::array<sf::RectangleShape, 16 * 16> _shape;
            bool                _alive          {true};
            u_int8_t            _direction      {DOWN};
        private:
            sf::Clock           _clock;
            // u_int8_t         _speed;
    };

#endif /* !PLAYER_HPP_ */
