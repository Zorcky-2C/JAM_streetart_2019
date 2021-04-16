/*
** EPITECH PROJECT, 2020
** JAM_streetart_2019
** File description:
** game
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/lineshape.hpp"
#include "../include/include.hpp"
#include <iostream>
#include <ctime>

class Game
{
    public:
        Game(std::string imagepath, sf::RenderWindow &window);
        ~Game();
        bool isOpen() { return (window.isOpen()); }
        void update();
        void display();
    protected:
        bool isInSprite(sf::Sprite sprite, sf::Vector2i mouseposition);
        bool exeptionexists(int ex);
        void drawCircles();
    private:
        std::vector<sf::CircleShape> circles;
        std::vector<sf::CircleShape> particules;
        sf::RenderWindow &window;
        std::vector<int> exceptions;

        sf::Texture texture;
        sf::Texture texture_hand;
        sf::Texture texture_hand_close;
        sf::Texture textue_supreme;
        sf::Texture texture_can;
    
        sf::Sprite sprite;
        sf::Sprite sprite_hand;
        sf::Sprite sprite_supreme;
        sf::Sprite sprite_can;
    
        sf::Event event;
        bool dragged;

        sf::Clock clock;
        double lastTime;

        sf::Music music;
        sf::Text text;
        sf::Font font;
        sf::SoundBuffer buffer;
        sf::Sound sound;
};