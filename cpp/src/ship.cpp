#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
#include "common.h"
#include "input.h"

using namespace std;

Ship::Ship() {}

void Ship::registerPhysics(b2World* world, vector2fl position)
{
    // object
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.angle = M_PI / 2;
    body = world->CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.f, 1.f);
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.f;
    fixtureDef.friction = 0.3;

    body->CreateFixture(&fixtureDef);
    body->SetAngularDamping(0.01);
}

vector2fl Ship::getPos()
{
    return fromB2dVec(body->GetPosition());
}

void Ship::iterate()
{
}

void Ship::handleInput()
{
    float turnAmount = getFilteredLeftStickVector().x;
    body->ApplyTorque(-turnAmount*10, true);

    if (sf::Joystick::isButtonPressed(0, 0))
    {
        float angle = body->GetAngle();
        vector2fl force = composeVector2fl(angle, 100);
        body->ApplyForceToCenter(toB2dVec(force), true);
    }
}