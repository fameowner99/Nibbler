clang++ -Wall -Werror -Wextra -I inc -std=c++14 src/GUI_sdl.cpp -c 
clang++ -dynamiclib -undefined suppress -flat_namespace GUI_sdl.o -o GUI_sdl.dylib
rm GUI_sdl.o