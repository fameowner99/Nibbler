#include "../inc/GUI.hpp"

#include <iostream>
#include "../inc/Game.hpp"

void GUI::createWindow(int &h, int &w)
{

    SDL_Init( SDL_INIT_EVERYTHING );
    window = SDL_CreateWindow("SNAKE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_OPENGL);

    if (window == nullptr)
    {
        std::cout << "There was error initializing the window!" << std::endl
                  << SDL_GetError() << std::endl;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);


    SDL_Surface *tmp = SDL_LoadBMP("../img/greensquare.bmp");
    snakePart = SDL_CreateTextureFromSurface(renderer, tmp);
    delete tmp;

    SDL_Surface *tmp1 = SDL_LoadBMP("../img/yellowcircle.bmp");
    food = SDL_CreateTextureFromSurface(renderer, tmp1);
    delete tmp1;
}

bool GUI::checkEvent(Snake &snake, Position &vectorOfTurn)
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) {
           return (true);
        }
        else if (event.type == SDL_KEYDOWN)
        {
           switch (event.key.keysym.sym)
           {
               case SDLK_ESCAPE:
                   return (true);
               case SDLK_LEFT: //turn left
               {
                    if (snake.getVectorOfMoving().x == 0)
                    {
                        vectorOfTurn.x = -1;
                        vectorOfTurn.y = 0;
                    }
                    break ;
               }
               case SDLK_RIGHT: //turn right
               {
                   if (snake.getVectorOfMoving().x == 0)
                   {
                       vectorOfTurn.x = 1;
                       vectorOfTurn.y = 0;
                   }
                   break ;
               }
               case SDLK_UP: //turn up
               {
                   if (snake.getVectorOfMoving().y == 0)
                   {
                       vectorOfTurn.x = 0;
                       vectorOfTurn.y = -1;
                   }
                   break ;
               }
               case SDLK_DOWN: //turn down
               {
                   if (snake.getVectorOfMoving().y == 0)
                   {
                       vectorOfTurn.x = 0;
                       vectorOfTurn.y = 1;
                   }
                   break ;
               }



           }

        }


    }
    return (false);
}

void GUI::updateWindwow()
{

    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);
}

GUI::GUI()
{

    window = nullptr;
    renderer = nullptr;
}

GUI::~GUI()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void GUI::drawSnake(std::list<Object> lst) const
{
    SDL_Rect dst;

    for (auto &item : lst)
    {
       dst.x = item._currentPosition.x * CELL_WIDTH;
       dst.y = item._currentPosition.y * CELL_HEIGHT;
       dst.h = CELL_HEIGHT;
       dst.w = CELL_WIDTH;
       SDL_RenderCopy(renderer, snakePart, nullptr, &dst);
    }
}

void GUI::drawFood(std::vector<Object> &lst) const
{
    SDL_Rect dst;

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    for (auto &item : lst)
    {
        dst.x = item._currentPosition.x * CELL_WIDTH;
        dst.y = item._currentPosition.y * CELL_HEIGHT;
        dst.h = CELL_HEIGHT;
        dst.w = CELL_WIDTH;
        SDL_RenderCopy(renderer, food, nullptr, &dst);
    }
}