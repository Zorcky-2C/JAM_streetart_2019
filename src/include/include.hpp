/*
** EPITECH PROJECT, 2020
** JAM_streetart_2019
** File description:
** include
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/lineshape.hpp"
#include <iostream>
#include <ctime>

int random(int minimum_number, int max_number);

/*
sf::Sprite loadSprite(std::string path)
{
    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile(path)) {
        std::cout << "Error: Loading texture" << std::endl;
        exit(84);
    }
    sprite.setTexture(texture);
    return (sprite);
}

std::map<enum SPRITE, sf::Sprite> getSprites()
{
    std::map<enum SPRITE, sf::Sprite> sprites;
    sprites.insert(std::make_pair(SPRITE::BACKGROUND, loadSprite("ressources/subway.jpg")));
    return (sprites);
}

void displaySprites(std::map<enum SPRITE, sf::Sprite> &sprites)
{
    for (std::map<enum SPRITE, sf::Sprite>::const_iterator iter = sprites.begin(); iter != sprites.end(); ++iter) {
        window.draw(iter->second);
    }
}*/