#ifndef SHIP_H
#define SHIP_H

#include "../include/box2d/box2d.h"
#include "myvectors.h"

const float SHIP_THRUST_FORCE = 10000;
const float SHIP_TURN_TORQUE = 20000;

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