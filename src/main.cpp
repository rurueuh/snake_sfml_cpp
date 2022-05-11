/*
** EPITECH PROJECT, 2022
** snake_cpp_sfml
** File description:
** main
*/

#include "game.hpp"

int main(void)
{
    srand(time(NULL));
    Game game;
    game.run();
    return 0;
}