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

    def getTime(self,x,y,direction):
        ''' Returns the time at the specified location '''
        return self.maze[x][y].time[direction] # returns the time



    
