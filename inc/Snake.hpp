#ifndef SNAKE_HPP

#define  SNAKE_HPP

#include "../inc/Object.hpp"
#include "Position.hpp"
#include <vector>
#include <list>

class Snake
{
    public:
        Snake();
        ~Snake();
        Snake(Snake &rhs);
        Snake&operator=(const Snake &rhs);
        bool operator==(const Snake &rhs); // true if all possitions of snakes' parts are different
        void moveSnake(); // move snake to next cell (cut off last part and push it on the front)
        void addPart();
        bool checkSelfCollision();
        bool checkCollision(const int &nX, const int &nY)const; //check that head's position not more than max position, return true if OK
        std::list<Object> getParts()const;
        void    snakeInitialize(int x, int y);
        Position    getVectorOfMoving();
        void        setVectorOfMoving(int x, int y);
    private:
        std::list<Object> _parts;
        Position _vectorOfMoving; // vector where will move head, vector will change by pressing on turn buttons
};

#endif