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
    dynamicBox.SetAsBox(4.f, 4.f);
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.f;
    fixtureDef.friction = 0.3;

    body->CreateFixture(&fixtureDef);
    body->SetAngularDamping(5);
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

    //cout << body->GetAngularVelocity() << endl;
    body->ApplyTorque(-turnAmount*SHIP_TURN_TORQUE, true);
    
    
    

    if (sf::Joystick::isButtonPressed(0, 0))
    {
        float angle = body->GetAngle();
        vector2fl force = composeVector2fl(angle, SHIP_THRUST_FORCE);
        body->ApplyForceToCenter(toB2dVec(force), true);
    }
}