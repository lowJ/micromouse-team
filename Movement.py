class Mouse():
    def __init__(self):
        self.position = [15,0]
        self.direction = 0
        self.moves = {0:(-1,0),1:(0,-1),2:(0,1),3:(1,0)}
        self.shiftL = {0:1,1:3,2:0,3:2}
        self.shiftR = {1:0,3:1,0:2,2:3}

    def startPos(self):
        pass
    
    def moveForward(self):
        pass

    def stop(self):
        pass

    def tickPosition(self):
        if self.getDistanceMoved() > 18:
            currMove = self.moves[self.direction]
            self.postion[0] += currMove[0]
            self.postion[1] += currMove[1]
            self.setMovement(self.getDistanceMoved()-18)
            return True
        return False

    def moveAlongPath(self,pathString):
        pass

    def wallForward(self):
        return False

    def wallLeft(self):
        return False

    def wallRight(self):
        return False

    def getDistanceMoved(self):
        return "distanceMoved"

    def setMovement(self,distance):
        pass

    def fixPathList(pList):
        ''' returns a string of movements from a path list '''
        moves = "" # the list of moves to be made
        shiftL = {0:1,2:0,3:2,1:3} # function to shift a direction to the left
        for i in range(len(pList)-1): # loop through the path list
            currDir = pList[i][2] # gets the current block's direction
            nextDir = pList[i+1][2] # gets the next block's direction
            if currDir == nextDir: # checks if the curr and next block's direction are the same
                moves += "f" # puts forward in the moves list
            elif shiftL[currDir] == nextDir: # checks if the next block's direction is to the left of the curr block's direction
                moves += "lf" # puts left in the moves list
            else: # if not forward and left then right
                moves += "rf" # puts right in the moves list
        return moves # returns fixed path string
