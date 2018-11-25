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
