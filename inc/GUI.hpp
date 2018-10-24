#ifndef GUI_HPP

# define GUI_HPP

#include "Object.hpp"
#include <list>
#include "../SDL_LIBRARY/SDL2.framework/Headers/SDL.h"
#include "../SDL_LIBRARY/SDL2_image.framework/Headers/SDL_image.h"



  class GUI
  {
        private:
        SDL_Surface *screen;
          SDL_Window   *window;
        public:
            void createWindow(int &h, int &w);
            void drawSnake(std::list<Object> &)const;
            void drawFood(std::vector<Object> &)const;
            void updateWindwow();
            GUI();
            ~GUI();

      //maybe something else...
  };




#endif