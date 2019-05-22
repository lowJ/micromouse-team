
#ifndef INITPATH
#define INITPATH

#include "maze.h"
#include "followpath.h"
#include <set>

struct Mouse
{
    int position[2] = {15,0};
    int direction = 0;
    int moves[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
    int shiftL[4] = {1,3,0,2};
    int shiftR[4] = {2,0,3,1};
};

struct Point
{
    int x,y;
};

void Traverse(Maze maze,Mouse mouse);

void moveToNextPoint(std::set<Point> pois,Maze maze,Mouse mouse);

bool ScanBlock(Maze maze,Mouse mouse);

void getToPoi(Maze maze,Mouse mouse,std::set<Point> pois);

bool validMove(int x,int y,int* movement,Maze maze);

int* move(int* task,int* movement,Maze maze);

FollowPath getPathList(Maze maze,int* start ,int* end);


#endif