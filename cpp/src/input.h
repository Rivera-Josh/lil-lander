#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include "myvectors.h"
#include "ship.h"

vector2fl joystickAxisToFilteredVector(int controllerNum, int axis);
void handleInput(sf::RenderWindow*, Ship*);

vector2fl getFilteredLeftStickVector();
vector2fl getFilteredRightStickVector();

#endif // INPUT_H