#ifndef IGUI_HPP

#define IGUI_HPP

#include "Snake.hpp"
#include "Position.hpp"
#include "Object.hpp"
#include <list>
#include <vector>

//interface for handling dynamic libraries using polymorphism
class IGUI
{
	public:
		virtual void createWindow(int &h, int &w) = 0;
     	virtual void drawSnake(std::list<Object> )const = 0;
    	virtual void drawFood(std::vector<Object> &)const = 0;
     	virtual Position checkEvent(Position vec) = 0;
     	virtual void updateWindow() = 0;
};

#endif