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
        bool isPoi(int x, int y);
        void markPoi(int x, int y);
        void unmarkPoi(int x, int y);
        float getTime(int x, int y);
        bool isMarked(int x, int y);
        int * getPrevious(int x, int y);
        bool hasWall(int x, int y, int direction);
        void setWall(int x, int y,int direction);
        void setPrevious(int x, int y, int * previous);
        void mark(int x, int y);
        void setTime(int x, int y, float time);
        bool inGoal(int* position);
        int** getGoals();
        void resetTimes();
};

#endif