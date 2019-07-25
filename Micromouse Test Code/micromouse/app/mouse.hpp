
#ifndef MOUSE
#define MOUSE

#include <array>

class Mouse
{
public:
	Mouse(short x, short y, short dir);

	void moveForward(int blocks = 1);

	void turnClockwise(int degrees = 90);

	void turnCounterClockwise(int degrees = 90);	

	std::array<bool,3> getWalls();
	
	short getXpos()
	{
		return xPos;
	}

	short getYpos()
	{
		return yPos;
	}

	void setPosition(short x,short y)
	{
		xPos = x;
		yPos = y;
	}

	short getDirection()
	{
		return direction;
	}

	void setDirection(short direction)
	{
		this->direction = direction;
	}



private:
	short xPos;
	short yPos;
	short direction;
};

#endif