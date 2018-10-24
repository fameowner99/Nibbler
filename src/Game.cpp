#include "../inc/Game.hpp"

Game::Game(): _height(0), _width(0)
{
    gameOver = false;

}

Game::~Game()
{

}

Game::Game(int hight, int width): _height(hight), _width(width)
{

    snake.snakeInitialize(_height / ( CELL_HEIGHT * 2), _width / (CELL_WIDTH * 2));
    gameOver = false;
    loop();
}

void Game::loop()
{
    gui.createWindow(_height, _width);


   // while (!gameOver)
   // {

    //}

}

