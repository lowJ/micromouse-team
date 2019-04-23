// defines the maze and functions to easily acess data within it

#include "../inc/maze.h"

block::block() 
{
    this->mark = false;
    this->time = 0;
    this->moves = new bool[4] {false, false, false, false};
    this->previous = new int[3] {-1,-1,-1};
};

float Maze::getTime(int x, int y) 
{
    return maze[x][y].time;
}

bool Maze::isMarked(int x, int y)
{
    return maze[x][y].mark;
}

int * Maze::getPrevious(int x, int y)
{
    return maze[x][y].previous;
}

bool Maze::hasWall(int x, int y,int direction)
{
    return maze[x][y].moves[direction];
}

Maze::Maze() 
{
    for (int i = 0; i < 16; i++) 
    {
        for (int j = 0; j < 16; j++) 
        {
            this->maze[i][j] = block();
        }
    }
    this->start = new int[3] {15,0,0};
    goal = new int[4][2] {{7,7},{7,8},{8,7},{8,8}};
}