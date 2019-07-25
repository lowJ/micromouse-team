
#include "mouse.hpp"
#include "direction.hpp"
#include "testhelper.hpp"
#include <iostream>

Mouse::Mouse(short x, short y, short dir)
: xPos{x},yPos{y},direction{dir}
{

}

void shiftDirection(short& x, short& y, short direction)
{
	switch(direction)
	{
		case 0:
			y-=1;
			return;
		case 1:
			x+=1;
			return;
		case 2:
			y+=1;
			return;
		case 3:
			x-=1;
			return;
	}
}

void Mouse::moveForward(int blocks)
{
	shiftDirection(xPos,yPos,direction);
}

void Mouse::turnClockwise(int degrees)
{
	direction = shiftClockwise(direction);
}

void Mouse::turnCounterClockwise(int degrees)
{
	direction = shiftCounterClockwise(direction);
}

std::array<bool,3> Mouse::getWalls()
{
	//std::array<bool,3> walls = std::array<bool,3>{false,false,false};
	//return walls;
	return getMouseWalls(xPos,yPos,direction);
}