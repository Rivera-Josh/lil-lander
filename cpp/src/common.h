#ifndef COMMON_H
#define COMMON_H

#include <SFML/Graphics.hpp>
#include "../include/box2d/box2d.h"
#include "myvectors.h"

sf::Vector2f toSFVec(vector2fl v);
sf::Vector2i toSFVec(vector2i v);
vector2fl fromSFVec(sf::Vector2f v);
vector2i fromSFVec(sf::Vector2i v);

vector2fl fromB2dVec(b2Vec2 v);
b2Vec2 toB2dVec(vector2fl v);


#endif // COMMON_H