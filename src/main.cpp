#include "Game.hpp"
#include <iostream>
#include <sstream>

void print_usage()
{
    std::cout << "Usage: ./nibbler [" << MIN_HEIGHT <<
                 " < HEIGHT < " << MAX_HEIGHT <<
                 "] [" << MIN_WIDTH <<
                 " < WIDTH < " << MAX_WIDTH << "]" << std::endl;
}

bool checkLimits(const char *height, const char *width, int &h, int &w) // I think exist much better way to convert char* to int, improve if you know
{
    std::stringstream strValue;
    std::stringstream strValue1;
    unsigned int intHeight;
    unsigned int intWidth;

    strValue << height;
    strValue >> intHeight;
    if (intHeight > MAX_HEIGHT || intHeight < MIN_HEIGHT)
        return (false);
    strValue1 << width;
    strValue1 >> intWidth;
    if (intWidth > MAX_WIDTH || intWidth < MIN_WIDTH)
        return (false);
    w = intWidth;
    h = intHeight;
    return (true);
}

bool checkIfDigit(const char *str) // check that only digits in str
{
    int i = 0;

    while (str[i])
    {
        if (str[i] > '9' || str[i] < '0')
            return (false);
        ++i;
    }
    return (true);
}

bool changeSize(int &h, int &w) // change size for right number of cells
{
    int numberCellsH, numberCellsW;
    std::string answer;

    numberCellsH = h / CELL_HEIGHT;
    numberCellsW = w / CELL_WIDTH;

    if (h % CELL_HEIGHT != 0 || w % CELL_WIDTH != 0)
    {
        std::cout << "Width and height will be changed to : " << (h = numberCellsH * CELL_HEIGHT) << " "
                  << (w = numberCellsW * CELL_WIDTH) << std::endl;
        std::cout << "Y/N?" << std::endl;
        std::cin >> answer;
        if (answer == "Y" || answer == "y")
            return (true);
        return (false);
    }
    return (true);
}

int main(int argc, char **argv)
{
    int h;
    int w;


    if (argc != 3 || !checkIfDigit(argv[1]) || !checkIfDigit(argv[2]) || !checkLimits(argv[1], argv[2], h, w))
    {
        print_usage();
        return (1);
    }
    if (!changeSize(h, w))
        return (1);
    Game game(h, w);




    return (0);
}