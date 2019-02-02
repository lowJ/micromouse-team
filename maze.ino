
using namespace std;

struct block {
    float * time;
    bool mark;
    bool * moves;
    int (*previous)[3];
    block();
};

block::block() {
    this->mark = false;
    this->time = new float[4] {0,0,0,0};
    this->moves = new bool[4] {false, false, false, false};
    this->previous = new int[4][3] {{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}};
};

class Maze
{
    block maze[16][16];
    int * start;
    
    int (*goal)[2];
public:
    Maze();
    float getTime(int x, int y, int direction) {
        return maze[x][y].time[direction];
    }
};

Maze::Maze() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            this->maze[i][j] = block();
        }
    }
    this->start = new int[3] {15,0,0};
    goal = new int[4][2] {{7,7},{7,8},{8,7},{8,8}};
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
