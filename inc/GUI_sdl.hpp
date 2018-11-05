#ifndef GUI_SDL_HPP

# define GUI_SDL_HPP
#include "IGUI.hpp"
#include <SDL2/SDL.h>
  class GUI: public IGUI
  {
        private:
          SDL_Renderer *renderer;
          SDL_Window   *window;
          SDL_Event     event;
          SDL_Texture* snakePart;
          SDL_Texture* food;

        public:
            void createWindow(int &h, int &w);
            void drawSnake(std::list<Object> )const;
            void drawFood(std::vector<Object> &)const;
            Position checkEvent(Position vec);
            void updateWindow();
            GUI();
            virtual ~GUI();

      //maybe something else...
  };

extern "C" GUI* create_object();

extern "C" void destroy_object( GUI* object );

#endif