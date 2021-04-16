/*
** EPITECH PROJECT, 2020
** JAM_streetart_2019
** File description:
** menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <SFML/Graphics.hpp>
#include <memory>

struct sprite_t
{
    sf::Texture texture;
    sf::CircleShape sprite;
    std::string filepath;
};

struct text_t
{
    sf::Font font;
    sf::Text text;
    std::string filepath;
};

class Menu
{
    public:
        Menu(sf::RenderWindow &window);
        ~Menu();

        sprite_t init_sprite(std::string filename, int x, int y);
        text_t init_text(std::string filename, int x, int y);
        void display_sprite();
        bool isInSprite(sf::CircleShape sprite, sf::Vector2i mouseposition);
        std::string check_button();
        std::string run_menu();
    
    protected:
        sf::RenderWindow &_window;
        sf::Event _event;
        std::vector<sprite_t> _sprite_list;
};

#endif /* MENU_HPP_ */