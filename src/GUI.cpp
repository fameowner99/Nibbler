#include "../inc/GUI.hpp"
#include <iostream>


void GUI::createWindow(int &h, int &w)
{

    SDL_Init( SDL_INIT_EVERYTHING );
    window = SDL_CreateWindow("info", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_RESIZABLE);

    if (window == NULL)
    {
        std::cout << "There was error initializing the window!" << std::endl
                  << SDL_GetError() << std::endl;
    }
    screen = SDL_GetWindowSurface(window);
    while(1)
    {

    }

}
GUI::GUI()
{

    window = nullptr;
    screen = nullptr;
}
GUI::~GUI()
{

    SDL_DestroyWindow(window);
    SDL_Quit();
}
