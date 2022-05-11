/*
** EPITECH PROJECT, 2022
** snake_cpp_sfml
** File description:
** player
*/

#include "game.hpp"

Player::Player()
{
    this->_shape[0].setSize(sf::Vector2f(49, 49));
    this->_shape[0].setPosition(sf::Vector2f(600, 100));
    this->_shape[0].setFillColor(sf::Color::Green);
}

void Player::draw(sf::RenderWindow *window)
{
    for (auto &shape : this->_shape)
        window->draw(shape);
}

void Player::change_direction()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->_direction = UP;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->_direction = DOWN;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->_direction = LEFT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->_direction = RIGHT;
}

void Player::add_score()
{
    this->_score++;

    if (this->_direction == UP){
        this->_shape[this->_score ].setPosition(
            this->_shape[this->_score - 1].getPosition().x,
            this->_shape[this->_score - 1].getPosition().y + 50
        );
    }

    if (this->_direction == DOWN){
        this->_shape[this->_score ].setPosition(
            this->_shape[this->_score - 1].getPosition().x,
            this->_shape[this->_score - 1].getPosition().y - 50
        );
    }

    if (this->_direction == LEFT){
        this->_shape[this->_score].setPosition(
            this->_shape[this->_score - 1].getPosition().x + 50,
            this->_shape[this->_score - 1].getPosition().y
        );
    }

    if (this->_direction == RIGHT){
        this->_shape[this->_score].setPosition(
            this->_shape[this->_score - 1].getPosition().x - 50,
            this->_shape[this->_score - 1].getPosition().y
        );
    }
    this->_shape[this->_score].setFillColor(sf::Color::Green);
    this->_shape[this->_score].setSize(sf::Vector2f(49, 49));
}

void Player::move()
{
    if (this->_clock.getElapsedTime().asSeconds() >= 0.2) {
        sf::Vector2f position_save = this->_shape[0].getPosition();

        switch (this->_direction) {
            case UP:
                this->_shape[0].move(0, -50);
                this->_position.y -= 1;
                break;
            case DOWN:
                this->_shape[0].move(0, 50);
                this->_position.y += 1;
                break;
            case LEFT:
                this->_shape[0].move(-50, 0);
                this->_position.x -= 1;
                break;
            case RIGHT:
                this->_shape[0].move(50, 0);
                this->_position.x += 1;
                break;
        }

        // tail connector
        for (int i = this->_score; i >= 1; i--) {
            sf::Vector2f pos = this->_shape[i - 1].getPosition();
            this->_shape[i].setPosition(pos);
            if (i == 1) {
                this->_shape[i].setPosition(position_save);
            }
        }

        // map collision
        if (this->_shape[0].getPosition().x < 600){
            this->_shape[0].setPosition(sf::Vector2f(600, this->_shape[0].getPosition().y));
            this->_position.x += 1;
            this->_alive = false;
        }

        if (this->_shape[0].getPosition().x > 600 + (15 * 50)){
            this->_shape[0].setPosition(sf::Vector2f(600 + (15 * 50), this->_shape[0].getPosition().y));
            this->_position.x -= 1;
            this->_alive = false;
        }

        if (this->_shape[0].getPosition().y < 100){
            this->_shape[0].setPosition(sf::Vector2f(this->_shape[0].getPosition().x, 100));
            this->_position.y += 1;
            this->_alive = false;
        }

        if (this->_shape[0].getPosition().y > 100 + (15 * 50)){
            this->_shape[0].setPosition(sf::Vector2f(this->_shape[0].getPosition().x, 100 + (15 * 50)));
            this->_position.y -= 1;
            this->_alive = false;
        }

        // tail collision
        for (int i = 1; i < this->_score; i++) {
            if (this->_shape[0].getGlobalBounds().intersects(this->_shape[i].getGlobalBounds())) {
                this->_shape[0].setPosition(position_save);
                this->_alive = false;
            }
        }
        this->_clock.restart();
    }
}
