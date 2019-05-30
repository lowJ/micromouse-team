
#ifndef OPTIMIZATION
#define OPTIMIZATION

#include "../inc/followpath.hpp"

void ShortestPath(Maze& maze, int startX = 15, int startY = 0, int startDir = 0);

bool validMove(int x, int y, int* movement, Maze& maze);

int* move(int* task , int* movement, Maze& maze);

FollowPath getOptimalPath(Maze& maze);

#endif