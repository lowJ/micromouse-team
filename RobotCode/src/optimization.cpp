
#include "optimization.h"
#include "maze.h"
#include <queue>
#include "../inc/marcros.h"

void ShortestPath(Maze& maze)
{
    maze.setPrevious(15,0,{-1,-1,-1});
    std::queue<int*> tasks;
    int currTask[3];
    int currMove[3];
    int movements[4][3] = {{-1,0,0},{0,-1,1},{0,1,2},{1,0,3}}
    while(!tasks.empty())
    {
        currTask = tasks.pop();
        for(int* movement: movements)
        {
            currMove = move(currTask,movement,maze);
            if(currMove != nullptr && !maze.inGoal(currMove))
            {
                tasks.push(currMove);
            }
        }
    }
}

bool validMove(int x, int y, int* movement, Maze& maze)
{
    return 0 <= x + movement[0] and x + movement[0] <= MAZE_WIDTH-1 && 0 <= y + movement[1] and y + movement[1] <= MAZE_HEIGHT-1 && maze.hasWall(x,y,movement[2]); 
}

int* move(int* task , int* movement, Maze& maze)
{
    if validMove(task[0],task[1],movement,maze)
    {
        int nTime = maze.getTime(task[0] + movement[0],task[1] + movement[1], movement[2]);
        int cTime = maze.getTime(task[0],task[1],task[2]);
        block curr = maze.getBlock(task[0],task[1]);
        if(nTime == 0 or nTime > cTime + 1)
        {
            block b = maze.getBlock(task[0] + movement[0],task[1] + movement[1]);
            b.time = curr.time + 1;
            b.previous = task;
            return {task[0]+movement[0],task[1]+movement[1],movement[2]};
        }
    }
    return nullptr;
}

