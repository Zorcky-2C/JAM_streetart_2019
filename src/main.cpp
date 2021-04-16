/*
** EPITECH PROJECT, 2020
** JAM_streetart_2019
** File description:
** main
*/

#include "../include/game.hpp"
#include "../include/menu.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Street Art");
    std::unique_ptr<Menu> menu = std::make_unique<Menu>(window);
    std::string image = menu->run_menu();
    std::unique_ptr<Game> game = std::make_unique<Game>(image, window);

    while (game->isOpen()) {
        game->update();
        game->display();
    }
    return (0);
}