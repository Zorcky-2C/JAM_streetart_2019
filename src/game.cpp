/*
** EPITECH PROJECT, 2020
** JAM_streetart_2019
** File description:
** game
*/

#include "../include/game.hpp"

Game::Game(std::string imagepath, sf::RenderWindow &window) : window(window)
{
    texture_hand.loadFromFile("ressources/open.png");
    texture_hand_close.loadFromFile("ressources/close.png");
    sprite_hand.setTexture(texture_hand);
    sprite_hand.setScale(2, 2);
    textue_supreme.loadFromFile("ressources/supreme.png");
    sprite_supreme.setTexture(textue_supreme);
    sprite_supreme.setScale(0.51, 0.51);
    sprite_supreme.setPosition(100, 500);
    dragged = false;
    lastTime = 0;
    font.loadFromFile("ressources/segoeui.ttf");
    text.setPosition(5, 0);
    text.setFont(font);
    text.setCharacterSize(16);
    text.setString("FPS: ");
    if (!music.openFromFile("ressources/one.ogg"))
        exit(84);
    music.setVolume(50);
    music.play();
    if (!texture.loadFromFile(imagepath))
        exit(84);
    sprite.setTexture(texture);
    if (!texture_can.loadFromFile("ressources/can.png"))
        exit(84);
    sprite_can.setTexture(texture_can);
    sprite_can.setScale(0.2f, 0.2f);
    sprite_can.setPosition(700, 600);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    window.setMouseCursorVisible(false);
    if (!buffer.loadFromFile("ressources/spray_paint.ogg"))
        exit(84);
    sound.setBuffer(buffer);
    sound.setVolume(70);
    srand((unsigned)time(0));
}

Game::~Game()
{

}

void Game::update()
{
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left) {
            sprite_hand.setTexture(texture_hand_close);
        }
        if (event.type == sf::Event::MouseButtonReleased &&
        event.mouseButton.button == sf::Mouse::Left) {
            sprite_hand.setTexture(texture_hand);
            dragged = false;
        }
        if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Right) {
            if (dragged)  {
                sound.play();
                sf::Vector2i mousepoition = static_cast<sf::Vector2i>(sf::Mouse::getPosition(window));
                for (int i = 0; i < 10; i++) {
                    sf::CircleShape point(random(1, 3));
                    point.setPosition(random(sprite_can.getPosition().x - 14, sprite_can.getPosition().x + 14) - 40, random(sprite_can.getPosition().y - 14, sprite_can.getPosition().y + 14));
                    point.setFillColor(sf::Color(255, 0, 0, 255));
                    particules.push_back(point);
                }
            }
        }
        if (event.type == sf::Event::MouseButtonReleased &&
        event.mouseButton.button == sf::Mouse::Right) {
            if (dragged == true) {
                sound.stop();
            }
            exceptions.push_back(circles.size());
        }
    }
    sf::Vector2i mousepoition = sf::Mouse::getPosition(window);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (dragged == true || isInSprite(sprite_can, mousepoition)) {
            dragged = true;
            sprite_can.setPosition(mousepoition.x - 30, mousepoition.y - 40);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                sf::CircleShape point(10);
                point.setPosition(sprite_can.getPosition().x - 40, sprite_can.getPosition().y);
                point.setFillColor(sf::Color(255, 0, 0, 70));
                circles.push_back(point);
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
    }
    sprite_hand.setPosition(mousepoition.x - 9, mousepoition.y);
}

void Game::display()
{
    window.clear();
    window.draw(sprite);
    drawCircles();
    window.draw(sprite_can);
    window.draw(sprite_supreme);
    window.draw(text);
    window.draw(sprite_hand);
    window.display();
    
    sf::Time time = clock.getElapsedTime();
    double fps = 1.0 / time.asSeconds();
    clock.restart().asSeconds();
    text.setString("FPS: " + std::to_string((int)fps));
}

void Game::drawCircles()
{
    float angle;
    size_t size = circles.size();
    int counter = 0;

    for (auto iter = circles.begin(); iter != circles.end(); ++iter, ++counter)
    {
        auto iternext = iter + 1;
        sf::Vector2f pos1 = (*iter).getPosition();
        pos1.x += (*iter).getRadius();
        pos1.y += (*iter).getRadius();
        sf::Vector2f pos2 = (*iternext).getPosition();
        pos2.x += (*iter).getRadius();
        pos2.y += (*iter).getRadius();
        sf::LineShape line(pos1, pos2);
        line.setThickness((*iter).getRadius() * 2);
        line.setFillColor((*iter).getFillColor());

        window.draw(*iter);
        if (counter < size - 1) {
            if (exeptionexists(counter + 1) == 0)
                window.draw(line);
        }
    }
    for (auto iter = particules.begin(); iter != particules.end(); ++iter)
    {
        window.draw(*iter);
    }
}

bool Game::exeptionexists(int ex)
{
    for (int i = 0; i < this->exceptions.size(); i++) {
        if (this->exceptions[i] == ex) {
            return (1);
        }
    }
    return (0);
}

bool Game::isInSprite(sf::Sprite sprite, sf::Vector2i mouseposition)
{
    auto translated_pos = window.mapPixelToCoords(mouseposition);
    if (sprite.getGlobalBounds().contains(translated_pos))
        return (true);
    return (false);
}