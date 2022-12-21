#include "common.h"

sf::Vector2f toSFVec(vector2fl v)
{
    return sf::Vector2f(v.x, v.y);
}
sf::Vector2i toSFVec(vector2i v)
{
    return sf::Vector2i(v.x, v.y);
}
vector2fl fromSFVec(sf::Vector2f v)
{
    return vector2fl(v.x, v.y);
}
vector2i fromSFVec(sf::Vector2i v)
{
    return vector2i(v.x, v.y);
}

vector2fl fromB2dVec(b2Vec2 v)
{
    return vector2fl(v.x, v.y);
}
b2Vec2 toB2dVec(vector2fl v)
{
    return b2Vec2(v.x, v.y);
}
