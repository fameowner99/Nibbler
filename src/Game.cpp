#include "Game.hpp"
#include <iostream>

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
    vectorOfTurn.x = snake.getVectorOfMoving().x;
    vectorOfTurn.y = snake.getVectorOfMoving().y;
    gameOver = false;
    loop();
}

void Game::loop()
{
    gui.createWindow(_height, _width);


   while (!gameOver)
    {
        start = SDL_GetTicks();
        if (_food.empty())
            generateFood();
        vectorOfTurn = gui.checkEvent(snake.getVectorOfMoving());


        gui.drawFood(_food);
        gui.drawSnake(snake.getParts());

        if (eatFood())
        {
            snake.addPart();
           // system("canberra-gtk-play -f ../sounds/eat.wav &");
        }
        gui.updateWindwow();
        snake.setVectorOfMoving(vectorOfTurn.x,vectorOfTurn.y);
        snake.moveSnake();
        if ((gameOver = snake.checkCollision(_width / CELL_WIDTH, _height / CELL_HEIGHT ))
            || (gameOver = snake.checkSelfCollision()))
        {
            SDL_Delay(1000);
        }

        if (1000 / FPS > SDL_GetTicks() - start) // change delay to sleep
        {
            SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
        }


    }

}

void Game::generateFood()
{
    bool identical = false;
    Object obj;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dis(0,  _width / CELL_WIDTH - 1);
    std::uniform_int_distribution<> dis1(0,  _height / CELL_HEIGHT - 1);

    while (!identical)
    {
        identical = true;
        obj._currentPosition.x = dis(mt);
        obj._currentPosition.y = dis1(mt);
        for (auto item : snake.getParts())
        {
            if (obj._currentPosition == item._currentPosition)
            {
                identical = false;
                break;
            }
        }
    }
    _food.push_back(obj);
}

bool Game::eatFood()
{
    int i;

    i = 0;
    for (auto &item : _food)
    {
        if (item._currentPosition == snake.getParts().front()._currentPosition)
        {
            _food.erase(_food.begin() + i);
            return (true);
        }
        ++i;
    }
    return (false);
}

