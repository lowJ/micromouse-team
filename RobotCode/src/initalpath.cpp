
#include "../inc/initalpath.hpp"
#include "../inc/marcros.h"
#include "../inc/motors.h"
#include "../inc/sensors.h"
#include "../inc/followpath.h"
#include "../inc/maze.h"
#include <queue>

void tickPosition();

void Traverse(Maze maze, Mouse mouse)
{
    int pois = 0;
    // mouse.startPos()
    bool flag = false;
    ScanBlock(maze,mouse,pois);

    while (flag or pois > 0)
    {
        if(maze.hasWall(mouse.x,mouse.y,mouse.direction))
        {
            moveToNextPoint(maze,mouse);
            --pois;
            maze.unmarkPoi(mouse.x,mouse.y);
        }
        flag = false;
        forwardTillDistance(forwardSpeed , 18);
        tickPosition();
        ScanBlock(maze,mouse,pois);
    }
}

/*
def Traverse(maze,mouse):
    pois = []
    mouse.startPos()
    flag = True

    while flag or pois:
        flag = False
        ScanBlock(maze,mouse)
        mouse.moveForward()
        while not wallForward():
            if mouse.tickPostion(False) and not ScanBlock(maze,mouse):
                break
        if mouse.getDistanceMoved() > 15:
            ScanBlock(maze,mouse)
            tickPosition(True)
        mouse.setMovement(0)    
        mouse.stop()
        moveToNextPoint(pois,maze,mouse)
*/

void moveToNextPoint(Maze maze,Mouse mouse)
{
    FollowPath path = getToPoi(maze,mouse);
    path.runList();
}

/*
def moveToNextPoint(pois,maze,mouse): #TODO
    mouse.moveAlongPath(getToPoi(maze,mouse,pois))
*/

void ScanBlock(Maze maze,Mouse mouse, int& pois)
{

    pulseIR();

    if(wallForward())
    {
        maze.setWall(mouse.x,mouse.y,mouse.direction);
    }

    if(wallLeft())
    {
        maze.setWall(mouse.x,mouse.y,mouse.shiftL[mouse.direction]);
    }
    else
    {
        maze.markPoi(mouse.x,mouse.y,mouse.shiftL[mouse.direction]);
        ++pois;        
    }

    if(wallRight())
    {
        maze.setWall(mouse.x,mouse.y,mouse.shiftR[mouse.direction]);
    }
    else
    {
        maze.markPoi(mouse.x,mouse.y,mouse.shiftR[mouse.direction]);
        ++pois;
    }
    
    
}

/*
def ScanBlock(maze,mouse):
    pos = mouse.position
    
    block = maze.maze[pos[0]][pos[1]]
    if block.mark:
        return False
    block.mark = True

    d = mouse.shiftL[mouse.direction]
    if wallLeft():
         
        block.moves[d] = True
    else:
        move = mouse.moves[d]
        poi.append((pos[0] + move[0],pos[1] + move[1]))

    d = mouse.shiftR[mouse.direction]
    if wallRight():
         
        block.moves[d] = True
    else:
        move = mouse.moves[d]
        poi.append((pos[0] + move[0],pos[1] + move[1]))

    if (pos[0],pos[1]) in poi:
        poi.remove((pos[0],pos[1]))

    return True
*/

FollowPath getToPoi(Maze maze,Mouse mouse)
{
    int start[3] = {mouse.x,mouse.y,3-mouse.direction};
    std::queue<int*> tasks;
    stack.push(start);
    int movements[4][3] = {{-1,0,0},{0,-1,1},{0,1,2},{1,0,3}};
    while(!tasks.empty())
    {
        int* currTask = tasks.pop();
        for(int* movement : movements)
        {
            int* currMove = move(currTask,movement,maze);
            if(currMove != nullptr)
            {
                if(maze.isPoi(currTask[0],currTask[1]))
                {
                    FollowPath path = getPathList(maze,start,currMove);
                    path.pushMovement('l');
                    path.pushMovement('l');
                    return path;
                }

                tasks.push(currMove);
            }
        }
    }
}

/*
def getToPoi(maze,mouse,pois):
    start = (mouse.position[0],mouse.position[1],3-mouse.direction)
    tasks = [maze.start]
    movements = [(-1,0,0),(0,-1,1),(0,1,2),(1,0,3)]
    while tasks:
        currTask = tasks.pop() # get the current task to work on
        for movement in movements: # loop through all possible movements
            currMove = move(currTask,movement,maze) # get the result of a move
            if currMove: # only accept a movement that is valid and is not a goal
                if (currTask[0],currTask[1]) in pois:
                    pois.remove((currTask[0],currTask[1]))
                    path = getPathList(maze,start,currMove)
                    fL = path[0]
                    if fL == "l":
                        return "r" + path[1:]
                    elif fL == "r":
                        return "l" + path[1:]
                    return "rr" + path
                    
                tasks.insert(0,currMove) # add in the new task to our tasks
*/

bool validMove(int x,int y,int* movement,Maze maze)
{
    return 0 <= x + movement[0] and x + movement[0] <= MAZE_WIDTH-1 and 0 <= y + movement[1] and y + movement[1] <= MAZE_HEIGHT-1 and !maze.hasWall(x,y,movement[2]);
}

/*
def validMove(x,y,movement,maze):
    ''' checks if the movement is valid for the maze '''
    return 0 <= x + movement[0] <= 15 and 0 <= y + movement[1] <= 15 and not maze.maze[x][y].moves[movement[2]] # returns true if pos exists on the maze and it is not walled off
*/

int* move(int* task,int* movement,Maze maze)
{
    if(validMove(task[0],task[1],movement,maze))
    {
        if(task[2] != 3-movement[2])
        {
            int newTask[3] = {task[0] + movement[0], task[1] + movement[1], movement[2]};
            return newTask;
        }
    }
    return nullptr;
}

/*
def move(task,movement,maze):
    ''' attempts move in movements direction '''
    if validMove(task[0],task[1],movement,maze): # checks if movement is possible
        if task[2] != 3 - movement[2]: # checks if move is a turn and if the time to move to the next block is move efficent
            block = maze.maze[task[0] + movement[0]][task[1] + movement[1]] # gets the block to move to
            block.previous[movement[2]] = task # sets the block to move towards time to the current blocks position
            return (task[0] + movement[0],task[1] + movement[1],movement[2]) # returns a task for the new block
    return None # return no task if no need to move
*/

FollowPath getPathList(Maze maze,int* start ,int* end)
{
    FollowPath path;

    return path;
}

/*
def getPathList(maze,start , end):
    pathList = [end] # creates the start of the list of blocks
    nextPos = maze.maze[pathList[0][0]][pathList[0][1]].previous[pathList[0][2]] # gets previous block in the sequence
    while nextPos != start: # continues to get the next block until you have reached the start
        pathList.insert(0,nextPos) # puts the next block in the sequence
        nextPos = maze.maze[pathList[0][0]][pathList[0][1]].previous[pathList[0][2]] # gets previous block in the sequence
    return pathList # returns path list
*/