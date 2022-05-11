/*
** EPITECH PROJECT, 2022
** snake_cpp_sfml
** File description:
** map
*/

#ifndef MAP_HPP_
    #define MAP_HPP_

    #include "include_sfml.hpp"

    typedef struct {
        sf::RectangleShape shape;
        bool used;
    } case_t;

    class Map {
        public:
            Map();
            ~Map() = default;

            void draw(sf::RenderWindow *window);
            bool is_used(int x, int y);
            void set_used(int x, int y, bool used);

            array<array<case_t, 16>, 16> map_array;
    };

#endif /* !MAP_HPP_ */
