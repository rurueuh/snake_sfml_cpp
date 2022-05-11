/*
** EPITECH PROJECT, 2022
** snake_cpp_sfml
** File description:
** game
*/

#include "game.hpp"

Game::Game()
{
    this->_window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    this->_window->setFramerateLimit(WINDOW_FPS);

    this->_font.loadFromFile("michel/arial.ttf");
    this->_text.setFont(this->_font);
    this->_text.setCharacterSize(30);
    this->_text.setFillColor(sf::Color::White);
    this->_text.setString("0");
}

Game::~Game()
{
    delete this->_window;
}



void Game::events()
{
    while (this->_window->pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            this->_window->close();
        if (this->_event.type == sf::Event::KeyPressed) {
            if (this->_event.key.code == sf::Keyboard::Escape)
                this->_window->close();
            if (this->_event.key.code == sf::Keyboard::A)
                this->stop();
        }
    }
    this->player.change_direction();
}

void Game::update()
{
    this->events();
    this->player.move();
    if (this->item.detect_eat(this->player._position.x, this->player._position.y) == true) {
        this->player.add_score();
        this->item.respawn_item(&this->player);
        this->_text.setString(std::to_string(this->player._score));
    }
    if (this->player._alive == false) {
        this->stop();
    }
}

void Game::render()
{
    this->_window->clear();

    this->map.draw(this->_window);
    this->item.draw(this->_window);
    this->player.draw(this->_window);
    this->_window->draw(this->_text);

    this->_window->display();
}

void Game::run()
{
    while (this->_window->isOpen()) {
        this->events();
        this->update();
        this->render();
    }
}

void Game::reset()
{
    this->item.respawn_item(&this->player);
    for (int i = 1; i < this->player._shape.size(); i++) {
        this->player._shape[i].setFillColor(sf::Color::Transparent);
    }
    this->player._position = sf::Vector2f(0, 0);
    this->player._shape[0].setPosition(sf::Vector2f(600, 100));
    this->player._direction = {DOWN};
    this->player._score = 0;
    this->player._alive = true;
    this->_text.setString("0");

}

void Game::stop()
{
    this->_text.setString("GAME OVER\n Press R to restart");
    this->_text.setPosition(sf::Vector2f(WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 - 100));
    while (this->_window->isOpen()) {
        this->_window->clear();
        while (this->_window->pollEvent(this->_event)) {
            if (this->_event.type == sf::Event::Closed)
                this->_window->close();
            if (this->_event.type == sf::Event::KeyPressed) {
                if (this->_event.key.code == sf::Keyboard::Escape)
                    this->_window->close();
                if (this->_event.key.code == sf::Keyboard::R){
                    this->reset();
                }
            }
        }
        if (this->player._alive == true)
            break;
        this->_window->draw(this->_text);
        this->_window->display();
    }
    this->_text.setString("0");
    this->_text.setPosition(sf::Vector2f(0, 0));
}
