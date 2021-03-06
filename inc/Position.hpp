#ifndef POSITION_HPP

# define POSITION_HPP

class Position
{
    public:
        int x;
        int y;
        bool operator==(const Position &rhs); // return true if equal
        Position&operator=(const Position &rhs);
};

#endif