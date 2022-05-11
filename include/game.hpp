/*
** EPITECH PROJECT, 2022
** fake_hearthstone
** File description:
** game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_

    #include "include_sfml.hpp"
    #include "map.hpp"
    #include "player.hpp"
    #include "item.hpp"

    #define     WINDOW_WIDTH        1920
    #define     WINDOW_HEIGHT       1080
    #define     WINDOW_TITLE        "Snake"
    #define     WINDOW_FPS          60

    class Game {
        public:
            Game();
            ~Game();

            void run();
            void reset();
            void stop();
            void update();
            void events();
            void render();

            Map map;
            Player player;
            Item item;

        private:
            sf::RenderWindow    *_window;
            sf::Font            _font;
            sf::Text            _text;
            sf::Event           _event;
            sf::Clock           _clock;
        };

#endif
