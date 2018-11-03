#include "Object.hpp"

Object::Object()
{

}

Object::Object(Position &pos)
{
    _currentPosition.x = pos.x;
    _currentPosition.y = pos.y;
}

Object::Object(int x, int y)
{
    _currentPosition.x = x;
    _currentPosition.y = y;
}