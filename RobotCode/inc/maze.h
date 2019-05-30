// Header file for the maze

#ifndef MAZE
#define MAZE

#include "marcros.h"

struct block {
    float time;
    bool mark;
    bool * moves;
    int * previous;
    bool isPoi;
    block();
};

class Maze
{
    private:
        block maze[MAZE_WIDTH][MAZE_HEIGHT];
        int * start;   
        int goal[4][2];

    public:
        Maze();

        bool isPoi(int x, int y)
        {
            return maze[x][y].isPoi;
        }

        void markPoi(int x, int y)
        {
            maze[x][y].isPoi = true;
        }

        void unmarkPoi(int x, int y)
        {
            maze[x][y].isPoi = false;
        }

        // Returns the time of the block at (<x>,<y>)
        float Maze::getTime(int x, int y) 
        {
            return maze[x][y].time;
        }

        // Sets the time of the block at (<x>,<y>) to time <time>
        void Maze::setTime(int x, int y, float time) 
        {
            maze[x][y].time = time;
        }

        // Returns if the block at (<x>,<y>) has been visited
        bool Maze::isMarked(int x, int y)
        {
            return maze[x][y].mark;
        }

        // Marks the block at (<x>,<y>) as visited
        void Maze::mark(int x, int y)
        {
            maze[x][y].mark = true;
        }

        // Returns the x, y, and direction of the block previous to the block at (<x>,<y>) in the path to the center of the maze
        int * Maze::getPrevious(int x, int y)
        {
            return maze[x][y].previous;
        }

        // Sets the x, y, and direction of the block previous to the block at (<x>,<y>) in the path to the center of the maze
        void Maze::setPrevious(int x, int y, int * previous)
        {
            maze[x][y].previous = previous;
        }

        // Returns if the block at (<x>,<y>) if there is a wall in direction <direction>
        bool Maze::hasWall(int x, int y,int direction)
        {
            return maze[x][y].moves[direction];
        }

        // Marks the wall at the block at (<x>,<y>) in direction <direction>
        void Maze::setWall(int x, int y,int direction)
        {
            maze[x][y].moves[direction] = true;
        }

        bool inGoal(int* position);
        int** getGoals();
        void resetTimes();
};

#endif