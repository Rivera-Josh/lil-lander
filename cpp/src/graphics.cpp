#include "graphics.h"
#include "myvectors.h"
#include "common.h"
#include "ship.h"

sf::RenderWindow* setupGraphics(bool fullscreen)
{
    // if (!font.loadFromFile("Andale_Mono.ttf"))
    //     throw runtime_error("Can't load main font");

    auto flags =
        fullscreen ? sf::Style::Close | sf::Style::Fullscreen
                   : sf::Style::Close | sf::Style::Titlebar;
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(sf::Vector2u(1280, 720), 24), "SFML Start", flags);
    window->setKeyRepeatEnabled(false);

    return window;
}

void display(sf::RenderWindow* window, Ship* ship)
{
    sf::Color backgroundColor(0, 0, 50);
    window->clear(backgroundColor);

    // draw ground
    sf::RectangleShape ground(sf::Vector2f(200, 20));
    ground.setOrigin(sf::Vector2f(100, 10));
    ground.setPosition(sf::Vector2f(0, 10));
    ground.setFillColor(sf::Color::Blue);
    window->draw(ground);

    ship->display(window);

    sf::View view = window->getView();
    vector2fl cameraCenter = ship->getPos();
    cameraCenter.y *= -1;
    view.setCenter(toSFVec(cameraCenter));
    window->setView(view);

    window->display();
}

void Ship::display(sf::RenderWindow* window)
{
    sf::RectangleShape rect(sf::Vector2f(2, 2));
    rect.setOrigin(sf::Vector2f(1, 1));
    vector2fl position = fromB2dVec(body->GetPosition());
    position.y *= -1;
    float rotation = body->GetAngle();
    rect.setPosition(toSFVec(position));
    rect.setRotation(-sf::radians(rotation));
    rect.setFillColor(sf::Color::Red);
    window->draw(rect);
}