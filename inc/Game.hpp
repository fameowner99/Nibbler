#ifndef GAME_HPP

# define GAME_HPP

#include "Object.hpp"
#include "Snake.hpp"
#include <vector>
#include <random>
#include <unistd.h>

#include "GUI_sdl.hpp" // will be deleted after creating dynamic library

#include <dlfcn.h>

# define CELL_HEIGHT 50
# define CELL_WIDTH 50
# define MIN_HEIGHT 500
# define MIN_WIDTH 500
# define MAX_HEIGHT 2000
# define MAX_WIDTH 2000
# define FPS 7


class Game
{
    public:
        Game();
        ~Game();
        Game(int hight, int width);
        void loop(); // game loop here (update, move etc.)
    private:
        bool connectLibrary(const char* path); //connect dynamic library with handler, return false if file is missing
        void    generateFood(); //add food to vector
        bool	eatFood(); //if position of head == position food => food delete
        int _height;
        int _width;
        IGUI *gui;
        void *handler; //pointer for dynamic library, null if error
        Snake snake;
        std::vector<Object> _food;
        bool gameOver; //variable for game LOOP
        Uint32     start; //should be changed (see end of game loop (FPS))
		Position vectorOfTurn; //current vector of moving 
        IGUI* (*create)(); //function pointer to create object of class in dynamic library
        void (*destroy)(IGUI*); // destroy object from dynamic library
};

#endif