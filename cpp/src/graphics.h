#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SFML/Graphics.hpp>
#include "myvectors.h"
#include "ship.h"

sf::RenderWindow* setupGraphics(bool fullscreen);
void display(sf::RenderWindow*, Ship*);

#endif // GRAPHICS_H