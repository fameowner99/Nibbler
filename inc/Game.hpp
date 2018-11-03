#ifndef GAME_HPP

# define GAME_HPP

#include "Object.hpp"
#include "Snake.hpp"
#include <vector>
#include <random>
#include "GUI.hpp" // will be deleted after creating dynamic library
#include "GUI1.hpp"

# define CELL_HEIGHT 50
# define CELL_WIDTH 50
# define MIN_HEIGHT 500
# define MIN_WIDTH 500
# define MAX_HEIGHT 2000
# define MAX_WIDTH 2000
# define FPS 5


class Game
{
    public:
        Game();
        ~Game();
        Game(int hight, int width);
        void loop(); // game loop here (update, move etc.)
    private:
        void    generateFood();
        bool	eatFood();
        int _height;
        int _width;
        GUI gui;
        Snake snake;
        std::vector<Object> _food;
        bool gameOver;
        Uint32       start;
		Position vectorOfTurn;
};

#endif