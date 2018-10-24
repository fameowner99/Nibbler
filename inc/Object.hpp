#ifndef OBJECT_HPP

# define OBJECT_HPP

#include "Position.hpp"

class Object
{
    public:
        Object();
        Object(int x, int y);
        Object(Position &pos);
        Position _currentPosition;
};

#endif