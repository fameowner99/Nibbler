NAME = nibbler

CC = clang++

FLAGS = -std=c++11  -Wall -Wextra -Werror

RM = rm -f

LIBRARY			=	-framework SDL2
#SDL_LIB			=	-I /Library/Frameworks/SDL2.framework/Headers


SRC = src/Game.cpp src/main.cpp src/Object.cpp src/Snake.cpp src/Position.cpp

OBJ =  $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  $(LIBRARY) $(FLAGS) $(OBJ) -o $@
	@echo "nibbler done."

%.o: %.cpp
	$(CC)  -I inc/ -I ../.brew/include $(FLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
