#include <math.h>
#include <chrono>
#include "../include/box2d/box2d.h"
#include "graphics.h"
#include "input.h"
#include "ship.h"

const std::chrono::duration<double, std::ratio<1,60>> ONE_FRAME(1);

const float TIMESTEP = 1.f / 60;
const int32 VELOCITY_ITERATIONS = 8;
const int32 POSITION_ITERATIONS = 3;

using namespace std;

b2World* setupPhysicsWorld()
{
    b2Vec2 gravity(0.f, -10.f);
    b2World* world = new b2World(gravity);

    // ground
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.f, -10.f);
    b2Body* groundBody = world->CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(100.f, 10.f);
    groundBody->CreateFixture(&groundBox, 0.f);

    return world;
}

int main (int argc, char **argv) {
    b2World* world = setupPhysicsWorld();
    Ship ship;
    ship.registerPhysics(world, vector2fl(0, 20));

    sf::RenderWindow* window = setupGraphics(false);

    b2Vec2 position;

    chrono::time_point<chrono::system_clock, chrono::duration<double>> nextFrameStart(chrono::system_clock::now());
    while (window->isOpen()) {
        chrono::time_point<chrono::system_clock, chrono::duration<double>> now(chrono::system_clock::now());
        
        if (now < nextFrameStart)
        {
            display(window, &ship);
        }
        else
        {
            nextFrameStart += ONE_FRAME;

            handleInput(window, &ship);
            ship.iterate();

            world->Step(TIMESTEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
            // position = body->GetPosition();
        }
    }
    
    delete world;

    return 0;
}