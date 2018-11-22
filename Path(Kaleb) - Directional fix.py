#issues:
#   Direction matters when moving to a block


# fuck, this code is hard to understand

class Block():
    def __init__(self):
        ''' Generated a basic block of a maze '''
        self.time = [0,0,0,0] # used to determine time to get to block facing in a direction: time[0] = face up, time[1] = face left, time[2] = face right, time[3] = face down 
        self.mark = False # used to determine if the block has been visitied
        self.moves = [False,False,False,False] # walls surrounding the block: moves[0] = upper wall, moves[1] = left wall, moves[2] = right wall, moves[3] = lower wall 
        self.previous = [(-1,-1,-1),(-1,-1,-1),(-1,-1,-1),(-1,-1,-1)] # used to determine the block moved from to get here: previous[0] = (x prev, y prev, direc prev) for facing up, previous[1] = (x prev, y prev, direc prev) for facing left, previous[2] = (x prev, y prev, direc prev) for facing right, previous[3] = (x prev, y prev, direc prev) for facing down 

class Maze():
    def __init__(self):
        ''' Generates a 16 by 16 maze of blocks '''
        self.maze = [[Block() for j in range(16)] for i in range(16)] # initalizes a 16 by 16 array of Blocks
        self.start = (15,0,0) # start placed in bottom right corner
        self.goal = [(7,7),(7,8),(8,7),(8,8)] # four goal markers for the center of the maze

def ShortestPath(maze):
    ''' determines the shortest path to reach a goal from the start '''
    tasks = [maze.start] # tasks that need to be completed: task[0] = x pos, task[1] = y pos, task[2] = direction
    turn = .25 # time needed to turn 90 degrees
    movements = [(-1,0,0),(0,-1,1),(0,1,2),(1,0,3)] # different movements that can be taken: movement[0] = x movement, movement[1] = y movement, movement[2] = direction
    while tasks: # continue code untill all tasks are complete
        currTask = tasks.pop() # get the current task to work on
        for movement in movements: # loop through all possible movements
            currMove = move(currTask,movement,maze,turn) # get the result of a move
            if currMove and (task[0],task[1]) not in maze.goal: # only accept a movement that is valid and is not a goal
                tasks.append(currMove) # add in the new task to our tasks

def validMove(x,y,movement,maze):
    ''' checks if the movement is valid for the maze '''
    return 0 <= x + movement[0] <= 15 and 0 <= y + movement[1] <= 15 and not maze.maze[x][y].move[movement[2]] # returns true if pos exists on the maze and it is not walled off

def move(task,movement,maze,turn):
    ''' attempts move in movements direction '''
    if validMove(task[0],task[1],movement,maze): # checks if movement is possible
        if task[2] == movement[2] and maze.maze[task[0] + movement[0]][task[1] + movement[1]].time[movement[2]] > maze.maze[task[0]][task[1]].time[task[2]] + 1: # checks if move is forward and if the time to move to the next block is move efficent
            block = maze.maze[task[0] + movement[0]][task[1] + movement[1]] # gets the block to move to
            block.time[movement[2]] = curr.time[task[2]] + 1 # changes the time in the new block
            block.previous[movement[2]] = task # sets the block to move towards time to the current blocks position
            return (task[0] + movement[0],task[1] + movement[1],movement[2]) # returns a task for the new block
        elif task[2] != 3 - movement[2] and maze.maze[task[0] + movement[0]][task[1] + movement[1]].time[movement[2]] > maze.maze[task[0]][task[1]].time[task[2]] + 1 + turn: # checks if move is a turn and if the time to move to the next block is move efficent
            block = maze.maze[task[0] + movement[0]][task[1] + movement[1]] # gets the block to move to
            block.time[movement[2]] = curr.time[task[2]] + 1 + turn # changes the time in the new block
            block.previous[movement[2]] = task # sets the block to move towards time to the current blocks position
            return (task[0] + movement[0],task[1] + movement[1],movement[2]) # returns a task for the new block
    return None # return no task if no need to move 
        
