
#include "optimization.h"
#include "maze.h"
#include <queue>
#include "../inc/marcros.h"
#include "../inc/followpath.h"

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
            optPath.pushMovement('l')
        }
        else
        {
            optPath.pushMovement('r')
        }

    }
    while(notEnd(currentPos));
    return optPath;
}

def getPathList(maze):
    ''' gets the list of blocks used to reach the goal the quickest '''
    goals = sum([[(g[0],g[1],i) for i in range(4) if maze.getTime(g[0],g[1],i) != 0] for g in maze.goal],[]) # gets all goals that have been reached
    start = min(goals,key = lambda x: maze.getTime(x[0],x[1],x[2])) # gets the goal you can reach quickest
    pathList = [start] # creates the start of the list of blocks
    nextPos = maze.maze[pathList[0][0]][pathList[0][1]].previous[pathList[0][2]] # gets previous block in the sequence
    while nextPos != (-1,-1,-1): # continues to get the next block until you have reached the start
        pathList.insert(0,nextPos) # puts the next block in the sequence
        nextPos = maze.maze[pathList[0][0]][pathList[0][1]].previous[pathList[0][2]] # gets previous block in the sequence
    return pathList # returns path list