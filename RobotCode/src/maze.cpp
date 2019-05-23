// defines the maze and functions to easily acess data within it

#include "../inc/maze.h"
#include "../inc/marcros.h"

// Constructs a new block with some initial values
block::block() 
{
    this->mark = false;
    this->time = 0;
    this->moves = new bool[4] {false, false, false, false};
    this->previous = new int[3] {-1,-1,-1};
    this->isPoi = false;
};

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

// Constructs a new maze with empty blocks
Maze::Maze() 
{
    for (int i = 0; i < MAZE_WIDTH; i++) 
    {
        for (int j = 0; j < MAZE_HEIGHT; j++) 
        {
            this->maze[i][j] = block();
        }
    }
    this->start = new int[3] {MAZE_WIDTH-1,0,0};
    goal = new int[4][2] {{7,7},{7,8},{8,7},{8,8}};
}

// Returns all the goal positions
int** Maze::getGoals()
{
    return goal;
}

// Finds if <position> corresponds to a goal position
bool Maze::inGoal(int* position)
{
    return position[0] >= MAZE_WIDTH/2-1 && position[0] <= MAZE_WIDTH/2 && position[1] >= MAZE_HEIGHT/2-1 && position[1] <= MAZE_HEIGHT/2;
}

void Maze::resetTimes()
{
    for(int x = 0; x < MAZE_WIDTH; ++x)
    {
        for(int y = 0; y < MAZE_HEIGHT; ++y)
        {
            this->setTime(x,y,0);
        }
    }
}