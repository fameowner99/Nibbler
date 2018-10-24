#include "../inc/Snake.hpp"
#include "../inc/Game.hpp"
#include <iostream>

Snake::Snake() {

}

Snake::~Snake() {}

Snake::Snake(Snake &rhs)
{
    *this = rhs;
}

void Snake::moveSnake()
{
    Object last;
    last = _parts.back();
    _parts.pop_back();
    last._currentPosition.y = _parts.front()._currentPosition.y +  _vectorOfMoving.y;
    last._currentPosition.x = _parts.front()._currentPosition.x +  _vectorOfMoving.x;
    _parts.push_front(last);

}

std::list<Object> Snake::getParts()const
{
    return (_parts);
}

Snake& Snake::operator=(const Snake &rhs) {
    if (this != &rhs)
    {
        _parts.clear();
        for (auto item : rhs.getParts())
        {
            _parts.push_back(item);
        }
    }
    return (*this);
}

bool Snake::operator==(const Snake &rhs)
{
    for (auto &item : _parts)
    {
        for(auto &item1 : rhs.getParts())
        {
            if (item._currentPosition == item1._currentPosition)
                return (false);
        }
    }
    return (true);
}

bool Snake::checkCollision(const int &nX, const int &nY)const
{
    return (_parts.front()._currentPosition.x >= nX || _parts.front()._currentPosition.x < 0 ||
        _parts.front()._currentPosition.y >= nY || _parts.front()._currentPosition.y < 0);
}

void Snake::snakeInitialize(int x, int y)
{
    _parts.push_back(Object(x, y));
    _parts.push_back(Object(x, y + 1));
    _parts.push_back(Object(x, y + 2));
    _vectorOfMoving.x = 0;
    _vectorOfMoving.y = -1;
}