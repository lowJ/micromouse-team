// Header file for the maze

#ifndef MAZE
#define MAZE

struct block {
    float time;
    bool mark;
    bool * moves;
    int * previous;
    block();
};

class Maze
{
    private:
        block maze[16][16];
        int * start;   
        int (*goal)[2];

    public:
        Maze();
        float getTime(int x, int y);
        bool isMarked(int x, int y);
        int * getPrevious(int x, int y);
        bool hasWall(int x, int y, int direction);
        void setWall(int x, int y,int direction);
        void setPrevious(int x, int y, int * previous);
        void mark(int x, int y);
        void setTime(int x, int y, float time);
        bool inGoal(int* position);
};

#endif