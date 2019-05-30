
#include "optimization.hpp"
#include "maze.hpp"
#include <queue>
#include "../inc/marcros.hpp"
#include "../inc/followpath.hpp"

void ShortestPath(Maze& maze, int startX = 15, int startY = 0, int startDir = 0)
{
    maze.setPrevious(startX,startY,{-1,-1,-1});
    std::queue<int*> tasks;
    int start[3] = {startX,startY,startDir};
    tasks.push(start); 
    int currTask[3];
    int currMove[3];
    int movements[4][3] = {{-1,0,0},{0,-1,1},{0,1,2},{1,0,3}}
    while(!tasks.empty())
    {
        currTask = tasks.pop();
        int* movement;
        for(int i = 0; i < 4; ++i)
        {
            movement = movements[i];
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

int* getBestGoal(Maze& maze)
{
    float bestTime = 0;
    int** bestBlock = nullptr;
    float tempTime;
    for(int* position: maze.getGoal())
    {
        tempTime = maze.getTime(position[0],position[1]);
        if(bestBlock == nullptr or tempTime < bestTime)
        {
            bestTime = tempTime;
            bestBlock = &position;
        }
    }
    return *bestBlock;
}

bool notEnd(int* arr)
{
    return !(arr[0] == -1 && arr[1] == -1 && arr[2] == -1);
}

int getLeft(int pos)
{
    switch(pos)
    {
        case 0:
        return 1;
        case 1:
        return 3;
        case 2:
        return 0;
        case 3;
        return 2;
    }
}

int fixGoalDir(int* endPos, int* prevPos)
{
    if(endPos[0] > prevPos[0])
    {
        return 3;
    }
    else if(endPos[0] < prevPos[0])
    {
        return 0;
    }
    else if(endPos[1] < prevPos[1])
    {
        return 1;
    }
    return 2;
}

FollowPath getOptimalPath(Maze& maze)
{
    FollowPath optPath;
    int* bestGoal = getBestGoal(maze);
    int currentPos[3] = {bestGoal[0],bestGoal[1],fixGoalDir(bestGoal,maze.getPrevious(bestGoal[0],bestGoal[1])};
    int nextPos[3];
    do
    {
        nextPos = maze.getPrevious(currentPos[0],currentPos[1]);
        if(nextPos[2] == currentPos[2])
        {
            optPath.pushMovement('f');
        }
        else if(getLeft(nextPos[2]) == currentPos[2])
        {
            optPath.pushMovement('l');
            optPath.pushMovement('f');
        }
        else
        {
            optPath.pushMovement('r');
            optPath.pushMovement('f');
        }

    }
    while(notEnd(currentPos));
    return optPath;
}