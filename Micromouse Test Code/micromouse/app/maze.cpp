
#include "maze.hpp"
#include <iostream>
#include "mouse.hpp"
#include "direction.hpp"
#include <stack>
#include <array>
#include <vector>
#include <algorithm>

Maze::Maze()
{
	for(std::array<bool,MazeSize>& arr: vertical)
	{
		arr.fill(false);
	}

	for(std::array<bool,MazeSize+1>& arr: horizontal)
	{
		arr.fill(false);
		arr[0] = true;
		arr[MazeSize] = true;
	}

	int temp = (MazeSize - 1) / 2;

	for(unsigned int j = 0; j < MazeSize; ++j)
	{
		for(unsigned int i = 0; i < MazeSize; ++i)
		{
			board[i][j] = abs(int(temp - i + ((temp < i) ? 1 : 0))) + abs(int(temp - j + ((temp < j) ? 1 : 0)));
		}
	}

	vertical[0].fill(true);
	vertical[MazeSize].fill(true);
}

void Maze::printMaze(short x, short y)
{
	for(unsigned int i = 0; i < MazeSize * 2 + 1; ++i)
	{
		if(i % 2  == 0)
		{
			for(unsigned int j = 0; j < MazeSize * 2 + 1; ++j)
			{
				     if(j % 2 == 1)
				     {
				     	std::cout << ((vertical[(i+1)/2][(j-1)/2]) ? "██" : "  ");
				     }
				     else
				     {
				     	std::cout << "█";
				     }
			}
		}
		else
		{
			for(unsigned int j = 0; j < MazeSize * 2 + 1; ++j)
			{
				if(j % 2 == 0)
				{
					std::cout << ((horizontal[(i-1)/2][(j+1)/2]) ? "█" : " ");
				}
				else
				{
					if(board[i/2][j/2] < 10)
					{
						std::cout << ((x == j/2 && y == i/2)? "\033[1;31m" : ((board[i/2][j/2] == 0) ? "\033[1;32m" : "\033[1;36m")) << "0" << board[i/2][j/2] << "\033[0m";
					}
					else
					{
						std::cout << ((x == j/2 && y == i/2)? "\033[1;31m" : ((board[i/2][j/2] == 0) ? "\033[1;32m" : "\033[1;36m")) << board[i/2][j/2] << "\033[0m";
					}
				}
			}
		}
		std::cout << std::endl;
	}
}

std::array<bool*,4> Maze::getBlockWalls(short x, short y)
{
	std::array<bool*,4> walls{&vertical[y][x],&horizontal[y][x+1],&vertical[y+1][x],&horizontal[y][x]};
	return walls; 
	//Up, Right, Down, Left
}

void Maze::exploreMaze(Mouse& mouse)
{
	std::array<bool*,4> block = this->getBlockWalls(mouse.getXpos(),mouse.getYpos());
	std::array<bool,3> walls = mouse.getWalls();
	*block[mouse.getDirection()] = walls[1];
	*block[shiftClockwise(mouse.getDirection())] = walls[2];
	*block[shiftCounterClockwise(mouse.getDirection())] = walls[0];

	this->fixMaze(mouse.getXpos(),mouse.getYpos());
}


std::vector<DirPoint> getSurroundingPoints(Point p, std::array<bool*,4>& walls)
{
	std::vector<DirPoint> blocks;
	if(p.y > 0 && !(*walls[0]))
	{
		blocks.push_back({Point{p.x,(short)(p.y-1)},0});
	}
	if(p.x < MazeSize-1 && !(*walls[1]))
	{
		blocks.push_back({Point{(short)(p.x+1),p.y},1});
	}
	if(p.y < MazeSize-1 && !(*walls[2]))
	{
		blocks.push_back({Point{p.x,(short)(p.y+1)},2});
	}
	if(p.x > 0 && !(*walls[3]))
	{
		blocks.push_back({Point{(short)(p.x-1),p.y},3});
	}
	return blocks;
}

DirPoint getMinPoint(std::vector<DirPoint>& surrPoints, Mouse& mouse, std::array<std::array<int,MazeSize>,MazeSize>& board)
{
	return *std::min_element(std::begin(surrPoints),std::end(surrPoints),
			[&](const DirPoint& a, const DirPoint& b)
			{
				return board[a.position.y][a.position.x] - ((a.direction == mouse.getDirection()) ? .5 : 0) < board[b.position.y][b.position.x] - ((b.direction == mouse.getDirection()) ? .5 : 0);
			}
			);
}

void Maze::moveMouse(Mouse& mouse)
{
	std::array<bool*,4> walls = this->getBlockWalls(mouse.getXpos(),mouse.getYpos());
	Point p{mouse.getXpos(),mouse.getYpos()};
	std::vector<DirPoint> surrPoints = getSurroundingPoints(p,walls);


	DirPoint minPoint = getMinPoint(surrPoints,mouse, this->board);

	if(minPoint.direction == mouse.getDirection())
	{
		mouse.moveForward();
	}
	else if(minPoint.direction == shiftClockwise(mouse.getDirection()))
	{
		mouse.turnClockwise();
		mouse.moveForward();
	}
	else if(minPoint.direction == shiftCounterClockwise(mouse.getDirection()))
	{
		mouse.turnCounterClockwise();
		mouse.moveForward();
	}
	else
	{
		mouse.turnClockwise();
		mouse.turnClockwise();
		mouse.moveForward();
	}
}

void Maze::fixMaze(short x, short y)
{
	if(this->inGoal(x,y))
	{
		return;
	}

	Point start{x,y};
	std::stack<Point> fixStack;
	fixStack.push(start);  
	std::array<bool*,4> currBlock;  
	Point currPoint;
	std::vector<DirPoint> surrPoints;
	int newDist;
	Point minPoint;

	while(!fixStack.empty())
	{
		currPoint = fixStack.top();
		fixStack.pop();
		currBlock = this->getBlockWalls(currPoint.x,currPoint.y);
		surrPoints = getSurroundingPoints(currPoint,currBlock);
		minPoint = std::min_element(std::begin(surrPoints),std::end(surrPoints),
			[&](const DirPoint& a, const DirPoint& b){return board[a.position.y][a.position.x] < board[b.position.y][b.position.x];}
			)->position;
		newDist = board[minPoint.y][minPoint.x];
		if(newDist + 1 != board[currPoint.y][currPoint.x])
		{
			board[currPoint.y][currPoint.x] = newDist + 1;
			for(DirPoint dp : surrPoints)
			{
				if(!this->inGoal(dp.position.x,dp.position.y))
				{
					fixStack.push(dp.position);
				}
			}
		}
	}
}

void Maze::setWalls(short x, short y, bool up, bool right, bool down, bool left)
{
	std::array<bool*,4> block = this->getBlockWalls(x,y);
	*block[0] = up;
	*block[1] = right;
	*block[2] = down;
	*block[3] = left;
}

bool Maze::inGoal(short x, short y)
{
	return (x == MazeSize/2 || x == MazeSize/2 - 1) && (y == MazeSize/2 || y == MazeSize/2 - 1);
}