#include "GUI_sdl.hpp"
#include <iostream>
#include "Game.hpp"


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


    SDL_Surface *tmp = SDL_LoadBMP("img/greensquare.bmp");
    if (!tmp)
    {
        std:: cout << "Couldn't load image." << std::endl;
        exit(9);
    }
    snakePart = SDL_CreateTextureFromSurface(renderer, tmp);

    if (snakePart == NULL)
    {
        std::cout << "Error to create texture" << std::endl;
        exit(9);
    }
    delete tmp;

    SDL_Surface *tmp1 = SDL_LoadBMP("img/yellowcircle.bmp");
    food = SDL_CreateTextureFromSurface(renderer, tmp1);
    if (!tmp1)
    {
        std:: cout << "Couldn't load image." << std::endl;
        exit(9);
    }
    if (food == NULL)
    {
        std::cout << "Error to create texture" << std::endl;
        exit(9);
    }
    delete tmp1;
}

Position GUI::checkEvent(Position vec)
{

    Position resVec;

    resVec.x = vec.x;
    resVec.y = vec.y;

    while (SDL_PollEvent(&event))
    {

        if (event.type == SDL_QUIT) {
            exit(0);
        }
       if (event.type == SDL_KEYDOWN)
        {
           switch (event.key.keysym.sym)
           {
               case SDLK_ESCAPE:
                   exit(0);

               case SDLK_LEFT: //turn left
               {
                        resVec.x = -1;
                        resVec.y = 0;
                    break ;
               }
               case SDLK_RIGHT: //turn right
               {
                        resVec.x = 1;
                        resVec.y = 0;

                   break ;
               }
               case SDLK_UP: //turn up
               {

                   resVec.x = 0;
                   resVec.y = -1;

                   break ;
               }
               case SDLK_DOWN: //turn down
               {
                   resVec.x = 0;
                   resVec.y = 1;
                   break ;
               }
           }

        }


    }
    if ((resVec.x == -1 && vec.x == 1) || (resVec.x == 1 && vec.x == -1) ||
        (resVec.y == -1 && vec.y == 1) || (resVec.y == 1 && vec.y == -1))
        return (vec);

    return (resVec);
}

void GUI::updateWindow()
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

extern "C" GUI* create_object()
{ 
  return (new GUI);
}

extern "C" void destroy_object( GUI* object )
{
  delete object;
}