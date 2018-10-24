#include "../inc/Position.hpp"

bool Position::operator==(const Position &rhs)
{
    return (this->x == rhs.x && this->y == rhs.y);
}