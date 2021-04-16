/*
** EPITECH PROJECT, 2020
** JAM_streetart_2019
** File description:
** menu
*/

#include "../include/menu.hpp"
#include <iostream>
#include <vector>

Menu::Menu(sf::RenderWindow &window) : _window(window)
{
}

Menu::~Menu()
{
}

sprite_t Menu::init_sprite(std::string filename, int x, int y)
{
    sprite_t new_sprite;

    new_sprite.filepath = filename;
    if (!new_sprite.texture.loadFromFile(filename)) {
        std::cerr << "File: " << filename << " not found." << std::endl;
        // return error;                                    ////   <--- should return error  
    }
    sf::CircleShape shape(75);
    shape.setTexture(&new_sprite.texture);
    shape.setPosition(x, y);
    new_sprite.sprite = shape;
    return new_sprite;
}

text_t Menu::init_text(std::string filename, int x, int y)
{
    text_t new_text;

    new_text.filepath = filename;
    if (!new_text.font.loadFromFile(filename)) {
        std::cerr << "File: " << filename << " not found." << std::endl;
        // return error;                                    ////   <--- should return error  
    }
    sf::Text text;
    text.setFont(new_text.font);
    text.setString("Select background to continue:");
    text.setCharacterSize(56);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x, y);
    new_text.text = text;
    return new_text;
}

void Menu::display_sprite()
{
    for (auto i = this->_sprite_list.begin(); i != this->_sprite_list.end(); ++i) {
        this->_window.draw((i->sprite));
    }
}

bool Menu::isInSprite(sf::CircleShape sprite, sf::Vector2i mouseposition)
{
    auto translated_pos = this->_window.mapPixelToCoords(mouseposition);
    if (sprite.getGlobalBounds().contains(translated_pos))
        return (true);
    return (false);
}

std::string Menu::check_button()
{
    sf::Vector2i vector = sf::Mouse::getPosition(this->_window);

    int counter = 0;
    for (auto i = this->_sprite_list.begin(); i != this->_sprite_list.end(); ++i, ++counter) {
        if (isInSprite(i->sprite, vector) == true) {
            i->sprite.setTextureRect(sf::IntRect(100, 50, 600, 600));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                return (i->filepath);
            }
        } else
            i->sprite.setTextureRect(sf::IntRect(100, 50, 700, 700));
    }
    return ("NULL");
}

std::string Menu::run_menu()
{
    std::string filepath = "ressources/wall9.jpg";
    std::string ret = "NULL";
    sf::Texture texture;
    text_t text = init_text("ressources/Black Hold.ttf", 310, 130);
    sf::Sprite background;
    if (!texture.loadFromFile(filepath)) {
        std::cerr << "File: " << filepath << " not found." << std::endl;
        return "NULL";                                                  ////   <--- should return error
    }
    background.setTexture(texture);
    
    sprite_t button1 = init_sprite("ressources/subway.jpg", 320, 220);
    sprite_t button2 = init_sprite("ressources/cellars.jpg", 500, 220);
    sprite_t button3 = init_sprite("ressources/dump.jpg", 680, 220);
    sprite_t button4 = init_sprite("ressources/garage.jpg", 860, 220);
    sprite_t button5 = init_sprite("ressources/hose.jpg", 320, 420);
    sprite_t button6 = init_sprite("ressources/pedestrians.jpg", 500, 420);
    sprite_t button7 = init_sprite("ressources/render.jpg", 680, 420);
    sprite_t button8 = init_sprite("ressources/tiles.jpg", 860, 420);

    this->_sprite_list.push_back(button1);
    this->_sprite_list.push_back(button2);
    this->_sprite_list.push_back(button3);
    this->_sprite_list.push_back(button4);
    this->_sprite_list.push_back(button5);
    this->_sprite_list.push_back(button6);
    this->_sprite_list.push_back(button7);
    this->_sprite_list.push_back(button8);

    while (this->_window.isOpen()) {
        while (this->_window.pollEvent(this->_event)) {
            if (this->_event.type == sf::Event::Closed)
                this->_window.close();
        }
        this->_window.clear();
        this->_window.draw(background);
        this->_window.draw(text.text);
        display_sprite();
        ret = check_button();
        if (ret.compare("NULL") != 0)
            return ret;
        this->_window.display();
    }
    return "NULL";                                                        ////   <--- should return something idk :(
}