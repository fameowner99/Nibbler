#ifndef GAME_HPP

# define GAME_HPP

#include "Object.hpp"
#include "Snake.hpp"
#include <vector>
#include "GUI.hpp" // will be deleted after creating dynamic library

# define CELL_HEIGHT 100
# define CELL_WIDTH 100
# define MIN_HEIGHT 500
# define MIN_WIDTH 500
# define MAX_HEIGHT 2000
# define MAX_WIDTH 2000


class Game
{
    public:
        Game();
        ~Game();
        Game(int hight, int width);
        void loop(); // game loop here (update, move etc.)
    private:
        int _height;
        int _width;
        GUI gui;
        Snake snake;
        std::vector<Object> food;
        bool gameOver;
};

#endif