NAME = nibbler

CC = clang++

FLAGS = -std=c++11  #-Wall -Wextra -Werror

LDFLAGS = 

sdl_cflags := $(shell pkg-config --cflags sdl2 SDL2_mixer)
sdl_libs := $(shell pkg-config --libs sdl2 SDL2_mixer)
override CFLAGS += $(sdl_cflags)
override LIBS += $(sdl_libs)

RM = rm -f

#LIBRARY			=	-framework SDL2 -F SDL_LIBRARY -rpath SDL_LIBRARY -framework SDL2
#SDL_LIB			=	-I /usr/include/SDL2


SRC = src/Game.cpp src/GUI.cpp src/main.cpp src/Object.cpp src/Snake.cpp src/Position.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)   $(FLAGS) $(OBJ) -o $@
	@echo "nibbler done."

%.o: %.cpp
	$(CC)  $(LDFLAGS) $(FLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
