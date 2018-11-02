#include <iostream>
using namespace std;

struct block {
	float time;
	int mark;
	bool up, down, left, right;
	block();
};

block::block() {
	this->down = this->up = this->left = this->right = false;
	this->time = 0.0;
	this->mark = 0;
}

struct point {
	int x = -1, y = -1;
};

class Maze
{
	block maze[16][16];
	point start;
	point goal;
public:
	Maze();

	block getBlock(int x, int y) {
		return maze[x][y];
	}

	void setStart(int x, int y) {
		start.x = x;
		start.y = y;
	}

	void setGoal(int x, int y) {
		goal.x = x;
		goal.y = y;
	}

	void setTime(int x, int y, float t) {
		maze[x][y].time = t;
	}

	float getTime(int x, int y) {
		return maze[x][y].time;
	}

	point getStart() {
		return start
	}

	point getGoal() {
		return goal;
	}
};

Maze::Maze() {
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++)
			this->maze[i][j] = block();
}



void ShortestPath(Maze maze) {
	int x = maze.getStart().x;
	int y = maze.getStart().x;
	float turn = 0;
	maze.setTime(x, y, 0);

	block currB = maze.getBlock(x, y);

	if (!currB.up) {
		up(x, y - 1, maze, 1,turn);
	}

	if (!currB.left) {
		left(x - 1, y, maze, 1 + turn, turn);
	}

	if (!currB.right) {
		right(x + 1, y, maze, 1 + turn, turn);
	}

	if (!currB.up) {
		down(x, y + 1, maze, 1, turn);
	}
}

void up(int x, int y,Maze maze, float time, float turn) {
	maze.setTime(x,y,time);
	if (x == maze.getGoal().x && x == maze.getGoal().y) {
		return;
	}

	block currB = maze.getBlock(x, y);
	if (!currB.up && maze.getBlock(x, y - 1).time > time + 1) {
		up(x, y - 1, maze, time + 1, turn);
	}

	if (!currB.left && maze.getBlock(x-1, y).time > time + 1 + turn) {
		left(x - 1, y, maze, time + 1 + turn, turn);
	}

	if (!currB.right && maze.getBlock(x + 1, y).time > time + 1 + turn) {
		right(x + 1, y, maze, time + 1 + turn, turn);
	}
}

void down(int x, int y, Maze maze, float time, float turn) {
	maze.setTime(x, y, time);
	if (x == maze.getGoal().x && x == maze.getGoal().y) {
		return;
	}

	block currB = maze.getBlock(x, y);
	if (!currB.up && maze.getBlock(x, y - 1).time > time + 1) {
		down(x, y + 1, maze, time + 1, turn);
	}

	if (!currB.left && maze.getBlock(x - 1, y).time > time + 1 + turn) {
		left(x - 1, y, maze, time + 1 + turn, turn);
	}

	if (!currB.right && maze.getBlock(x + 1, y).time > time + 1 + turn) {
		right(x + 1, y, maze, time + 1 + turn, turn);
	}
}

void left(int x, int y, Maze maze, float time, float turn) {
	maze.setTime(x, y, time);
	if (x == maze.getGoal().x && x == maze.getGoal().y) {
		return;
	}

	block currB = maze.getBlock(x, y);
	if (!currB.up && maze.getBlock(x, y - 1).time > time + 1) {
		left(x - 1, y, maze, time + 1, turn);
	}

	if (!currB.left && maze.getBlock(x - 1, y).time > time + 1 + turn) {
		up(x, y -1, maze, time + 1 + turn, turn);
	}

	if (!currB.right && maze.getBlock(x + 1, y).time > time + 1 + turn) {
		down(x , y+1, maze, time + 1 + turn, turn);
	}
}

void right(int x, int y, Maze maze, float time, float turn) {
	maze.setTime(x, y, time);
	if (x == maze.getGoal().x && x == maze.getGoal().y) {
		return;
	}

	block currB = maze.getBlock(x, y);
	if (!currB.up && maze.getBlock(x, y - 1).time > time + 1) {
		right(x + 1, y, maze, time + 1, turn);
	}

	if (!currB.left && maze.getBlock(x - 1, y).time > time + 1 + turn) {
		up(x, y - 1, maze, time + 1 + turn, turn);
	}

	if (!currB.right && maze.getBlock(x + 1, y).time > time + 1 + turn) {
		down(x, y + 1, maze, time + 1 + turn, turn);
	}
}
