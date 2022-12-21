#include <iostream>
#include "input.h"

using namespace std;

vector2fl scaleAndFilterJoystickVector(vector2fl inputVec)
{
    inputVec = inputVec / 100.f;

    if (inputVec.getMagnitude() < 0.15) {
        return vector2fl();
    }
    else {
        return inputVec;
    }
}

vector2fl getFilteredLeftStickVector()
{
    return scaleAndFilterJoystickVector(
        vector2fl(sf::Joystick::getAxisPosition(0, sf::Joystick::X),
                  sf::Joystick::getAxisPosition(0, sf::Joystick::Y)
                )
    );
}

vector2fl getFilteredRightStickVector()
{
    return scaleAndFilterJoystickVector(
        vector2fl(sf::Joystick::getAxisPosition(0, sf::Joystick::U),
                  sf::Joystick::getAxisPosition(0, sf::Joystick::V)
                )
    );
}

void handleInput(sf::RenderWindow* window, Ship* ship)
{
    ship->handleInput();

    sf::Event event;

    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window->close();
                }
                break;
            default:
                break;
        }
    }
}