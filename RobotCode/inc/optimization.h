
#ifndef OPTIMIZATION
#define OPTIMIZATION

#include "../inc/followpath.h"

void ShortestPath(Maze& maze);

bool validMove(int x, int y, int* movement, Maze& maze);

int* move(int* task , int* movement, Maze& maze);

#endif