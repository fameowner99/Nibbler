#ifndef GUI_HPP

# define GUI_HPP

#include "Snake.hpp"
#include "Object.hpp"
#include <list>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <vector>

//#include "../SDL_LIBRARY/SDL2.framework/Headers/SDL.h"
//#include "../SDL_LIBRARY/SDL2_image.framework/Headers/SDL_image.h"
//#include </usr/>



  class GUI
  {
        private:
          SDL_Renderer *renderer;
          SDL_Window   *window;
          SDL_Event     event;
          SDL_Texture* snakePart;
          SDL_Texture* food;

        public:
            void init();
            void createWindow(int &h, int &w);
            void drawSnake(std::list<Object> )const;
            void drawFood(std::vector<Object> &)const;
            bool checkEvent(Snake &snake, Position &vectorOfTurn);
            void updateWindwow();
            GUI();
            ~GUI();

      //maybe something else...
  };




#endif