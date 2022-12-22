#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
#include "common.h"
#include "input.h"

using namespace std;

Ship::Ship() {}
void Ship::registerPhysics(b2World* world, vector2fl position)
{
    // object body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    body = world->CreateBody(&bodyDef);

    //sets points to make triangle
    b2Vec2 triangleVerts[3];
    triangleVerts[0].Set((-4), (4));
    triangleVerts[1].Set((4), (4));
    triangleVerts[2].Set((0), (12));
    b2PolygonShape dynamicTriangle;
    dynamicTriangle.Set(triangleVerts, 3);

    
    b2FixtureDef fixtureHeadDef;
    fixtureHeadDef.shape = &dynamicTriangle;
    fixtureHeadDef.density = 1.f;
    fixtureHeadDef.friction = 0.3;

    //set points to make square base
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(4.f, 4.f);
    
    b2FixtureDef fixtureBaseDef;
    fixtureBaseDef.shape = &dynamicBox;
    fixtureBaseDef.density = 1.f;
    fixtureBaseDef.friction = 0.3;

    body->CreateFixture(&fixtureBaseDef);

    body->CreateFixture(&fixtureHeadDef);
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

    body->ApplyTorque(-turnAmount*SHIP_TURN_TORQUE, true);

    if (sf::Joystick::isButtonPressed(0, 0))
    {
        float thrustAngle = body->GetAngle() + (M_PI/2);
        vector2fl force = composeVector2fl(thrustAngle, SHIP_THRUST_FORCE);
        body->ApplyForceToCenter(toB2dVec(force), true);
    }
}