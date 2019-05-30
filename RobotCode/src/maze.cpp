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