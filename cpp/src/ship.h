#ifndef SHIP_H
#define SHIP_H

#include "../include/box2d/box2d.h"
#include "myvectors.h"

class Ship
{
    b2Body* body;
public:
    Ship();
    void registerPhysics(b2World* world, vector2fl);
    vector2fl getPos();
    void handleInput();
    void iterate();
    void display(sf::RenderWindow*);
};

#endif // SHIP_H